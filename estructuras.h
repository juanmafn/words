//#ifndef _EST_
//#define _EST_

#include <iostream>
#include <string.h>

using namespace std;

struct tipo{
  char letra;
  bool a;
};

struct nodo{
  char palabra[50];
  int longitud;
  nodo *sig, *pre;
  nodo(nodo *s, nodo *p){sig = s; pre=p;}
};

class palabras{
  nodo *cabeza;
  int n;
public:
  palabras(){cabeza=0; n=0;}
  void insertar(char *p, int lon){
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
  nodo *cab(){return cabeza;}
  int size_pila(){return n;}
  void mostrar(){
    nodo *aux = cabeza;
    while(aux){
      cout << aux->palabra << " -> " << aux->longitud << endl;
      aux=aux->sig;
    }
  }
  void ordenar(){
    nodo *aux, *aux2;
    aux=cabeza;
    aux2=0;
    while(aux != aux2){
      while(aux->sig != aux2){
	if(aux->longitud < aux->sig->longitud){
	  intercambiar(aux, aux->sig);
	}
	else aux=aux->sig;
      }
      aux2=aux;
      aux=cabeza;
    }
  }
  void intercambiar(nodo *aux, nodo *aux2){
    if(aux==cabeza || aux2==cabeza){
      aux->sig = aux2->sig;
      aux2->sig = aux;
      aux->sig->pre = aux;
      aux2->pre = 0;
    }
    else{
      aux->sig = aux2->sig;
      aux2->sig = aux;
      aux->sig->pre = aux;
      aux2->pre = aux->pre;
    }
  }
};

//#endif 
