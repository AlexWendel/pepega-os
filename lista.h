// lista.h - implementacao de lista encadeada

#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

#define fmt "%d "
//#define fmt "%c "

typedef fila Item;
//typedef char Item;
/*typedef struct {
	char nome[81];
	char matricula[8];
	char turma;
	float p1;
	float p2;
	float p3;
} Item; */

typedef struct no {
   Item item;          
   struct no *prox; 
   int position;
} *Lista;

Lista no(Item x, Lista p, int position) {
   Lista n = (struct no*) malloc(sizeof(struct no));
   n->item = x;
   n->prox = p;
   n->position = position;
   return n;
}


// funções novas inicio
Lista new_priotity(Item item,int position, Lista n){
    if(n == NULL) return NULL;
    if(n->position == new_priotity) retun n;
    else if(n->position < new_priotity){
        if(n->prox == NULL){
        }
    }
}

Item searchP(int position, Lista n){
    if(n == NULL) return NULL;
    if(n->position == position) return n->item;
    else searchP(position, n->prox);
}

Item searchI(Item item, Lista n){
    if(n == NULL) return NULL;
    if(n->item == item) return n->position;
    else searchP(item, n->prox);
}

Item search_high_P(Lista n){
    if(n == NULL) return NULL;
    if(n->prox == NULL) return n->item;
    else search_high_P(n->prox);
}

// funções novas fim

void exibe(Lista L) {
   while( L != NULL ) {
      printf(fmt,L->item);
      L = L->prox;
   }
}

void anexa(Lista *A, Lista B) {
   if( B == NULL ) return;
   while( *A != NULL ) A = &(*A)->prox;
   *A = B;
}

void destroi(Lista *L) {
   while( *L != NULL ) {
      Lista n = *L;
      *L = n->prox;
      free(n);
   }
}

int tam(Lista L) {
   if( L == NULL ) return 0;
   return 1 + tam(L->prox);
}

int pert(Item x, Lista L) {
   if( L == NULL ) return 0;
   if( x == L->item ) return 1;    
   return pert(x,L->prox);
}

Lista clone(Lista L) {
   if( L == NULL ) return NULL;
   return no(L->item,clone(L->prox));
}

void exibe_inv(Lista L) {
   if( L == NULL ) return;
   exibe_inv(L->prox);
   printf(fmt,L->item);
}
