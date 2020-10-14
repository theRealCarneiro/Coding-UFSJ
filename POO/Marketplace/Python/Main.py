class Produto:
    def __init__(self, id, nome, valor):
        self.id = id
        self.nome = nome
        self.valor = valor

class Cliente:
    def __init__(self, nome, cpf):
        self.nome = nome
        self.cpf = cpf

class Venda:
    def __init__(self, Carrinho, Cliente):
        self.Carrinho = Carrinho
        self.Cliente = Cliente

    def printaVenda(self):
        print(self.Cliente.nome)
        for i in self.Carrinho:
            print self.Carrinho[i].id
            print self.Carrinho[i].nome
            print self.Carrinho[i].valor

cliente = Cliente("Ze", 13)
queijo = Produto("1", "Queijo", "2")
carne = Produto("2", "Carne", "4")
carrinho = [queijo, carne]
venda = Venda(carrinho, cliente)
venda.printaVenda()
