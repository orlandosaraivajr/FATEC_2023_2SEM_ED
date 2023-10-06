/*
 * Exemplo do uso de fila com uso de vetor.
 *
 * Neste exemplo, faço uso de variáveis estáticas.
 *
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 28/04/2018
 * Alterado em : 20/09/2018
 * Alterado em : 05/10/2023
 */
 
 #include <iostream>

using namespace std;

struct Item {
    int     valor;
};

static Item *fila;
static int N = 10;
static int inicio, fim;

void inicializar() {
	fila = new Item[N];
	inicio = N - 1;
	fim = 0;
}

void inserir(Item item) {
	fila[fim++] = item;
	fim = fim % N;
}

Item remover() {
	inicio = (inicio + 1) % N;
	return fila[inicio];
}

void imprime_fila() {
    int x;
	for (x = 0; x < N ; x++)
		cout << fila[x].valor <<" ";
    cout << endl;

}

int main(void) {
	Item item;
    int x;

    N = 20;

	inicializar();
    imprime_fila();
    for ( x = 0; x<N;x++) {
        item.valor = x + 1;
        inserir(item);
    }
    imprime_fila();

    for ( x = 0; x<N/2 ; x++) {
        cout << "Próximo da fila: " <<  remover().valor << endl;
    }
    item.valor = 46;
    inserir(item);
    item.valor = 45;
    inserir(item);
    item.valor = 47;
    inserir(item);
    imprime_fila();

    delete fila;
	return 0;
}
