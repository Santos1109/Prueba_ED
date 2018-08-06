//
// Created by saint on 05/08/2018.
//

#ifndef PRUEBA_ED_KNOWNVARSIZE_REGISTER_H
#define PRUEBA_ED_KNOWNVARSIZE_REGISTER_H


class KnownVarSize_Register {
public:
    KnownVarSize_Register(char* nombre, double salary, char* job);
    ~KnownVarSize_Register();
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
    int size_name;
    char* name;
    double salary;
    char *job;
};


#endif //PRUEBA_ED_KNOWNVARSIZE_REGISTER_H
