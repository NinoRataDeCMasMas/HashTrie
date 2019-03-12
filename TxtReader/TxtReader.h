/**
 * @author    Giovanny Alfonso Chávez Ceniceros (310831)
 *            Julieta Navarro Rivera            (311012)
 *            Sebastián De la Riva Rivera       (301608)
 *            Christopher Ochoa Gutierrez       (310853)
 *
 * @file      TxtReader.h
 * @date      Nov 25, 2018
 * @version   1.0
 * @brief     Clase para obtencion de cadenas de caracteres a traves de un archivo de texto
 */
#ifndef HASHTRIE_TXTREADER_H
#define HASHTRIE_TXTREADER_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class TxtReader {
    std::string line;
    std::ifstream file;

public:
    TxtReader(); // ctor por defecto
    // recuperacion de cadenas desde un archivo
    std::vector<std::string>* operator()(std::string path);
};

#endif //HASHTRIE_TXTREADER_H
