'''
 Exemplo do uso de fila.

 Prof. Me. Orlando Saraiva Jr
 Criado em : 28/04/2018
 '''


class Fila:
    """ Classe Fila, representando uma fila """
    def __init__(self):
        """No construtor, cria-se uma lista """
        self._data = []

    def __len__(self):
        """Retorna o tamanho da fila"""
        return len(self._data)

    def is_empty(self):
        """Checa se a fila está vazia"""
        return len(self._data) == 0

    def insere(self, e):
        """Adiciona um elemento a fila"""
        self._data.insert(0, e)

    def remove(self):
        """Remove um elemento da fila"""
        if self.is_empty():
            print('Fila vazia')
        else:
            return self._data.remove(self._data[-1])

    def __str__(self):
        return str(self._data)


if __name__ == '__main__':
    q = Fila()
    q.insere(1)
    q.insere(2)
    q.insere(3)
    print(q)

    print(q)
    print(q.remove())

    print(q)
    print(q.remove())
    print(q)
    print(q.remove())
    print(q.remove())
