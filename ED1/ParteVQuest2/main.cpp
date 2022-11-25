#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"
using namespace std;

int main(){

    Pilha P;
    char expressao[100];
    init(&P);

    scanf(" %s", expressao);

    for(int i=0;i<strlen(expressao); i++){
        if(expressao[i]>='0'&&expressao[i]<='9')
        push(&P, expressao[i]-'0');
        else{
            switch(expressao[i]){
                case"+": 
                    push(&P, pop(&P) + pop(&P)); 
                    break;
                case"-": 
                    push(&P, pop(&P) - pop(&P)); 
                    break;
                case"*": 
                    push(&P, pop(&P) * pop(&P)); 
                    break;
                case"/": 
                    push(&P, pop(&P) / pop(&P));
                    break;
            }
        }
    printf("%d\n", peek(&P));
    }
    return 0;
}
