#include "avl.h"

/*Função que devolve o maior entre dois números inteiros!*/
int maior (int esq, int dir) {
   return (esq > dir ? esq : dir);
}

/*----------------------*/
int altura (Arvore* a) {
   /*TERMINAR!!!!*/	
}

int atualizar_altura (Arvore *a) {
   /*TERMINAR!!!!*/	
}

/*----------------------*/
int balanceamento (Arvore *a) {
   /*TERMINAR!!!!*/
}

/*----------------------*/
Arvore* rotacao_simples_esq (Arvore* a) {
   /*TERMINAR!!!!*/
}

/*----------------------*/
Arvore* rotacao_simples_dir (Arvore* a) {
   /*TERMINAR!!!!*/
}

/*----------------------*/
Arvore* rotacao_dupla_esq (Arvore* a) {
   /*TERMINAR!!!!*/
}

/*----------------------*/
Arvore* rotacao_dupla_dir (Arvore* a) {
   /*TERMINAR!!!!*/
}

/*----------------------*/
Arvore* atualizar_fb_dir (Arvore *a) {
   /*TERMINAR!!!*/
}

/*----------------------*/
Arvore* atualizar_fb_esq (Arvore *a) {
   /*TERMINAR!!!*/
}

/*----------------------*/
Arvore* inserir (Arvore *a, char chave) {
   /*TERMINAR!!!*/
}

/*Função para remover um nó de uma árvore binária de busca balanceada!*/
Arvore* remover (Arvore *a, char chave) {
   if (a == NULL) {
      return NULL;
   }
   else {
      if (chave < a->chave) {
         a->esq = remover (a->esq, chave);
         a = atualizar_fb_dir (a);
      }
      else if (chave > a->chave) {
         a->dir = remover (a->dir, chave);
         a = atualizar_fb_esq (a);
      }
      else {
         if ((a->esq == NULL) && (a->dir == NULL)) {
            free (a);
            a = NULL;
         }
         else if (a->esq == NULL) {
            No *tmp = a;
            a = a->dir;
            free (tmp);
         }
         else if (a->dir == NULL) {
            No *tmp = a;
            a = a->esq;
            free (tmp);
         }
         else {
            No *tmp = a->esq;
            while (tmp->dir != NULL) {
               tmp = tmp->dir;
            }
            a->chave = tmp->chave; 
            tmp->chave = chave;
            a->esq = remover (a->esq, chave); 
            a = atualizar_fb_dir (a);
         }
      }
      return a; 
   }   
}

/*Função para imprimir os nós de uma árvore binária de acordo com um percurso in-ordem!*/
void imprimir_in_order (Arvore* a, int nivel) {
   if (a != NULL) {
      int i;
      for (i = 0; i < nivel; i++) {
         printf("      ");
      }
      printf("Chave: %c (altura: %d, fb: %+d) no nível: %d\n", a->chave, a->altura, balanceamento(a), nivel);
      imprimir_in_order (a->esq, nivel + 1);
      imprimir_in_order (a->dir, nivel + 1);
   }
}

