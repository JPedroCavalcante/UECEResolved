#include "Pilha.h"

void init(Pilha *P){
P->topo = -1;
}

void push(Pilha *P, int N){
if(P->topo != MAX_PILHA - 1)
P->vet[++(P->topo)]=N;
}

int pop(Pilha *P){
if(P->topo!=-1)
return P->vet[P->topo--];
return 0;
}

int peek(Pilha *P){
if(P->topo!=-1)
return P->vet[P->topo];
return 0;
}

bool full(Pilha *P){
return P->topo == MAX_PILHA -1;
}

bool empty(Pilha *P){
return P->topo == -1;
}
