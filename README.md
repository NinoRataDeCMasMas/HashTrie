# Estructura de datos HashTrie
En el presente código se plantea una solución algorítmica a la pérdida de información en los procesos de transmisión y recepción entre sistemas embebidos basados en microprocesadores, conocida en la literatura como  detección y corrección de errores, implentando en lenguaje C++ diversos tópicos computacionales tales como la programación orientada a objetos y las expresiones lambda ocupadas en la programación funcional.

La aplicación implementa el concepto matemático de funciones hash como técnicas de validación y corrección, complementadas con el uso de estructuras de datos tales como Tries.

## Uso
### Instalación
Descarga el contenido de este repositorio a el directorio donde está alojado el programa principal ```main.cpp``` en tu computadora. Agrega a la cabecera de tu programa principal los headers

```c++

#include "HashTrie/HashTrie.h"
#include "TxtReader/TxtReader.h"
#include "HashCollection/HashCollection.h"

using namespace std;
 
int main( void )
{ 
	// Aquí va tu código...
```
y ahora ejecuta en terminal, todo en el mismo directorio, los siguientes comandos:

```sh

mkdir build
cd build
cmake ..
make
```
Dentro del directorio ```build``` encontrarás el executable ```HashTrie```.

### Código de ejemplo

Se instancian los objetos correspondientes ```TxtReader``` y ```HashTrie```. La clase ```HashCollection``` es un singleton por lo que habrá que llamar al método ```create```.

```c++

    TxtReader reader;
    auto* HT = new HashTrie;
    auto* Hc = HashCollection::create();
<<<<<<< HEAD
=======

>>>>>>> 0b7030a5db0f1e7ac4992ba3d79d37c3e4c21dec
```

También se declara una variable ```path``` con la ruta del archivo que contendrá la simulación de datos corruptos durante una transmisión. La lista de datos corruptos usada en este ejemplo es la siguiente:

```txt
<<<<<<< HEAD
=======

>>>>>>> 0b7030a5db0f1e7ac4992ba3d79d37c3e4c21dec
_BTN1
uBXY1
%BTN1
%@TN1
%@TN&
6BTXY
 BXY1
5XTNY
wXYN1
3XTY1
%@^&1
876N)
asqwq
%@TN&
%@^&1
457py
<<<<<<< HEAD
=======

>>>>>>> 0b7030a5db0f1e7ac4992ba3d79d37c3e4c21dec
```
Enseguida simulamos la trama transmitida hacia nuestro dispositivo, en este caso 

```c++

    string key = "BTN1";
```
y generamos el buffer que recibirá la trama transmitida

```c++

    char* buffer = new char[key.length() + 2]; // [valor hash calculado| trama transmitida| '0']
```

Para cada dato transmitido, el ```HashTrie``` evaulará la calidad de la transmisión, es decir: verificará que el valor hash de la trama esperada y la trama recibida sean la misma. De no ser así, el algoritmo intentará reconstruir la trama buscando coincidencias con datos previamente validados. En este ejemplo se pide una validación del 50%.

```c++

    for(const auto& it: *reader(path))
    {
        // se muestra la trama real transmitida hacia nuestro dispositivo, la cual puede ser afectada o corrupta
        // por diversos factores como mala conexion, interferencia electromagnetica, etc.
        cout << it << " :";

        // se recupera la trama transmitida en el buffer
        memcpy(buffer, it.c_str(), key.length() + 2);

        // se emplea el hashCollection para generar el valor hash de la trama
        buffer[0] = Hc->checksum(key.c_str(), key.length() - 1);

        HT->correction(buffer, key.length() + 1, 1, 0.50
                // función que evaulará la calidad de la transmisión, es decir:
                // verificar que el valor hash de la trama esperada y la trama recibida sean la misma
                ,[&buffer, &Hc](char* D, size_t s) -> bool
                {
                    return buffer[0] == Hc->checksum(D, s - 1);
                }

                // Función que se ejecuta al validar los datos recibidos
                ,[ ](char* D, size_t s, double z) -> void
                {
                    std::cout << D << " (" << z << ")" << std::endl;
                }

                // Función que se ejecuta al no poder corregir los datos
                ,[ ](char* D, size_t s, double z) -> void
                {
                    std::cout << D << " ✗ (" << z << ")" << std::endl;
                }
                );
    }
```

### Resultados

Al ejecutar este ejemplo con la lista mostrada, se observan los siguientes resultados:

<<<<<<< HEAD

```txt
=======
```txt

>>>>>>> 0b7030a5db0f1e7ac4992ba3d79d37c3e4c21dec
_BTN1 :BTN1 (1)
uBXY1 :BTN1 (0.6)
%BTN1 :BTN1 (1)
%@TN1 :BTN1 (0.8)
%@TN& :BTN1 (0.6)
6BTXY :BTN1 (0.6)
 BXY1 :BTN1 (0.6)
5XTNY :BTN1 (0.6)
wXYN1 :BTN1 (0.6)
3XTY1 :BTN1 (0.6)
%@^&1 :@^&1 ✗ (0.4)
876N) :76N) ✗ (0.4)
asqwq :sqwq ✗ (0.2)
%@TN& :BTN1 (0.6)
%@^&1 :@^&1 ✗ (0.4)
457py :57py ✗ (0.2)
```
<<<<<<< HEAD

=======
>>>>>>> 0b7030a5db0f1e7ac4992ba3d79d37c3e4c21dec
