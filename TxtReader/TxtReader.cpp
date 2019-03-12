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

#include "TxtReader.h"
/**
 * @brief ctor por defecto
 */
TxtReader::TxtReader() = default;
/**
 * @brief recuperacion de cadenas desde un archivo
 * @param path ruta del archivo a leer
 * @return iterable con los datos recuperados
 */
std::vector<std::string>* TxtReader::operator()(std::string path)
{
    auto iterable = new std::vector<std::string>;
    try
    {
        file.open(path);

        if(file.is_open( ))
        {
            while(getline(file,line))
                iterable->push_back(line);
        }
        else
        {
            std::string msg = "Excepción al abrir/leer/cerrar el archivo!!";
            throw msg;
        }
    }
    catch(std::string& e)
    {
        std::cout << e << std::endl;
    }
    return iterable;
}
