#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

typedef struct arvb ArvB;

struct arvb{
  int n;
  ArvB* e;
  ArvB* d;
};

ArvB* criavazia(){
  ArvB* a = NULL;
  return a;
}

void imprimeArv (ArvB* a){
    printf("< ");
    if (a!=NULL){
      printf("%d ",a->n);
      imprimeArv (a->e);
      imprimeArv (a->d);
    }
    printf(">");
}

void imprimeNo(ArvB* a){
  if (a == NULL) return;
  printf("%d ",a->n);
}

void imprimeOrd(ArvB* a){
  if (a==NULL) return;
  imprimeOrd(a->e);
  imprimeNo(a);
  imprimeOrd(a->d);
}

ArvB* insere(ArvB* arv, int n){
  if (arv==NULL){
    ArvB* nova = (ArvB*)malloc(sizeof(ArvB));
    nova->n = n;
    nova->d = nova->e = NULL;
    arv = nova;
    return nova;
  }
  if (arv->n > n) arv->e = insere(arv->e,n);
  else arv->d = insere(arv->d,n);
  return arv;
}

ArvB* retira(ArvB* arv, int n){
  if(arv==NULL) return NULL;
  if (arv->n > n) arv->e = retira(arv->e,n);
  if (arv->n < n) arv->d = retira(arv->d,n);
  if (arv->n == n){
    if ((arv->d == NULL)&&(arv->e == NULL)){
      free(arv);
      arv = NULL;
    }else{
      if (arv->d == NULL){
        ArvB* t = arv;
        arv = arv->e;
        free(t);
      }else{
        if (arv->e == NULL){
          ArvB* t = arv;
          arv = arv->d;
          free(t);
        }else{
          ArvB* q = arv->e;
          while(q->d != NULL){
            q = q->d;
          }
          arv->n = q->n;
          q->n = n;
          arv->e = retira(arv->e,n);
        }
      }
    }
  }
  return arv;
}

ArvB* busca(ArvB* a, int n){
  if (a == NULL) return NULL;
  if (a->n == n) return a;
  if (a->n > n) return busca(a->e, n);
  else return busca(a->d, n);
}

ArvB* libera(ArvB* a){
  if (a == NULL) return NULL;
  libera(a->e);
  libera(a->d);
  free(a);
  return NULL;
}
