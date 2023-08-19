#include <iostream>

using namespace std;

int soma( int n ) {
   int total = 0;
   for(int x = n; x>0; x--){
      total = total + x;
   }
   return total;
}

int main(int argc, char *argv[]){
   int numero;
   cout << "Digite um número \n";
   cin >> numero;
   cout << soma(numero) << "\n";
   return 0;
}
