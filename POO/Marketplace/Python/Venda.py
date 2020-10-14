class Venda:
    from Cliente import *
    from Produto import *
    def __int__(self, Carrinho, Cliente):
        self.produto = carrinho
        self.cliente = cliente

    def printaVenda(self):
        print(self.Cliente.nome)
        for i in self.carrinho:
            print self.carrinho.id[i]
            print self.carrinho.nome[i]
            print self.carrinho.valor[i]
