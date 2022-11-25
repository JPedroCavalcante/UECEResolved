//Exemplo prático
#include <iostream>
#include "Pilha.h"
using namespace std;

int main()
{
    Pilha pilha;

    pilha.Empilhar('S');
    pilha.Empilhar('O');
    pilha.Empilhar('R');
    pilha.Empilhar('I');
    pilha.Empilhar('E');
    pilha.Empilhar('R');
    pilha.Empilhar('G');
    pilha.Empilhar('E');
    pilha.Empilhar('N');


    while(!pilha.Vazia())
    {
        Dado i;
        pilha.Desempilhar(i);
        cout << i << endl;
    }
}

// Output
// N 
// E 
// G 
// R 
// E 
// I 
// R 
// O 
// S
