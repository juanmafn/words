#include "estructuras.h"

palabras::palabras(){
  cabeza=0; n=0;}

void palabras::insertar(char *p, int lon){
    nodo *nuevo = new nodo(cabeza, 0);
    strcpy(nuevo->palabra, p);
    nuevo->longitud = lon;
    if(cabeza==0) cabeza=nuevo;
    else{
      cabeza = nuevo;
      cabeza->sig->pre = nuevo;
    }
    n++;
  }
nodo* palabras::cab(){return cabeza;}

int palabras::size_pila(){return n;}

void palabras::mostrar(){
  nodo *aux = cabeza;
  while(aux){
    cout << aux->palabra << " -> " << aux->longitud << endl;
    aux=aux->sig;
  }
}

// void palabras::ordenar(){
//   nodo *aux, *aux2;
//   aux=cabeza;
//   aux2=0;
//   while(aux != aux2){
//     while(aux->sig != aux2){
//       if(aux->longitud < aux->sig->longitud){
// 	intercambiar(aux, aux->sig);
//       }
//       else aux=aux->sig;
//     }
//     aux2=aux;
//     aux=cabeza;
//   }
// }
//   void intercambiar(nodo *aux, nodo *aux2){
//     if(aux==cabeza || aux2==cabeza){
//       aux->sig = aux2->sig;
//       aux2->sig = aux;
//       aux->sig->pre = aux;
//       aux2->pre = 0;
//     }
//     else{
//       aux->sig = aux2->sig;
//       aux2->sig = aux;
//       aux->sig->pre = aux;
//       aux2->pre = aux->pre;
//     }
//   }
// };
