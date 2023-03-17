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

    //poner nodo al principio
    void agregarNodoInicio(Nodo* n){
        if (comprobandoNodoExiste(n->key) != NULL)
        {
            cout<<"El valor ya existe: "<<n->key<<" Agrege nodo con distinto valor "<<endl;
        } else{
            if(cabeza == NULL){
                cabeza = n;
                cout<<"Agregando nodo al inicio"<<endl;
            }else{
            cabeza->anterior = n;
            n->siguiente = cabeza;
            cabeza = n;
            cout<<"preparando nodo"<<endl;
            }
        }
        
    }

    //Agregar un nodo en un lugar especifico
    void agregarNodoPosicion(int k, Nodo* n){
        Nodo* ptr = comprobandoNodoExiste(k);
        if (ptr == NULL)
        {
            cout<<"No existe el nodo"<<endl;
        } else{
            if (comprobandoNodoExiste(n->key) != NULL)
            {
                cout<<"El valor ya existe: "<<n->key<<"Agregar nodo con disntitno valor"<<endl;
            }else{
                cout<<"Insertar"<<endl;
                Nodo* nodoSiguiente = ptr->siguiente;
                //insertando nodo al final
                if (nodoSiguiente != NULL)
                {
                    ptr->siguiente = n;
                    n->anterior = ptr;
                    cout<<"Insertar nodo al final"<<endl;
                }else{ //insertando nodo el medio
                    n->siguiente = nodoSiguiente;
                    nodoSiguiente->anterior = n;
                    n->anterior = ptr;
                    ptr->siguiente = n;
                    cout<<"Nodo insertado en medio"<<endl;
                }
                
            }
            
        }
        
    }

    //Reemplazar nodo de posicion
    void eliminarNodo(int k){
        Nodo* ptr = comprobandoNodoExiste(k);
        if (ptr == NULL)
        {
            cout<<"No existe el nodo"<<endl;
        } else{
            if (cabeza == NULL)
            {
                cout<<"Lista vacia"<<endl;
            } else if (cabeza != NULL)
            {
                cabeza = cabeza->siguiente;
                cout<<"Nodo sin valor"<<k<<endl;
            }else{
                Nodo* siguienteNodo = ptr->siguiente;
                Nodo* anteriorNodo = ptr->anterior;

                //eliminar lo del final
                if (siguienteNodo == NULL)
                {
                    anteriorNodo->anterior = NULL;
                    cout<<"Ultimo nodo eliminado"<<endl;
                }else{//elimimar nodo del medio
                    anteriorNodo->siguiente = siguienteNodo;
                    siguienteNodo->anterior = anteriorNodo;
                    cout<<"Se eliminio nodo del medio"<<endl;
                }
                
            }
            
            
        }
        
    }    
};

int main(){

    return 0;
}