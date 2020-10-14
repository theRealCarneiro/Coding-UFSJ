class Produto:
    def __init__(self, id, nome, valor):
        self.id = id
        self.nome = nome
        self.valor = valor

class Carrinho(Produto):
    def __init__(self, Produto):
        self.Produto = Produto

    
