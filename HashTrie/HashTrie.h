/**
 * @author    Giovanny Alfonso Chávez Ceniceros (310831)
 *            Julieta Navarro Rivera            (311012)
 *            Sebastián De la Riva Rivera       (301608)
 *            Christopher Ochoa Gutierrez       (310853)
 *
 * @file      HashTrie.h
 * @date      Nov 25, 2018
 * @version   1.0
 * @brief     Clase para la generación de tramas de envío y recepción de datos
 *            con sus respectivos valores hash calculados, a traves de la im_
 *            plementación de un Trie
 */

#ifndef HASHTRIE_HASHTRIE_H
#define HASHTRIE_HASHTRIE_H

#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include "Trie/Trie.h"

class HashTrie {
    //  Estructura Trie para almecenar las tramas correctas
    Trie trie;
    //  Cálculo del nivel de similaridad entre 2 arreglos
    double similar(const char* A, size_t sa, const char* B, size_t sb);

public:
    //  Generación de HashTries para tramas de control
    void hashing(std::function<void(char*, const size_t)> F
            ,char* D
            ,size_t s
            ,size_t c = 1
            ,char m = '$');
    //  Algoritmo de verificación de tramas de control
    void verify(char* D
            ,size_t s
            ,size_t c
            ,std::function<bool(char*, size_t)> F
            ,std::function<void(char*, size_t)> G
            ,std::function<void(char*, size_t)> H);
    //  Algoritmo de corrección de tramas de control
    void correction(char* D, size_t s, size_t c, double p
            ,std::function<bool(char*, size_t)> F
            ,std::function<void(char*, size_t, double)> G
            ,std::function<void(char*, size_t, double)> H);

};

#endif //HASHTRIE_HASHTRIE_H
