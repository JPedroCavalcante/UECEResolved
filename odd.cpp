#include <iostream>
using namespace std;

int main(){
    int X;

    cin >> X;
    if (X>=1 && X<=1000)
    {
    
    if ((X%2)==0)
    {
        X+1;
        for (int i = 1; i<=X ; i = i+2)
        {
            cout << i << endl;
        }
        
    }
    else{
        for (int i = 1; i<=X; i = i+2)
        {

            cout << i << endl;
        }
    }
    }


    return 0;
}