#include <iostream>

using namespace std;

int main(){
    int nota = 0;
    char resposta;

    system("clear||cls");
    
    cin >> nota;

    if (nota<=100 && nota>=86)
    {
        cout <<  "A" << endl;
    }

    else if (nota<=85 && nota>=61)
    {
        cout << "B" << endl;
    }

    else if (nota<=60 && nota>=36)
    {
        cout << "C" << endl;
    }

    else if (nota<=35 && nota>=1)
    {
        cout << "D" << endl;
    }

    else if (nota==0)
    {
        cout << "E" << endl;
    }
    
    return 0;
}