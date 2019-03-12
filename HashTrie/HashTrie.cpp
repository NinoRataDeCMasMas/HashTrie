/**
 * @author    Giovanny Alfonso Chávez Ceniceros (310831)
 *            Julieta Navarro Rivera            (311012)
 *            Sebastián De la Riva Rivera       (301608)
 *            Christopher Ochoa Gutierrez       (310853)
 *
 * @file      HashTrie.cpp
 * @date      Nov 25, 2018
 * @version   1.0
 * @brief     Clase para la generación de tramas de envío y recepción de datos
 *            con sus respectivos valores hash calculados, a traves de la im_
 *            plementación de un Trie
 */

#include "HashTrie.h"

/**
 * @brief Cálculo del nivel de similaridad entre 2 arreglos
 *
 * @param A  Arreglo a comparar el nivel se similaridad
 * @param sa Tamaño de los arreglos a comparar
 * @param B  Arreglo a comparar el nivel se similaridad
 * @param sb Tamaño de los arreglos a comparar
 * @return   Nivel de similaridad calculado donde 0 ≤ sim ≤ 1
 */
double HashTrie::similar(const char* A, size_t sa, const char* B, size_t sb)
{
    int p = 0;
    if(sa != sb)
        return -1.0;
    else
    {
        for(int i = 0; i < sa; ++i)
            p = p + (A[i] == B[i] ? 1 : 0);
    }
    return p/(double)sa;
}
/**
 * @brief Generación de HashTries para tramas de control
 *
 * @param F Función que pone a disposición del usuario el HashTrie definido para la transmisión
 * @param D Arreglo de datos para generar el hash-buffer
 * @param s Longitud inicial del arreglo
 * @param c Número de celdas a disminuir
 * @param m Caracter para visualizar las celdas añadidas
 */
void HashTrie::hashing(std::function<void(char*, const size_t)> F
        ,char* D, size_t s, size_t c, char m)
{
    size_t n = s + c;

    char B[n];
    memset(B, m, n);

    for(int i = 0; i < n; ++i)
    {
        B[i + c] = D[i];
    }

    F(B, n);
}
/**
 * @brief Algoritmo de verificación de tramas de control
 *
 * @param D Arreglo de datos para generar el hash-buffer
 * @param s Longitud inicial del arreglo
 * @param c Número de celdas a disminuir
 * @param F Función que evaulará la calidad de la transmisión
 * @param G Función que se ejecuta al validar los datos recibidos
 * @param H Función que se ejecuta al no poder corregir los datos
 */
void HashTrie::verify(char* D, size_t s, size_t c
        ,std::function<bool(char*, size_t)> F
        ,std::function<void(char*, size_t)> G
        ,std::function<void(char*, size_t)> H)
{
    size_t n = s - c + 1;
    char B[n];

    for(int i = 0; i < n; ++i)
    {
        B[i] = D[i + c];
    }

    (F(B,n) ? G : H)(B,n);
}
/**
 * @brief Algoritmo de corrección de tramas de control
 *
 * @param D Arreglo de datos para generar el HashTrie
 * @param s Longitud inicial del arreglo
 * @param c Número de celdas a disminuir
 * @param p Porcentaje de similaridad mínimo admisible
 * @param F Función que evaulará la calidad de la transmisión
 * @param G Función que se ejecuta al validar los datos recibidos
 * @param H Función que se ejecuta al no poder corregir los datos
 */
void HashTrie::correction(char* D, size_t s, size_t c, double p
        ,std::function<bool(char*, size_t)> F
        ,std::function<void(char*, size_t, double)> G
        ,std::function<void(char*, size_t, double)> H)
{
    size_t n = s - c + 1;
    char* hB = nullptr;
    size_t z = 0;
    char B[n];

    for(int i = 0; i < n; ++i)
    {
        B[i] = D[i + c];
    }

    if(F(B, n))
    {
        std::string tmp(B);
        if(trie.find(tmp) != 1) trie.insert(tmp);
        G(B, n, 1.00);
    }
    else
    {
        auto max = 0.0;
        std::string idx;

        for(const auto& it: *trie.iterable())
        {
            z = it.length() + 1;
            auto tmp = similar(B, n, it.c_str(), z);

            if(tmp > max)
            {
                max = tmp;
                idx = it;
            }
        }

        if(max > p)
        {
            hB = new char[z];
            memcpy(hB, idx.c_str( ), z);
            G(hB, z, max);
        }
        else
            H(B, n, max);
    }
}
