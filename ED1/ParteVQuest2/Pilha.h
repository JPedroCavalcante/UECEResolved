#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#define MAX_PILHA 1000

typedef struct Pilha{
int vet[MAX_PILHA];
int topo;
}Pilha;

void init(Pilha *P);
void push(Pilha *P, int N);
int pop(Pilha *P);
int peek(Pilha *P);
bool full(Pilha *P);
bool empty(Pilha *P);


#endif // PILHA_H_INCLUDED
