/**
 * @author    Giovanny Alfonso Chávez Ceniceros (310831)
 *            Julieta Navarro Rivera            (311012)
 *            Sebastián De la Riva Rivera       (301608)
 *            Christopher Ochoa Gutierrez       (310853)
 *
 * @file      HashCollection.h
 * @date      Nov 25, 2018
 * @version   1.0
 * @brief     Colección de algoritmos generadores de diversos valores hash
 *            a partir de un arreglo proporcionado
 */

#ifndef HASHTRIE_HASHCOLLECTION_H
#define HASHTRIE_HASHCOLLECTION_H

class HashCollection {
    static HashCollection* instance;
    HashCollection() = default;

public:
    /**
     * @brief generar una copia de la instancia de HashCollection
     * @return
     */
    static HashCollection* create()
    {
        if(instance == nullptr)
            instance = new HashCollection;
        return instance;
    }
    /**
     * @brief   Variante recursiva del checksum
     * @param   T* r, arreglo al que hay que determinar un valor hash
     * @param   int n, la longitud del arreglo
     * @return 	T , valor hash calculado mediante la suma de los valores ASCII
     */
    template<typename T> T checksum(T* r, unsigned long n)
    {
        return n == 0 ? r[n] : checksum(r, n - 1) + r[n];
    }
    /**
     * @brief   Variante recursiva del checksum staircase
     * @param   T* r, arreglo al que hay que determinar un valor hash
     * @param   int n, la longitud del arreglo
     * @return 	T , valor hash calculado mediante la suma de los valores ASCII multiplicado por su posicion
     */
    template<typename T> T staircase(T* r, unsigned long n)
    {
        return n == 0 ? r[n] : staircase(r, n - 1) + r[n]*(n + 1);
    }
    /**
     * @brief   Variante recursiva del algoritmo djb2
     * @param   T* r, arreglo al que hay que determinar un valor hash
     * @param   int n, la longitud del arreglo
     * @param   unsigned long hash, valor requerido para el funciona_
     *          miento del algoritmo djb2
     * @return 	T , valor hash calculado
     */
    template<typename T> unsigned long djb2(T* r, unsigned long n, unsigned long hash = 5381)
    {
        return n == 0 ? r[n] : djb2(r, n - 1, hash << 5) + r[n] + hash;
    }
};

HashCollection* HashCollection::instance = nullptr;

#endif //HASHTRIE_HASHCOLLECTION_H
