#include <iostream>

using namespace std;

int fatorial(int n) {
    if ((n==1) || (n==0)){
        return 1;
    } else {
        return fatorial(n-1)*n;
    }
}

int main () {
    int n;
    cout << "Informe o número que deseja obter o fatorial:" << endl;
    cin >> n;
    cout << "O fatorial de " << n << " eh " << fatorial(n) << endl;
}
