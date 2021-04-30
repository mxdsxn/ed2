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

void max_heapify(int *lista, int tam, int i)
{
 int filho1Esquerda = esquerda(i);
 int filho2Direita = direita(i);
 int maior = i;

 if ((filho1Esquerda < tam) && (lista[filho1Esquerda] > lista[i]))
 {
  maior = filho1Esquerda;
 }

 if ((filho2Direita < tam) && (lista[filho2Direita] > lista[maior]))
 {
  maior = filho2Direita;
 }

 if (maior == i)
 {
  return;
 }

 trocar(lista, i, maior);
 max_heapify(lista, tam, maior);
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
 // =================== EXERCICIO 1
 cout << "=================== EXERCICIO 1 ===================" << endl;

 int listaExercicio1[] = {15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1};

 int tamExercicio1 = sizeof(listaExercicio1) / sizeof(listaExercicio1[0]);

 cout << ">> Lista Exercicio 1: ";
 imprimirLista(listaExercicio1, tamExercicio1);

 // Alterando valor da primeira chave para 1
 heapDecreaseKey(listaExercicio1, 0, 1, tamExercicio1);

 cout << ">> Heap decrease key: ";
 imprimirLista(listaExercicio1, tamExercicio1);

 // =================== EXERCICIO 2
 cout << "=================== EXERCICIO 2 ===================" << endl;

 int listaExercicio2[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
 int tamExercicio2 = sizeof(listaExercicio2) / sizeof(listaExercicio2[0]);

 cout << ">> Lista Exercicio 2: ";
 imprimirLista(listaExercicio2, tamExercicio2);

 buildMinHeap(listaExercicio2, tamExercicio2);
 cout << ">> Build min heap: ";
 imprimirLista(listaExercicio2, tamExercicio2);

 heapExtractMin(listaExercicio2, &tamExercicio2);
 cout << ">> Heap extract min: ";
 imprimirLista(listaExercicio2, tamExercicio2);

 // Alterando valor da última chave de 16 para 1
 heapDecreaseKey(listaExercicio2, tamExercicio2 - 1, 1, tamExercicio2);
 cout << ">> Heap decrease key: ";
 imprimirLista(listaExercicio2, tamExercicio2);

 // Inserindo valor 0!
 minHeapInsert(listaExercicio2, 0, &tamExercicio2);
 cout << ">> Min heap insert: ";
 imprimirLista(listaExercicio2, tamExercicio2);

 return 0;
}