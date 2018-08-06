//
// Created by saint on 04/08/2018.
//

#include "FixedSize_Register.h"

FixedSize_Register::FixedSize_Register()
{
    this->code=-1;
    this->name = new char[30];
    this->salary = -1;
    this->job = new char[20];
    this->archivo = new DataFile();
}

void FixedSize_Register::print_register()
{
    string name = "", salary = "", job="";
}

char * FixedSize_Register::toChar()
{
    char *nuevo = new char[94];
    for (int i = 0; i <30; i++)
    {
        nuevo[i] = this->name[i];
        nuevo[i+30] = this->salary[i+30];
        nuevo[i+60] = this->job[i+60];
    }

    nuevo[90] = this->code;
    return nuevo;
}

void FixedSize_Register::fromChar(char * converter)
{
    for (int i = 0; i < 30; i++)
    {
        this->name[i] = converter[i];
        this->salary[i+30] = converter[i+30];
        this->job[i+60] = converter[i+60];
    }

    this->edad = converter[90];
}

void FixedSize_Register::open_file()
{
    string name;
    cout << "Ingrese nombre del archivo:" << endl;
    cin >> name;
    char *archivo;
    char joel[6];
    archivo = new char[strlen(name.c_str())];
    //strcpy(archivo, name.c_str());

    this->archivo->abrir(archivo);
}


void FixedSize_Register::close_file()
{
  this->archivo.close();
}

int Registro2::tamano_registro()
{
    return 42;
}