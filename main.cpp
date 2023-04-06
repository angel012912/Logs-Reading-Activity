#include "bitacoras.hpp"
#include <vector>
#include <iostream>
#include <fstream> //biblioteca para lectura y escritura de archivos
#include <string>


using namespace std;

int main(){
    //Declarando apuntador
    Bitacora *prueba;
    //Objeto en el heap
    prueba = new Bitacora("Oct", "01", "10:32:24", "127.0.0.1:8080", "Error 404");
    //Imprimir
    prueba->imprimirRegistro();
    return 0;

    //Escribir un archivo
    ofstream miArchivo("archivo1.txt");
    for(int i = 1; i <= 10; i++){
        miArchivo<<i<<"\n";
    }
    miArchivo<<"Esto es una prueba de escritura\n";
    miArchivo.close();

    //LeerunArchivo
    ifstream datos;
    datos.open("bitacoraSecundaria-1.txt");
    string entrada;
    while(getline(datos, entrada)){
        cout<<entrada<<endl;
        cout<<"Entra al archivo"<<endl;
    }
    datos.close();

    //Lectura de archivo separada
    datos.open("bitacoraSecundaria-1.txt");
    string mes, dia, hora, ipp, falla;
    vector<Bitacora *> log;
    while(datos.good()){
        getline(datos,mes,' ');
        getline(datos,dia,' ');
        getline(datos,hora,' ');
        getline(datos,ipp,' ');
        getline(datos, falla); //El salto de linea es por default
        log.push_back(new Bitacora(mes, dia, hora, ipp, falla));
    }
    datos.close();
    for(Bitacora * registro:log ){
        registro->imprimirRegistro();
    }
    for(Bitacora * registro:log ){
        delete registro;
    }
}