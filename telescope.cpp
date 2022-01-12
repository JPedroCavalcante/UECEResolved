#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int A, C, N, F, B;
    A = 0;
    C = 1;
    N = 0;
    F = 0;
    B = 0;
    
    scanf("%d", &A);
    scanf("%d", &N);

    do
    {
      scanf("%d", &F);
      if(F*A>=40000000)
         {
             B = B+1;
         }
      C = C+1;
    } while (C <= N);
    printf("%d\n", B);

    return 0;

}