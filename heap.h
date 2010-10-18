#include <iostream>
using namespace std;

   class max_heap {     // maxheap binario de valores de tipo T comparables
      nodo *vector;                         // vector que empieza con indice 1
      int tamanyo,ocupados;
      int padre(int pos) { return pos/2; }                    // estas tres
      int hijo_izq(int pos) { return 2*pos; }                 // funciones
      int hijo_der(int pos) { return 2*pos+1; }               // son inline
      void heapify(int pos);
      void heapify_recursiva(int pos);
   public:
      max_heap(int tamanyo_maximo);                          // constructor
      ~max_heap();                                            // destructor
      void vaciar() { ocupados = 0; }
      bool vacio() const { return ocupados == 0; }
      bool lleno() const { return ocupados == tamanyo; }
      int ocupacion() const { return ocupados; }
      
      
      bool borrar_maximo();                      // "true" si se ha borrado
      
      
      bool insertar(float elemento);         // "true" si se ha podido insertar
      void buildheap();           // se usa para imponer propiedad de orden
      void heapsort();       // despues de esto, el vector YA NO es un heap
   };


