'''
 Exemplo do uso de pilha.

 Prof. Me. Orlando Saraiva Jr
 Criado em : 05/04/2018
 '''


class Pilha:
    """ Classe Pilha, representando uma pilha """
    def __init__(self):
        """No construtor, cria-se uma lista """
        self._data = []

    def __len__(self):
        """Retorna o tamanho da pilha"""
        return len(self._data)

    def is_empty(self):
        """Checa se a pilha está vazia"""
        return len(self._data) == 0

    def push(self, e):
        """Adiciona um elemento a pilha"""
        self._data.append(e)

    def desempilhar(self):
        """Adiciona um elemento a pilha"""
        if self.is_empty():
            print('Pilha vazia')
        else:
            return self._data.pop()

    def __str__(self):
        return str(self._data)


if __name__ == '__main__':
    q = Pilha()
    q.push(1)
    q.push(2)
    q.push(3)
    print(q)

    print(q)
    print(q.desempilhar())

    print(q)
    print(q.desempilhar())
    print(q)
    print(q.desempilhar())
    print(q.desempilhar())
