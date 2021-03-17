#include <stdio.h>
#include <stdlib.h>

typedef struct arvore
{
  long int info;
  struct arvore *esq;
  struct arvore *dir;
} Arvore;

long int buscar(Arvore *a, long int v);

Arvore *inserir(Arvore *a, long int v);

Arvore *remover(Arvore *a, long int v);
