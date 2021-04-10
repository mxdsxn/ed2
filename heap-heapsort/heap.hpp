#pragma once

class Heap
{
public:
  int valor, index;
  Heap *filho1, *filho2;

  Heap(int valor, int index);
  ~Heap();
};