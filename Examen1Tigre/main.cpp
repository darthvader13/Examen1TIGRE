#include <iostream>
#include <fstream>
#include <math.h>
#include <list>
#include <vector>
#include "Evaluador.h"
using namespace std;

///////////////////////////////////////////////////////////////////
///////////////////////////// PARTE 1 /////////////////////////////
///////////////////////////////////////////////////////////////////

//Devuelve el atributo *nombre* de *usuario*
string getNombre(Usuario* usuario)
{

    Usuario v = *usuario;
    return v.nombre;
}

//Escribe todos los atributos de *usuario* en un archivo con con nombre *nombre_archivo*
void escribir(string nombre_archivo, Usuario* usuario)
{

}

//Lee los atributos de un *Usuario* desde un archivo con nombre *nombre_archivo* y luego lo devuelve
Usuario* leer(string nombre_archivo)
{

}

//Devuelve cuantas veces existe *numero* en *numeros*
int contar(vector<int> numeros, int numero)
{
    int n_veces = 0;
    for (int x=0;x<numeros.size();x++)
    {
        if(numeros[x]==numero)
        n_veces+=1;
    }

    return n_veces;
}

//Devuelve *true* si existe al menos un valor repetido en *cadenas*
bool existeRepetida(list<string> cadenas)
{
    cadenas.sort();
    int repetido = cadenas.size();
    cadenas.unique();
    int existente = cadenas.size();
    if(existente==repetido){
        return false;
        }
        else{
            return true;
        }
}

//Devuelve el contenido de *letras* invertido
vector<char> invertir(vector<char> letras)
{
    vector<char> respuesta;
    int v = letras.size();
    for (int x=0;x<v;x++)
    {
        respuesta.push_back(letras.back());
        letras.pop_back();
    }
    return respuesta;
}

///////////////////////////////////////////////////////////////////
///////////////////////////// PARTE 2 /////////////////////////////
///////////////////////////////////////////////////////////////////

//Realizar las siguientes clases dado el diagrama adjunto

//Lugar
//Lugar() Constructor vacio
//vendeComida() Funcion abstracta

//Restaurante
//Restaurante() Inicializa atributos
//vendeComida() Devuelve true

//Monumento
//Monumento() Inicializa atributos
//vendeComida() Devuelve false

///////////////////////////////////////////////////////////////////
////////////////////////////// Main ///////////////////////////////
///////////////////////////////////////////////////////////////////

void evaluar();
void evaluar2();

class Lugar
{
public:
        string Nombre;
        double Latitud;
        double Longitud;
        Lugar(){
        }
       virtual bool vendeZapatos()

};

class Zapateria
{
public:
    string horario;
    string nombre;
    double latitud;
    double longitud;
     Restaurante(string nombre,double latitud,double longitud,string horario)
    {
        this->horario=horario;
        this->latitud=latitud;
        this->longitud=longitud;
        this->nombre=nombre;
    }
    bool vendeZapatos()
    {
        return true;
    }
};
class Monumento
{
public:
    string nombre;
    double latitud;
    double longitud;


        Monumento(string nombre,double latitud,double longitud)
    {
        this->latitud=latitud;
        this->longitud=longitud;
        this->nombre=nombre;
    }


    bool vendeZapatos()
    {
     return false;
    }

};
int main ()
{
    //Funcion evaluadora parte 1
    cout<<"Evaluador parte 1"<<endl<<"================="<<endl;
    evaluar();


    //Evaluacion parte 2
    //Descomentar para evaluar
    cout<<"Evaluador parte 2"<<endl<<"================="<<endl;
    evaluar2();

    return 0;
}


///////////////////////////////////////////////////////////////////////
///////////////////////////// Evaluador 2 /////////////////////////////
///////////////////////////////////////////////////////////////////////


void evaluar2()
{
    double nota=0;

    cout<<"**Clase Zapateria**"<<endl;
    cout<<"Test constructor:\t\t";
    if(Restaurante("Converze",4.2,9.2,"24/7").nombre== "Coverze"
       && Restaurante("Coverze",8.1,6.3,"24/7").latitud== 6.1
       && Restaurante("Coverze",5.2,6.6,"24/7").longitud== 6.6
       && Restaurante("Coverze",4.2,9.2,"Toda la Semana").horario== "Toda la Semana"

       && Restaurante("Adibas",5.2,6.2,"24/7").nombre== "Adibas"
       && Restaurante("Adibas",10.1,6.2,"24/7").latitud== 10.1
       && Restaurante("Adibas",5.2,8.6,"24/7").longitud== 8.6
       && Restaurante("Adibas",5.2,6.2,"Martes a Jueves").horario== "Martes a Jueves"
       )
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Test vendeZapatos():\t\t";

    if(Zapateria("Coverze",4.2,9.2,"24/7").vendeZapatos()
       && Zapateria("Adibas",5.2,6.2,"24/7").vendeZapatos())
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }


    cout<<"**Clase Monumento**"<<endl;
    cout<<"Test constructor:\t\t";
    if(Monumento("Converze",4.2,9.2).nombre== "Coverze"
       && Monumento("Coverze",6.1,6.2).latitud== 6.1
       && Monumento("Coverze",5.2,6.6).longitud== 6.6

       && Monumento("Adibas",5.2,6.2).nombre== "Adibas"
       && Monumento("Adibas",10.1,6.2).latitud== 10.1
       && Monumento("Adibas",5.2,8.6).longitud== 8.6
       )
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Test vendeZapatos():\t\t";

    if(!Monumento("Coverze",5.2,6.2).vendeZapatos()
       && !Monumento("Adibas",5.2,6.2).vendeZapatos())
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<endl<<"Nota: "<<nota<<"/8"<<endl;
}
