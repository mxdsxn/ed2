#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

void imprimirLista(int *lista, int tam)
{
 int i;
 for (i = 0; i < tam; i++)
 {
  cout << lista[i] << ' ';
 }
 cout << endl;
}

int pai(int i)
{
 return (i - 1) / 2;
}

int esquerda(int i)
{
 return (i * 2) + 1;
}

int direita(int i)
{
 return (i * 2) + 2;
}

void trocar(int *lista, int a, int b)
{
 int aux = lista[a];
 lista[a] = lista[b];
 lista[b] = aux;
}

void minHeapify(int *lista, int tam, int i)
{
 int filho1Esquerda = esquerda(i);
 int filho2Direita = direita(i);
 int menor = i;

 if ((filho1Esquerda < tam) && (lista[filho1Esquerda] < lista[i]))
 {
  menor = filho1Esquerda;
 }

 if ((filho2Direita < tam) && (lista[filho2Direita] < lista[menor]))
 {
  menor = filho2Direita;
 }

 if (menor == i)
 {
  return;
 }

 trocar(lista, i, menor);
 minHeapify(lista, tam, menor);
}

int heapExtractMin(int *lista, int *tam)
{
 if (*tam < 1)
 {
  cout << "XXXX Tamanho Invalido XXXX";
 }

 int min = lista[0];
 lista[0] = lista[*tam - 1];
 *tam = *tam - 1;

 minHeapify(lista, *tam, 0);

 return min;
}

void buildMinHeap(int *lista, int tam)
{
 for (int i = (tam / 2) - 1; i >= 0; i--)
 {
  minHeapify(lista, tam, i);
 }
}

void heapDecreaseKey(int *lista, int i, int chave, int tam)
{
 if (chave > lista[i])
 {
  return;
 }

 lista[i] = chave;
 buildMinHeap(lista, tam);
}

void minHeapInsert(int *lista, int chave, int *tam)
{
 *tam = *tam + 1;
 lista[*tam - 1] = 999999;
 heapDecreaseKey(lista, *tam - 1, 0, *tam);
}

int main()
{

 int lista[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
 int tam = sizeof(lista) / sizeof(lista[0]);

 cout << ">> Exercicio 2: ";
 imprimirLista(lista, tam);
 cout << endl;

 buildMinHeap(lista, tam);
 cout << ">> Build min heap: ";
 imprimirLista(lista, tam);
 cout << endl;

 heapExtractMin(lista, &tam);
 cout << ">> Heap extract min: ";
 imprimirLista(lista, tam);
 cout << endl;

 // Alterando valor da última chave de 16 para 1
 heapDecreaseKey(lista, tam - 1, 1, tam);
 cout << ">> Heap decrease key: ";
 imprimirLista(lista, tam);
 cout << endl;

 // Inserindo valor 0!
 minHeapInsert(lista, 0, &tam);
 cout << ">> Min heap insert: ";
 imprimirLista(lista, tam);
 cout << endl;

 return 0;
}