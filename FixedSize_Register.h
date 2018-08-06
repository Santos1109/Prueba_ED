//
// Created by saint on 05/08/2018.
//

#ifndef PRUEBA_ED_FIXEDSIZE_REGISTER_H
#define PRUEBA_ED_FIXEDSIZE_REGISTER_H


class FixedSize_Register {
public:
    FixedSize_Register();
    void print_register();
    char* toChar();
    void fromChar(char *);
    void open_file();
    void leer_Archivo();
    void close_file();
    int get_size();
private:
    DataFile * archivo;
    int code;
    char *name;//30
    double salary;
    char* job;//20
};


#endif //PRUEBA_ED_FIXEDSIZE_REGISTER_H
