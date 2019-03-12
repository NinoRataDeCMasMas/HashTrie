/**
 * @author    Giovanny Alfonso Chávez Ceniceros (310831)
 *            Julieta Navarro Rivera            (311012)
 *            Sebastián De la Riva Rivera       (301608)
 *            Christopher Ochoa Gutierrez       (310853)
 *
 * @file      Node.cpp
 * @date      Nov 25, 2018
 * @version   1.0
 * @brief     Nodo inplementado en la estructura Trie
 */

#include "Node.h"
/**
 * @brief ctor por defecto
 */
Node::Node()
{
    wordEnd = false;
    for(auto& i : children)
    {
        // Use 0 para enteros, 0.0 para reales, nullptr para punteros y
        // '\ 0' para caracteres.
        i = nullptr;
    }
}

bool Node::isWordEnd() const
{
    return wordEnd;
}

void Node::setWordEnd(bool wordEnd)
{
    Node::wordEnd = wordEnd;
}

void Node::setChildren(int index, Node* node)
{
    children[index] = node;
}
/**
 *@brief Obtener nodo segun el indice proporcionado
 *
 * @param index indice correspondiente a la letra buscada en el alfabeto
 * @return nodo correspondiente a la letra del alfabeto segun el indice
 */
Node* const* Node::getChildren(int index) const
{
    // reinterpret_cast es un tipo de operador de casting utilizado en C++.

    // Se utiliza para convertir un puntero de otro puntero de cualquier tipo,
    // sin importar si la clase está relacionada entre  sí o no. No comprueba
    // si el tipo de puntero y los datos apuntados por el puntero son iguales
    // o no.
    return reinterpret_cast<Node* const*>(children[index]);
}
