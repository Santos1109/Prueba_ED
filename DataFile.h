//
// Created by saint on 01/08/2018.
//

#ifndef PRUEBA1_DATAFILE_H
#define PRUEBA1_DATAFILE_H
#include<fstream>
using  namespace std;

class DataFile{
public:
    void abrir(char* direccion);
    void cerrar();
    void escribir(char*, int, int);
    char* leer(int, int);
    DataFile();

private:
    char* direccion;
    fstream *archivo;
};

#endif //PRUEBA1_DATAFILE_H
