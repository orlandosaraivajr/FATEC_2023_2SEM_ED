/*
Ponteiro - Passagem por passagem por referência.

Prof. Me. Orlando Saraiva Jr
Adaptado de Deitel & Associates, Inc. and               *
Pearson Education, Inc. All Rights Reserved.
*/

#include <iostream>

using namespace std;

void cubeByReference( int *nPtr ); /* Protótipo */

int main(int argc, char *argv[]){
   int numero = 5;

   cout << "O valor original é " << numero << endl;

   /* Passa o endereço para cubeByReference */
   cubeByReference( &numero );

   cout << "O novo valor é " << numero << endl;

   return 0;
}

void cubeByReference( int *nPtr ) {
   *nPtr = *nPtr * *nPtr * *nPtr;
}
