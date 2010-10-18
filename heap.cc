#include "heap.h"
#include "estructuras.h"

max_heap::max_heap(nodo* v, int tamany_vector){
    tamanyo=tamany_vector;
    ocupados=tamany_vector;
    vector=new nodo [tamanyo];
    for (int i=0; i<tamanyo; i++)
	vector[i]=v[i];
    vector--;	
    buildheap();  // construeix el heap
}
max_heap::max_heap(int tamanyo_maximo){
    tamanyo=tamanyo_maximo;
    ocupados=0;
    vector=new nodo[tamanyo]; 
    vector--;  // despacem cap a l'esquerra el vector 
}

max_heap::~max_heap(){
   vector++;    // fem que apunte a la pos 0 del vector
   delete [] vector;
}

bool max_heap::borrar(int pos){

   if (pos > ocupados || pos <= 0)  
       return false;
   else {
      vector[pos] = vector[ocupados];
      ocupados--;

      // vore si va cap a baix
      heapify(pos);

      // vore si va cap a munt
      int valor=vector[pos];
      while (pos > 1 && valor > vector[padre(pos)]){
          vector[pos]= vector[padre(pos)];
          pos=padre(pos);
      }
      return true;
   }
}
bool max_heap::insertar(nodo elemento){
    if (ocupados == tamanyo)  // el vector esta ple
         return false; 
    else {
         ocupados++;  // crear el forat
         int pos=ocupados;

         while(pos > 1 &&  elemento.longitud > vector[padre(pos)].longitud ){
              vector[pos].longitud=vector[padre(pos)].longitud;
              strcpy(vector[pos].palabra, vector[padre(pos)].palabra);
              pos=padre(pos);    // pujar el forat cap amunt!
         }   
         vector[pos].longitud=elemento.longitud;
         strcpy(vector[pos].palabra, elemento.palabra);
         return true;
    }
}
bool max_heap::maximo(float& elemento){
   if (ocupados == 0) // esta buit
      return false;
   else {
        elemento=vector[1];
        return true;
   }
}
bool max_heap::borrar_maximo(){
    if (ocupados == 0)  //esta buit
        return false;
    else {
        vector[1].longitud=vector[ocupados].longitud;
        strcpy(vector[1].palabra, vector[ocupados].palabra);
        ocupados--;
        heapify(1);
        return true;
    }
}
void max_heap::heapify(int pos){
   int fill=hijo_izq(pos);  // suposem que el esq es major

   if (fill > ocupados) // es una fulla
	return;

   if (fill + 1 <= ocupados && vector[fill].longitud < vector[fill+1].longitud)
        fill++;  // el major es el dret

   if (vector[fill].longitud > vector[pos].longitud) {
      nodo tmp;
      tmp.longitud = vector[fill].longitud;
      strcpy(tmp.palabra, vector[fill].palabra)
      vector[fill].longitud=vector[pos].longitud;
      strcpy(vector[fill].palabra, vector[pos].palabra);
      vector[pos].longitud=tmp.longitud;
      strcpy(vector[pos].palabra, tmp.palabra);
      heapify(fill);
   }

}

void  max_heap::buildheap(){       // se usa para imponer propiedad de orden
   for (int pos=ocupados/2; pos >=1 ; pos--)
	heapify(pos);
}

void max_heap::heapsort(){

   int num_elem=ocupados;
   for(int i=1; i<num_elem; i++){
       // intercanviar la primera i la Ãºltima pos
       int aux=vector[1];
       vector[1]=vector[ocupados];
       vector[ocupados]=aux;

       // deixar fora del heap la Ãºltima pos
       ocupados--;

       // refer el heap
        heapify(1);
    }
    ocupados=num_elem;
} 

