#ifndef ABB_H_
#define ABB_H_


typedef struct arvb ArvB;


ArvB* criavazia();

void imprimeArv (ArvB* a);

void imprimeNo(ArvB* a);

void imprimeOrd(ArvB* a);

ArvB* insere(ArvB* arv, int n);

ArvB* retira(ArvB* a, int n);

ArvB* busca(ArvB* a, int n);

ArvB* libera(ArvB* a);

#endif
