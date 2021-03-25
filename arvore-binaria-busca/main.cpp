#include <iostream>
#include <ctime>
#include "./arvore.hpp"

using namespace std;

void mark(Arvore *arv)
{
  cout << "<";
  if (arv)
  {
    cout << arv->info;
    mark(arv->esq);
    mark(arv->dir);
  }
  cout << ">";
}

void imprimir_in_ordem(Arvore *a)
{
  if (a != NULL)
  {
    imprimir_in_ordem(a->esq);
    cout << a->info;
    imprimir_in_ordem(a->dir);
  }
}

void imprime_decrescente(Arvore *arv)
{
  if (arv != NULL)
  {
    imprime_decrescente(arv->dir);
    cout << arv->info << ", ";
    imprime_decrescente(arv->esq);
  }
}

void ordena_arvore(Arvore *arv)
{
  if (arv != NULL)
  {
    Arvore *tmp;
    if (arv->esq->info > arv->dir->info)
    {
      tmp = arv->dir;
      arv->dir = arv->esq;
      arv->esq = tmp;
    }
    ordena_arvore(arv->dir);
    ordena_arvore(arv->esq);
  }
}

long int min(Arvore *arv)
{
  long int minimo = NULL, minLeft = NULL, minRight = NULL;

  if (arv != NULL)
  {
    minimo = arv->info;
    if (arv->esq != NULL)
    {
      minLeft = min(arv->esq);
    }
    if (arv->dir != NULL)
    {
      minRight = min(arv->dir);
    }
  }

  if (minRight != NULL && minLeft != NULL)
    minimo = (minimo <= minLeft) && (minimo <= minRight)
                 ? minimo
                 : (minLeft <= minRight
                        ? minLeft
                        : minRight);
  else if (minRight != NULL)
    minimo = minimo <= minRight
                 ? minimo
                 : minRight;
  else if (minLeft != NULL)
    minimo = minimo <= minLeft
                 ? minimo
                 : minLeft;

  return minimo;
}

long int max(Arvore *arv)
{
  long int maximo = NULL, maxLeft = NULL, maxRight = NULL;

  if (arv != NULL)
  {
    maximo = arv->info;
    if (arv->esq != NULL)
    {
      maxLeft = max(arv->esq);
    }
    if (arv->dir != NULL)
    {
      maxRight = max(arv->dir);
    }
  }

  if (maxRight != NULL && maxLeft != NULL)
    maximo = (maximo >= maxLeft) && (maximo >= maxRight)
                 ? maximo
                 : (maxLeft >= maxRight
                        ? maxLeft
                        : maxRight);
  else if (maxRight != NULL)
    maximo = maximo >= maxRight
                 ? maximo
                 : maxRight;
  else if (maxLeft != NULL)
    maximo = maximo >= maxLeft
                 ? maximo
                 : maxLeft;

  return maximo;
}

void exer1()
{
  clock_t start, end, duration;

  Arvore *arv = NULL;

  //Inserir 100000 numeros numa arvore, em ordem.
  start = clock();
  for (long int i = 0; i < 100000; i++)
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
  for (long int i = 0; i < 100000; i++)
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

void exer3()
{

  Arvore *arv = NULL;

  //Funcao min e max.
  cout << "Preenchendo arvore binaria de busca..."
       << endl
       << endl;

  // int test[10] = {52, 31, 63, 42, 71, 11, 24, 85, 90, 1};

  for (long int i = 0; i < 100000; i++)
  {
    srand(time(NULL));
    (rand() % 1000000) + 1;
    arv = inserir(arv, i);
    // arv = inserir(arv, test[i]);
  }

  buscar(arv, 2000000);
  cout << "buscando min: " << min(arv) << endl;
  cout << "buscando max: " << max(arv) << endl;
}

void exer4()
{

  Arvore *arv = NULL;

  //Funcao recursiva, imprimir descrescente
  cout << "Preenchendo arvore binaria de busca..."
       << endl
       << endl;

  int test[10] = {52, 31, 63, 42, 71, 11, 24, 85, 90, 1};

  for (long int i = 0; i < 10; i++)
  {
    arv = inserir(arv, test[i]);
  }

  cout << "Descrescente via funcao recursiva: " << endl;
  imprime_decrescente(arv);
}

void exer5()
{

  //Funcao que ordena uma arvore (esquerda = menor, direita = maior)
  cout << "Preenchendo arvore binaria..."
       << endl
       << endl;

  Arvore *arv = constroi_arv(10,
                             constroi_arv(13,
                                          NULL,
                                          constroi_arv(5, NULL, NULL)),
                             constroi_arv(3,
                                          constroi_arv(18, NULL, NULL),
                                          constroi_arv(4, NULL, NULL)));

  cout << "Ordena arvore binaria via funcao recursiva: " << endl;
  mark(arv);

  cout << endl
       << endl;

  ordena_arvore(arv);

  mark(arv);
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

  cout << "Exercicio 3:" << endl;
  exer3();
  cout << endl
       << endl;

  cout << "Exercicio 4:" << endl;
  exer4();
  cout << endl
       << endl;

  cout << "Exercicio 5:" << endl;
  exer5();
  cout << endl
       << endl;
}
