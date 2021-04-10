#pragma once
#include "./heap.hpp"

class HeapSort
{
public:
 int *vetorDesordenado, *vetorOrdenado, tamanhoVetor;
 Heap **vetorHeap;

 Heap *pai(Heap *no);
 void trocar(Heap *a, Heap *b);
 void maxHeapfy(int index);
 void buildMaxHeap();
 void sort(int *vatorDesordenado, int tamVet);
 void imprimir();

 HeapSort();
 ~HeapSort();
};