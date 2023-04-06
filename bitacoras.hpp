#include <string>
#include <iostream>
#include <sstream> //Lectura de flujos de texto

using namespace std;

class Bitacora{
    //Atributos
    private:
        string mes, dia, hora, ipp, falla;
        int clave;

    //Metodos 
    public: //Operadores de memoria *, -> , &, .
        Bitacora(string mes, string dia, string hora, string ipp, string falla){
            this -> mes = mes;
            this -> dia = dia;
            this -> hora = hora;
            this -> ipp = ipp;
            this -> falla = falla;
            this -> asignarClave();
        }
        string getMes(){return this -> mes;}
        string getDia(){return this -> dia;}
        string getHora(){return this -> hora;}
        string getIpp(){return this -> ipp;}
        string getFalla(){return this -> falla;}
        //int getClave(){return this -> clave;}
        
        void setMes(string mes){this -> mes = mes;}
        void setDia(string dia){this -> dia = dia;}
        void setHora(string hora){this -> hora = hora;}
        void setIpp(string ipp){this -> ipp = ipp;}
        void setFalla(string falla){this -> falla = falla;}
        //void set(int clave){this -> clave = clave;

        string mes2Numero(){ //Falta completar el metodo
            if (!this->mes.compare("Jan"))// ! Es el operador logico not
                return "1";
            else if (!this->mes.compare("Feb"))
                return "2";
            else if (!this->mes.compare("Mar"))
                return "3";
            else if(!this->mes.compare("Apr"))
                return "4";
            else if(!this->mes.compare("May"))
                return "5";
            else if(!this->mes.compare("Jun")) 
                return "6";
            else if(!this->mes.compare("Jul"))
                return "7";
            else if(!this->mes.compare("Aug"))
                return "8";
            else if(!this->mes.compare("Sep"))
                return "9";
            else if(!this->mes.compare("Oct"))
                return "10";
            else if(!this->mes.compare("Nov"))
                return "11";
            else if(!this->mes.compare("Dec"))
                return "12";
            else
                return "0";
        }   

        void asignarClave(){
            //concatenar el mes con el dia para crear la clave
            string id = this->mes2Numero()+this->dia;
            stringstream string2int(id);
            string2int>>this->clave; //se hace la conversion de string a int
        }
        void imprimirRegistro(){
            cout<<this->clave<<" "<<this->mes<<" "<<this->dia<<" "<<this->hora<<" "<<this->ipp<<" "<<this->falla<<"\n";
        }
};
