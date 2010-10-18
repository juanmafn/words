#ifndef _EST_
#define _EST_

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
  nodo(){sig=0; pre=0;}
  nodo(nodo *s, nodo *p){sig = s; pre=p;}
};

class palabras{
  nodo *cabeza;
  int n;
public:
  palabras();
  void insertar(char *p, int lon);
  nodo *cab();
  int size_pila();
  void mostrar();
  void ordenar();
  void intercambiar(nodo *aux, nodo *aux2);
};
#endif 
