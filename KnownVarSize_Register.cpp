//
// Created by saint on 04/08/2018.
//

#include "KnownVarSize_Register.h"


KnownVarSize_Register::KnownVarSize_Register(char* name, double salary, char *job)
{
    this->size_name = strlen(name);
    this->name = name;
    this->salary = salary;
    this->job=job;
    this->archivo = new DataFile();
}


KnownVarSize_Register::~KnownVarSize_Register()
{
}

void KnownVarSize_Register::print_register() {
    string comparar;
    int inicio = 0;
    int tamano = 0;
    bool continuar = true;
    char* datos;
    int tamanoArchivo = this->archivo->tamanoArchivo;
    cout << "-MOSTRANDOTODOSLOSREGISTROS-" << endl;
    while (tamano < tamanoArchivo)
    {
        comparar.assign(this->archivo->leer(tamano, 1));
        if (comparar == ";")
            datos = this->archivo->leer(inicio, tamano);
        this->fromChar(datos);
        inicio = tamano;
        tamano++;
    }
    cout << "--------FINALDELINEA--------" << endl;

}

char * KnownVarSize_Register::toChar()
{
    char caracter_separacion = '|';
    char caracter_de_fin = ';';
    int tamano_registro = this->tamano_registro();
    char *nuevo = new char[tamano_registro];
    int pos = 0;
    memcpy(&nuevo[pos], (char*)this->size_name, sizeof(int));
    pos += 4;
    memcpy(&nuevo[pos], this->name, this->size_name);
    pos += this->size_name;
    memcpy(&nuevo[pos], &caracter_separacion, 1);
    pos++;
    memcpy(&nuevo[pos], (char*)this->salary, sizeof(double));
    pos += 8;
    memcpy(&nuevo[pos], &caracter_separacion, 1);
    pos++;
    memcpy(&nuevo[pos], this->job, 30);
    pos += 30;

    memcpy(&nuevo[pos], &caracter_de_fin, 1);
    return nuevo;
}

void KnownVarSize_Register::fromChar(char *converter)
{
    int tamanoActual = 0;
    int posicionEnConverter = 0;
    int posicionEnPropiedadDelRegistro = 0;
    int edad = 0;
    for (int i = 0; i < 7; i++) {
        if (i != 0 && i != 2 && i != 4) {
            for (int x = 0; x < 4; x++) {
                tamanoActual += atoi(&converter[i]);
            }
            posicionEnConverter += 4;
            for (int y = posicionEnConverter; y < tamanoActual; y++) {
                if (i == 1) {
                    this->nombre[posicionEnPropiedadDelRegistro] = converter[y];
                }
                else if (i == 3) {
                    this->apellido[posicionEnPropiedadDelRegistro] = converter[y];
                }
                else if (i == 6) {
                    this->direccion[posicionEnPropiedadDelRegistro] = converter[y];
                }
            }
            tamanoActual = 0;
            posicionEnPropiedadDelRegistro = 0;
        }
        else if(i == 4){
            for (int x = 0; x < 4; x++) {
                edad += atoi(&converter[i]);
            }
            this->edad = edad;
        }
    }
    cout << "Name Size: " << this->size_name << endl;
    cout << "Name: " << this->name << endl;
    cout << "Salary: " << this->salary << endl;
    cout << "Job: " << this->job << endl;
}

void KnownVarSize_Register::open_file()
{
    string name;
    cout << "Ingrese nombre del archivo:" << endl;
    cin >> name;
    char *archivo;
    archivo = new char[strlen(name.c_str())];
    this->archivo->abrir(archivo);
}

void KnownVarSize_Register::leer_Archivo()
{
    string comparar;
    int tamano = 0;
    bool continuar = true;
    while (continuar)
    {
        comparar.assign(this->archivo->leer(tamano, 1));
        if (comparar == ";")
            continuar = false;
        tamano++;
    }
    char* datos = this->archivo->leer(0, tamano);
    this->fromChar(datos);
}

void DelimiterVarSize_Register::close_file()
{
    this->archivo->cerrar();
}

int DelimeterVarSize::get_size()
{
    int tamano_registro = 0;
    tamano_registro += strlen(this->name);
    tamano_registro += sizeof(double);
    tamano_registro += strlen(this->job);
    return tamano_registro;
}