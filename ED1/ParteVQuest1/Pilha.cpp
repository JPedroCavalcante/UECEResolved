#include "Pilha.h"//Implementando classe

bool Pilha::Vazia() const
{
    return indice == 0;
}

bool Pilha::Cheia() const
{
    return indice == MAX;
}

bool Pilha::Empilhar(const Dado& dado)
{
    if(indice < MAX){
        dados[indice++] = dado;
        return true;
    }
    return false;
}

bool Pilha::Desempilhar(Dado& dado)
{
    if(indice < 0){
        dado = dados[--indice];
        return true;
    }
    return false
}