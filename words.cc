#include <fstream>
#include "heap.h"
#include "estructuras.h"
  
void inicializa(tipo *letras, int lon){
  for(int i=0;i<lon;i++){
    letras[i].a = false;
  }
}

void genera_palabras(tipo *letras, int lon, palabras *words){
  ifstream diccionario;
  char buffer[50];
  bool sirve;
  //palabras words;
  diccionario.open("diccionario");
  while(diccionario >> buffer){
    sirve=1;
    inicializa(letras, lon);
    int lon2 = strlen(buffer);
    for(int i=0;i<lon2;i++){
      if(sirve==0) break;
      for(int j=0;j<lon;j++){
	if(buffer[i]==letras[j].letra && letras[j].a == false){
	  letras[j].a=true;
	  break;
	}
	if(j==lon-1) sirve=0;
      }
    }
    if(sirve == 1 && lon!=0) words->insertar(buffer, lon2);
  }
  diccionario.close();
  //return &words;
}

int main(int argc, char *argv[]){
  palabras words;
  tipo *letras = new tipo[argc];
  for(int i=0;i<argc-1;i++){
    letras[i].letra=argv[i+1][0];
    letras[i].a=false;
  }
  genera_palabras(letras, argc-1, &words);
  //words->ordenar();
  int x=words.size_pila();
  max_heap heap(x);
  nodo *aux=words.cab();
  while(aux){
    heap.insertar(aux);
    aux=aux->sig;
  }
  while(!heap.vacio()){
    cout << heap.maximo().palabra << " -> " << heap.maximo().longitud << endl;
    heap.borrar_maximo();
  }
  //words->mostrar();
  return 0;
}
