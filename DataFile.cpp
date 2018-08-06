//
// Created by saint on 01/08/2018.
//
#include "DataFile.h"

DataFile::DataFile()
{
}

void DataFile::abrir(char * direccion)
{
    this->archivo = new fstream(direccion, ios::in | ios::out | ios::binary);
}

void DataFile::cerrar()
{
    this->archivo->close();
}

void DataFile::escribir(char * info, int initialPosition, int size)
{
    this->archivo->seekp(initialPosition);
    this->archivo->write(info,size);
}

char * DataFile::leer(int initialPosition, int size)
{
    char* lectura = new char[size];
    this->archivo->seekp(initialPosition);
    this->archivo->read(lectura,size);
    return lectura;
}

int DataFile::tamanoArchivo()
{
    return this->archivo->tellg();
}

