/**
 * @author    Giovanny Alfonso Chávez Ceniceros (310831)
 *            Julieta Navarro Rivera            (311012)
 *            Sebastián De la Riva Rivera       (301608)
 *            Christopher Ochoa Gutierrez       (310853)
 *
 * @file      Trie.cpp
 * @date      Nov 25, 2018
 * @version   1.0
 * @brief     Estructura de datos Trie para el manejo de cadenas de caracteres
 */

#include "Trie.h"

/**
 * @brief ctor por defecto
 */
Trie::Trie( )
{
    root = new Node;
}
/**
 * @brief verificar si el nodo esta marcado
 * @param node nodo a evaluar
 * @return si o no
 */
int Trie::lastNode( Node* node )
{
    return node->isWordEnd( );
}
/**
 * @brief verificar si el nodo tiene hijos definidos
 * @param node nodo a evaluar
 * @return si o no
 */
int Trie::isItFreeNode( Node* node )
{
    for(int i = 0; i < 256; ++i)
    {
        if(node->getChildren(i))
            return 0;
    }
//  el nodo es unico
    return 1;
}
/**
 * @brief borrar una palabra recursivamente
 * @param node nodo base
 * @param word palabra a eliminar
 * @param l control de la recursion
 * @return
 */
bool Trie::_erase(Node* node, std::string word, unsigned long l)
{
    if(node)
    {
        // se busca el nodo de la ultima letra de la palabra a borrar
        // mediante recursion
        if(l == word.length( )) //¿se ha recorrido toda la palabra?
        {
            // se ha encontrado el nodo de la ultima letra de la palabra
            if(node->isWordEnd())
            {
                // se desmarca el nodo
                node->setWordEnd(false);
                // si el nodo es unico, es decir, no tiene otra palabra
                // como prefijo, ni es en sí prefijo de otra palabra, se
                // determina que será borrado por lo que se regresa true
                return isItFreeNode(node) != 0;
                // el nodo resultó prefijo de otra palabra, por lo que
                // solo queda desmarcado
            }
        }
        else
        {
            int index = word[l];
            // el nodo de la recursion anterior fue marcado para ser bo_
            // rrado, asi que se elimina
            if(_erase((Node*) node->getChildren(index), word, l + 1))
            {
                node->setChildren(index, nullptr);
                // regresamos recursivamente hacia la raiz, observando
                // si los nodos subsecuentes son elegibles para ser bo_
                // rrados
                return (!lastNode(node) && isItFreeNode(node));
            }
            // Como el nodo no fue borrado, regresamos recursivamente
            // hacia la raiz sin más
        }
    }
    return false;
}
/**
 * @brief generar el iterable con los elementos del trie de manera recursiva
 * @param node nodo base
 * @param word prefijo a buscar dentro del trie
 * @param iterable coleccion de todos los elementos del trie
 */
void Trie::traversial(Node* node, std::string word, std::vector<std::string>& iterable)
{
    // si el nodo no existe pasamos de largo
    if(node)
    {
        // hemos encontrado una palabra en el trie?
        if(node->isWordEnd())
            iterable.push_back(word); // la agregamos a la coleccion
        // buscamos en el siguiente hijo del actual nodo
        for(int idx = 0; idx < 256; ++idx)
            traversial((Node*) node->getChildren(idx), word + (char)idx, iterable);
    }
}
/**
 * @brief buscar una palabra en el Trie
 * @param word palabra a buscar
 * @return encontrada o no
 */
bool Trie::find(std::string word)
{
    // empezamos en root
    Node* tmp = root;
    // recorremos la palabra nodo por nodo para ver si estos existen,
    // en caso contrario regresamos false
    for(int index : word)
    {
        if(!tmp->getChildren(index))
            return false;

        tmp = (Node*) tmp->getChildren(index); // siguente nodo
    }
    // regresamos si el nodo coincide con la palabra esta marcado como
    // tal y si el nodo existe
    return (tmp != nullptr && tmp->isWordEnd( ));
}
/**
 * @brief insertar una palabra en el Trie
 * @param word palabra a insertar
 */
void Trie::insert(std::string word)
{
    // empezamos en root
    Node* tmp = root;
    // si la palabra no está presente, insertala en el trie nodo
    // por nodo
    for(int index : word)
    {
        if(!tmp->getChildren(index))
            tmp->setChildren(index, new Node);

        tmp = (Node*) tmp->getChildren(index); // siguente nodo
    }
    // si la palabra es el prefijo de otra, solo marca el nodo como
    // ultimo
    tmp->setWordEnd(true);
}
/**
 * @brief borrar una palabra del Trie
 * @param word palabra a borrar
 */
void Trie::erase(std::string word)
{
    // empezamos el recorrido para borrar a partir de la raiz
    if((int)word.length( ) > 0) _erase(root, word, 0);
}
/**
 *
 * @return
 */
std::vector<std::string>* Trie::iterable()
{
    auto iterable = new std::vector<std::string>;
    traversial(root, "", *iterable);
    return iterable;
}
