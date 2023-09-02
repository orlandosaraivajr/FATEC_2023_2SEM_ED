/*
Ponteiro - o primeiro exemplo

Prof. Me. Orlando Saraiva Jr
Adaptado de Deitel & Associates, Inc. and               *
Pearson Education, Inc. All Rights Reserved.
*/
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
   int a;
   int *aPtr;

   a = 7;
   aPtr = &a;

   cout << "O endereco de a eh " << &a << endl;
   cout << "O valor de aPtr eh " << aPtr ;
   cout << endl;

   cout << "O valor de a eh " << a << endl;
   cout << "O valor de *aPtr eh " << *aPtr ;
   cout << endl;

   cout << "Mostrando que * e & são complementares um do outro ";
   cout << &*aPtr << "  " <<  *&aPtr;
   cout << endl;

   cout << "Cuidado com a legibilidade: ";
   cout << *&*aPtr << "  " <<  **&aPtr;
   cout << endl;
   return 0;
}
