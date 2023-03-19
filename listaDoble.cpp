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
            Nodo* nodito = cabeza;

            while (nodito != NULL)
            {
               if (nodito ->key == k)
               {
                temporal = nodito ;
               }
               nodito  = nodito->siguiente;
               
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
                Nodo* nodito  = cabeza;
                //si no se ha terminado los nodos
                while (nodito ->siguiente != NULL)
                {
                    nodito  = nodito->siguiente;
                }
                nodito ->siguiente = n;
                n->anterior = nodito;
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
        Nodo* nodito  = comprobandoNodoExiste(k);
        if (nodito  == NULL)
        {
            cout<<"No existe el nodo"<<endl;
        } else{
            if (comprobandoNodoExiste(n->key) != NULL)
            {
                cout<<"El valor ya existe: "<<n->key<<"Agregar nodo con disntitno valor"<<endl;
            }else{
                cout<<"Insertar"<<endl;
                Nodo* nodoSiguiente = nodito ->siguiente;
                //insertando nodo al final
                if (nodoSiguiente != NULL)
                {
                    nodito ->siguiente = n;
                    n->anterior = nodito ;
                    cout<<"Insertar nodo al final"<<endl;
                }else{ //insertando nodo el medio
                    n->siguiente = nodoSiguiente;
                    nodoSiguiente->anterior = n;
                    n->anterior = nodito ;
                    nodito ->siguiente = n;
                    cout<<"Nodo insertado en medio"<<endl;
                }
                
            }
            
        }
        
    }

    //Reemplazar nodo de posicion
    void eliminarNodo(int k){
        Nodo* nodito  = comprobandoNodoExiste(k);
        if (nodito  == NULL)
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
                Nodo* siguienteNodo = nodito ->siguiente;
                Nodo* anteriorNodo = nodito ->anterior;

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

    //actualizar nodo
    void actualizarNodo(int k, int d){
        Nodo* nodito  = comprobandoNodoExiste(k);
        if (nodito  != NULL)
        {
            nodito ->dato = d;
            cout<<"Se actualizo el valor con exito"<<endl;
        }else{
            cout<<"El nodo no existe, por lo que no se puede cambiar valor"<<k<<endl;
        }
        
    } 

    //imprimir

    void imprimirLista(){
        if (cabeza == NULL)
        {
            cout<<"El nodo y valor no existe"<<endl;
        }else{
            cout<<"Lista doblemente enlazada: "<<endl;
            Nodo* temporal = cabeza;

            while (temporal != NULL)
            {
                cout<<"("<<temporal->key<<","<<temporal->dato<<") <--"<<endl;
                temporal = temporal->siguiente;
            }
            
        }
        
    }
};

int main(){

    listaDobleEnlazada doble;
    int opcion;
    int key1, k1, dato1;

    do
    {
        /* menu de manipulacion de datos */
        cout<<"\n Eliga la opción que desea para la lista doble enlazada"<<endl;
        cout<<"1. Agregar Nodo a la lista"<<endl;
        cout<<"2. Agregar Nodo antes de algun valor ya establecido"<<endl;
        cout<<"3. Eliminar Nodo"<<endl;
        cout<<"5. Actualizar valor de algun Nodo"<<endl;
        cout<<"6. Imrpimir lista"<<endl;
        cout<<"7. Limpiar consola"<<endl<<endl;

        cin>>opcion;
        Nodo* n1 = new Nodo();

        switch (opcion)
        {
        case 0:
            break;
        case 1:
            cout<<"Agregar nodo"<<endl;
            cin>>key1;
            cin>>dato1;
            n1->key = key1;
            n1->dato = dato1;
            //llamo a mi funcion
            doble.agregarNodo(n1);
            break;
        case 2:
            cout<<"Ingrese valor del nodo que se antepondra"<<endl;
            cin>>key1;
            cin>>dato1;
            n1->key = key1;
            n1->dato = dato1;
            //lamando a mi funcion
            doble.agregarNodoInicio(n1);
            break;    
        case 3:
            cout<<"Ingrese valor de nodo que ya existe, para agregarlo el valor que desea despues de el"<<endl;
            cin>>key1;
            cout<<"Dato del nuevo nodo"<<endl;
            cin>>key1;
            cin>>dato1;
            n1->key = key1;
            n1->dato = dato1;
            //lamando a mi funcion
            doble.agregarNodoPosicion(k1,n1);
            break;
        case 4:
            cout<<"Ingrese valor del nodo a eliminar"<<endl;
            cin>>key1;
            //llamando a mi funcion
            doble.eliminarNodo(k1);
            break;
        case 5:
            cout<<"Ingrese valor del nuevo nodo, para actualizar la lista"<<endl;
            cin>>key1;
            cin>>dato1;
            //llamamos a la funcion
            doble.actualizarNodo(key1, dato1);
            break; 
         case 6:
            cout<<"Imprimiendo lista: "<<endl;
            //llamamos a la funcion
            doble.imprimirLista();
            break;
         case 7:
            system("cls");
            break;           
        default:
         cout<<"Error, esta opcion no existe"<<endl;
            break;
        }

    } while (opcion!=0);
    

    return 0;
}