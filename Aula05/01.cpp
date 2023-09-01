/*
Ponteiro - exemplo em C++

Orlando Saraiva Jr
*/
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    int numero_1;
    int* numero_2;
    cout << " Digite um numero " << endl;
    cin >> numero_1;
    numero_2 = &numero_1;
    cout << " Número digitado " << *numero_2 <<  endl;

    /* Alocação no heap */
    numero_2 = new(int);
    *numero_2 = 10;
    cout << " Alocado no heap " << *numero_2 <<  endl;
    delete(numero_2);

    numero_2 = new(int);
    *numero_2 = 15;
    cout << " Alocado no heap 2 " << *numero_2 <<  endl;
    delete(numero_2);

    cout << " Digite um numero " << endl;
    cin >> *numero_2;
    cout << " Número digitado " << *numero_2 <<  endl;
    return 0;
}
