//
// Created by saint on 03/08/2018.
//

#ifndef PRUEBA_ED_DELIMITERVARSIZE_REGISTER_H
#define PRUEBA_ED_DELIMITERVARSIZE_REGISTER_H
#include "DataFile.h"
using namespace std;

class DelimiterVarSize_Register {



public:
    DelimiterVarSize_Register(int code, char* name, double salary, char* job);
    ~DelimiterVarSize_Register();
    void print_register( );
    char* toChar();
    void fromChar(char *);
    void open_file();
    void write_into_file();
    void leer_Archivo();
    void close_file();
    int get_size;
private:
    DataFile* archivo;
    int code;
    char* name;
    double salary;
    char *job;
};



#endif //PRUEBA_ED_DELIMITERVARSIZE_REGISTER_H
