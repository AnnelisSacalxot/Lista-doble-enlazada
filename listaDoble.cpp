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

        //agregar nuevo nodo a la lista
    void agregarNodo(Nodo* n){
        if (comprobandoNodoExiste(n->key) != NULL)
        {
            cout<<"El nodo ya existe : "<<n->key<<". Agrege un valor distinto"<<endl;

        } else{
            if (cabeza == NULL)
            {
                cabeza = n;
                cout<<"El nodo se agrego correctamente, ahora es la cabeza"<<endl;
            }else{
                Nodo* ptr = cabeza;
                //si no se ha terminado los nodos
                while (ptr->siguiente != NULL)
                {
                    ptr = ptr->siguiente;
                }
                ptr->siguiente = n;
                n->anterior = ptr;
                cout<<"Nodo agregado"<<endl;
            }

        }
        
    }    
};

int main(){

    return 0;
}