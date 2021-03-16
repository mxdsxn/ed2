#include <iostream>
#include <chrono>
#include <ctime>
#include "./arvore.hpp"
using namespace std;
using namespace std::chrono;

void imprimir_in_ordem(Arvore *a)
{
  if (a != NULL)
  {
    imprimir_in_ordem(a->esq);
    cout << a->info;
    imprimir_in_ordem(a->dir);
  }
}

void exer1()
{
  auto start = high_resolution_clock::now();

  Arvore *arv = NULL;

  for (int i = 0; i < 10; i++)
  {
    arv = inserir(arv, i);
  }

  auto end = high_resolution_clock::now();
  auto duration = (end - start).count() * 1000000000;

  cout << duration << endl;
  // imprimir_in_ordem(arv);
}
int main()
{
  cout << "Exercicio 1:" << endl;
  exer1();
}
