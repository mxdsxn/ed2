#include "./heap.hpp"
#include <iostream>

Heap::Heap(int valor, int index)
{
 this->valor = valor;
 this->index = index;
 this->filho1 = nullptr;
 this->filho2 = nullptr;
}

Heap::~Heap()
{
}