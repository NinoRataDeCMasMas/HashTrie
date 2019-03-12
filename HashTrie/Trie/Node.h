/**
 * @author    Giovanny Alfonso Chávez Ceniceros (310831)
 *            Julieta Navarro Rivera            (311012)
 *            Sebastián De la Riva Rivera       (301608)
 *            Christopher Ochoa Gutierrez       (310853)
 *
 * @file      Node.h
 * @date      Nov 25, 2018
 * @version   1.0
 * @brief     Nodo inplementado en la estructura Trie
 */

#ifndef HASHTRIE_NODE_H
#define HASHTRIE_NODE_H

class Node {
    // arreglo de hijos que representan el alfabeto de letras que conforman el
    // trie
    Node* children[256];
    // wordEnd es verdadero si el nodo representa si es el fin
    // de una palabra
    bool wordEnd;

public:
    Node(); // ctor por defecto
    // getters
    Node* const* getChildren(int index) const; // Obtener nodo segun el indice proporcionado
    bool isWordEnd() const;
    // setters
    void setWordEnd(bool wordEnd);
    void  setChildren(int index, Node* node);
};

#endif //HASHTRIE_NODE_H
