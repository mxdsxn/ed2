#include "./heapSort.hpp"
#include <iostream>

using namespace std;

HeapSort::HeapSort() {}
HeapSort::~HeapSort() {}

Heap *HeapSort::pai(Heap *no)
{
  if (this)
  {
    int index = (no->index - 1) / 2;
    return this->vetorHeap[index];
  }
  return nullptr;
}

void HeapSort::trocar(Heap *a, Heap *b)
{
  if (this)
  {
    int tmpValor = a->valor;

    a->valor = b->valor;

    b->valor = tmpValor;
  }
}

void HeapSort::maxHeapfy(int index)
{
  if (this)
  {
    Heap *no = this->vetorHeap[index];
    Heap *maior = no;

    if (no->filho1 != nullptr && no->filho1->valor > no->valor)
      maior = no->filho1;

    if (no->filho2 != nullptr && no->filho2->valor > maior->valor)
      maior = no->filho2;

    if (maior == no)
      return;

    if (maior == no->filho1)
    {
      this->trocar(maior, no);
      this->maxHeapfy(maior->index);
    }
    else if (maior == no->filho2)
    {
      this->trocar(maior, no);
      this->maxHeapfy(maior->index);
    }
  }
}

void HeapSort::buildMaxHeap()
{
  if (this)
  {
    int tamanhoVetor = this->tamanhoVetor;
    int meioIndex = tamanhoVetor / 2;

    for (int i = meioIndex; i >= 0; i--)
    {
      this->maxHeapfy(this->vetorHeap[i]->index);
    }
  }
}

void HeapSort::sort(int *vetorDesordenado, int tamanhoVetor)
{
  if (this)
  {
    tamanhoVetor--;

    Heap *vetorHeap[10];

    this->tamanhoVetor = tamanhoVetor;
    this->vetorDesordenado = vetorDesordenado;
    this->vetorOrdenado = (int *)malloc(sizeof(int) * tamanhoVetor);
    this->vetorHeap = vetorHeap;

    for (int i = 0; i <= tamanhoVetor; i++)
    {
      this->vetorHeap[i] = nullptr;

      Heap *no = new Heap(this->vetorDesordenado[i], i);

      this->vetorHeap[i] = no;
    }

    for (int i = 0; i <= (tamanhoVetor / 2); i++)
    {
      int indexFilho = (i * 2) + 1;
      this->vetorHeap[i]->filho1 = indexFilho <= tamanhoVetor ? this->vetorHeap[indexFilho] : nullptr;
      this->vetorHeap[i]->filho2 = indexFilho + 1 <= tamanhoVetor ? this->vetorHeap[indexFilho + 1] : nullptr;
    }

    this->buildMaxHeap();

    for (int i = tamanhoVetor; i >= 0; i--)
    {
      Heap *ultimoNo = this->vetorHeap[i];
      Heap *primeiroNo = this->vetorHeap[0];

      if (i > 0)
      {
        this->trocar(ultimoNo, primeiroNo);

        Heap *pai = this->pai(ultimoNo);

        if (pai->filho1 == ultimoNo)
          pai->filho1 = nullptr;
        else if (pai->filho2 == ultimoNo)
          pai->filho2 = nullptr;

        this->maxHeapfy(primeiroNo->index);

        this->vetorHeap[i] = nullptr;
        this->vetorOrdenado[i] = ultimoNo->valor;
        delete this->vetorHeap[i];
      }
      else
      {
        this->vetorOrdenado[i] = ultimoNo->valor;
      }
    }
  }
}

void HeapSort::imprimir()
{

  for (int i = 0; i <= this->tamanhoVetor; i++)
  {
    cout << " | no com o Maior valor: index - " << i << " | valor - " << *(this->vetorOrdenado + i) << endl;
  }
}