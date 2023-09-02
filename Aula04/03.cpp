/*
Ponteiro Vazio - .

Prof. Me. Orlando Saraiva Jr
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    int a = 20;
    float b = 4.5;
    string c = "Oi Mundo";
    void *ptr;

    ptr=&a;
    cout << "O valor de *ptr eh " << *( (int*) ptr) << endl;

    ptr=&b;
    cout << "O valor de *ptr eh " << *( (float*) ptr) << endl;

    ptr=&c;
    cout << "O valor de *ptr eh " << *( (string*) ptr) << endl;
    return 0;
}
