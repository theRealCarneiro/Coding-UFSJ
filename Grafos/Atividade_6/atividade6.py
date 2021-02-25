class Aresta(object):
    def __init__(self, origem, destino, capacidade):
        self.origem = origem
        self. destino = destino
        self.capacidade = capacidade

    def __repr__(self):
        return "%s -> %s : %d" % (self.origem, self.destino, self.capacidade)

class Fluxo(object):

    def __init__(self):
        self.aresta = {}
        self.adjacentes = {}

    def add_aresta(self, origem, destino, capacidade):
        if origem == destino:
            raise ValueError("Origem nao pode ser o destino")

        vertice = Aresta(origem, destino, capacidade)
        rvertice = Aresta(origem, destino, capacidade)
        self.aresta[vertice] = 0
        self.aresta[rvertice] = 0

        if origem not in self.adjacentes:
            self.adjacentes[origem] = []
        if destino not in self.adjacentes:
            self.adjacentes[destino] = []

        self.adjacentes[origem].append(vertice)
        self.adjacentes[destino].append(rvertice)

    def caminho_valido(self, origem, destino, caminho):

        if origem == destino:
            return caminho
        for vertice in self.adjacentes[origem]:
            if vertice not in caminho:
                if vertice.capacidade - self.aresta[vertice] > 0:
                    return self.caminho_valido(vertice.destino, destino, caminho + [vertice])

        return None

    def fluxo_maximo(self, origem, destino):

        caminho = self.caminho_valido(origem, destino, [])

        while (caminho):
            fluxo_maximo = min([vertice.capacidade for vertice in caminho])
            for vertice in caminho:
                self.aresta[vertice] += fluxo_maximo
            caminho = self.caminho_valido(origem, destino, [])

        return  sum([self.aresta[vertice] for vertice in self.adjacentes[origem]])

grafo = Fluxo()
arquivo = open('grafo.txt', 'r') 
linha_arquivo = arquivo.readline() 
while linha_arquivo:
    linha_arquivo = linha_arquivo.rstrip()
    lista_aresta = linha_arquivo.split(' ')
    origem = lista_aresta[0]
    destino = lista_aresta[1]
    fluxo = int(lista_aresta[2])
    grafo.add_aresta(origem, destino, fluxo);
    linha_arquivo = arquivo.readline() 

print (grafo.fluxo_maximo('s', 't'))
