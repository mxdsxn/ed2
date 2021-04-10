#include <iostream>
#include "./heapSort.hpp"

using namespace std;

int main()
{
   int V[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
   int tam = sizeof(V) / sizeof(V[0]), v[10];

   HeapSort *heapSort = new HeapSort();

   heapSort->sort(V, tam);
   cout << "main: endereco vetorOrdenado: " << heapSort->vetorOrdenado << endl;

   *v = *(heapSort->vetorOrdenado);
   for (int i = 0; i < tam; i++)
   {
      cout << heapSort->vetorOrdenado[i] << ',' << endl;
   }
}