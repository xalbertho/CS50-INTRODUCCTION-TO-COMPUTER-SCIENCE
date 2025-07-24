
#include <iostream>

void contar(int limite);
using namespace std;

int main(){

    contar(10);
    return 0;
}

void contar(int limite){

    if(limite>1)
    {
        contar(limite-1);

        cout<<limite;
    }
}
