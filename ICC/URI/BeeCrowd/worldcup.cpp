#include <stdio.h>
int main(){
    int T, N, C, P, result, pointstotal;
    char name[11];
    P = 0;
    T = 0;
    N = 0;
    pointstotal = 0;
    C = 1;
    // P = Pontos de um time, T = Times, N = Número de partidas, C = Contador, Pointstotal = pontos no total, result = resultado total
    do{scanf("%d %d",&T, &N);          

        if(T<2 || T>200){
        break;
        
        }

             do{

              scanf("%10s %d",name, &P);
              
              pointstotal=pointstotal+P;
  
              C=C+1;
             }while (C<=T);
                     
        C=1;
        result = 3*N-pointstotal;
        printf("%d\n", result);
        result = 0;
        pointstotal = 0;
        }while (T!=0 && N!=0);
    
    return 0;
}