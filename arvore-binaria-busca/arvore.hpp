#include <stdio.h>
#include <stdlib.h>

typedef struct arvore
{
  int info;
  struct arvore *esq;
  struct arvore *dir;
} Arvore;

int buscar(Arvore *a, int v);

Arvore *inserir(Arvore *a, int v);

Arvore *remover(Arvore *a, int v);
