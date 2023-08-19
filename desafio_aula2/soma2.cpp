#include <iostream>

using namespace std;

int soma( int n ) {
    if (n==1) {
        return 1;
    } else {
        return soma(n-1) + n;
    }
}

int main(int argc, char *argv[]){
   int numero;
   cout << "Digite um número \n";
   cin >> numero;
   cout << soma(numero) << "\n";
   return 0;
}
