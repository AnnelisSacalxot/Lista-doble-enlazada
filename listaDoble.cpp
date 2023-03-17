#include <iostream>
using namespace std;

//creando mi clase Nodo
class Nodo{

  public:
    int key;
    int dato;
    Nodo* siguiente;
    Nodo* anterior;

    //constructor
    Nodo(){
        key= 0;
        dato= 0;
        siguiente = NULL;
        anterior = NULL;
    }

    Nodo(int k, int d){
        key = k;
        dato = d;
    }
};

//clase Lista doblemente enlazada

class listaDobleEnlazada{
    public:
        Nodo* cabeza;

        //al principio no hay nada es por eso que apunta a nulo
        listaDobleEnlazada(){
            cabeza = NULL;
        }

        listaDobleEnlazada(Nodo* n){
            cabeza = n;
        }

        //Comprobando si el nodo existe
        Nodo* comprobandoNodoExiste(int k){
            Nodo* temporal = NULL;
            Nodo* ptr = cabeza;

            while (ptr != NULL)
            {
               if (ptr->key == k)
               {
                temporal = ptr;
               }
               ptr = ptr->siguiente;
               
            }
            return temporal;
        }
};

int main(){

    return 0;
}