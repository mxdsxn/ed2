#include <iostream>
#include <ctime>
#include "./arvore.hpp"

using namespace std;

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
  clock_t start, end, duration;

  Arvore *arv = NULL;

  //Inserir 100000 numeros numa arvore, em ordem.
  start = clock();
  for (int i = 0; i < 100000; i++)
  {
    arv = inserir(arv, i);
  }
  end = clock();
  duration = (((float)end - start) / CLOCKS_PER_SEC);
  cout << "Inserir 100000 numeros numa arvore, em ordem." << endl
       << "duracao para preencher a arvore : " << duration << " s." << endl;

  //Buscar numero nao existente na arvore.
  start = clock();
  buscar(arv, 100000);
  end = clock();
  duration = (((float)end - start));
  cout << "duracao para busca de elemento que nao existe: " << duration << "ms." << endl;
}

void exer2()
{
  clock_t start, end, duration;

  Arvore *arv = NULL;

  //Inserir 100000 numeros numa arvore, aleatorios.
  start = clock();
  for (int i = 0; i < 100000; i++)
  {
    srand(time(NULL));
    (rand() % 1000000) + 1;
    arv = inserir(arv, i);
  }
  end = clock();
  duration = (((float)end - start) / CLOCKS_PER_SEC);
  cout << "Inserir 100000 numeros numa arvore, aleatorios." << endl
       << "duracao para preencher a arvore: " << duration << "s." << endl;

  //Buscar numero nao existente na arvore.
  start = clock();
  buscar(arv, 2000000);
  end = clock();
  duration = (((float)end - start));
  cout << "duracao para busca de elemento que nao existe: " << duration << "ms." << endl;
}

int main()
{
  cout << "Exercicio 1:" << endl;
  exer1();
  cout << endl
       << endl;

  cout << "Exercicio 2:" << endl;
  exer2();
  cout << endl
       << endl;
}
