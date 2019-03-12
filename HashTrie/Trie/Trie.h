/**
 * @author    Giovanny Alfonso Chávez Ceniceros (310831)
 *            Julieta Navarro Rivera            (311012)
 *            Sebastián De la Riva Rivera       (301608)
 *            Christopher Ochoa Gutierrez       (310853)
 *
 * @file      Trie.h
 * @date      Nov 25, 2018
 * @version   1.0
 * @brief     Estructura de datos Trie para el manejo de cadenas de caracteres
 */

#ifndef HASHTRIE_TRIE_H
#define HASHTRIE_TRIE_H

#include <string>
#include <vector>
#include "Node.h"

class Trie {
    Node* root; // nodo raiz

    int lastNode(Node* node); // verificar si el nodo esta marcado
    int isItFreeNode(Node* node); // verificar si el nodo tiene hijos definidos
    bool _erase(Node* node, std::string word, unsigned long l); // borrar una palabra recursivamente
    // generar el iterable con los elementos del trie de manera recursiva
    void traversial(Node* node, std::string word, std::vector<std::string>& iterable);

public:
    Trie( ); // ctor por defecto
    bool find(std::string word); // buscar una palabra en el Trie
    void insert(std::string word); // insertar una palabra en el Trie
    void erase(std::string word); // borrar una palabra del Trie
    std::vector<std::string>* iterable(); // proporcionar una coleccion iterable con los elementos del trie

};

#endif //HASHTRIE_TRIE_H
