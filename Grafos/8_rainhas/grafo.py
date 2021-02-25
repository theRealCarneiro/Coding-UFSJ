from networkx import *
from math import *
import chess

def generate_grafo():
    grafo = Graph()
    for i in range(0, 64):
        grafo.add_node(i)
    grafo = set_arestas(grafo)
    return grafo

def set_arestas(grafo): 
    a = list(grafo.nodes)
    b = list(grafo.nodes)
    for verticeA in a:
        for verticeB in b:
            if pode_colocar(verticeA, verticeB) == True:
                grafo.add_edge(verticeA, verticeB)  
        b.remove(verticeA)
    return grafo

def pode_colocar(verticeA,verticeB):
    if verticeA == verticeB:
        return False
    lista = ["linha","coluna","diagonal"]
    for i in lista:
        if verifica(i,verticeA,verticeB) == True:
            return False
    return True

def verifica(opcao, verticeA, verticeB):
    if(opcao == "linha"):
        if floor(verticeA / 8) == floor(verticeB / 8):
            return True
        return False

    elif(opcao == "coluna"):
        i = verticeA
        while(i <= 63):
            if i == verticeB:
                return True
            i+=8
        return False

    elif(opcao == "diagonal"):
        if floor(verticeA / 8) != 7 and verifica("coluna", verticeA, 63) == False:
            i = verticeA + 9
            while(i <= 63):
                if i == verticeB:
                    return True
                if verifica("coluna", i, 63) == True or verifica("linha", i, 63) == True:
                    break
                i += 9

        if floor(verticeA / 8) != 7 and verifica("coluna", verticeA, 56) == False:
            i = verticeA + 7
            while(i <= 63):
                if i == verticeB:
                    return True
                if verifica("coluna", i, 56) == True or verifica("linha", i, 63) == True:
                    break
                i += 7

        return False


def encontra_cliques(grafo):
    if len(grafo) == 0:
        return

    adj = {u: {v for v in grafo[u] if v != u} for u in grafo}
    Q = [None]

    sub_grafo = set(grafo)
    cand = set(grafo)
    u = max(sub_grafo, key=lambda u: len(cand & adj[u]))
    ext_u = cand - adj[u]
    pilha = []

    try:
        while True:
            if ext_u:
                q = ext_u.pop()
                cand.remove(q)
                Q[-1] = q
                adj_q = adj[q]
                sub_grafo_q = sub_grafo & adj_q
                if not sub_grafo_q:
                    yield Q[:]
                else:
                    cand_q = cand & adj_q
                    if cand_q:
                        pilha.append((sub_grafo, cand, ext_u))
                        Q.append(None)
                        sub_grafo = sub_grafo_q
                        cand = cand_q
                        u = max(sub_grafo, key=lambda u: len(cand & adj[u]))
                        ext_u = cand - adj[u]
            else:
                Q.pop()
                sub_grafo, cand, ext_u = pilha.pop()
    except IndexError:
        pass

grafo = generate_grafo()
tabuleiro = chess.Board()

j = 0
for i in encontra_cliques(grafo):
    tabuleiro.clear()
    if len(i) == 8:
        for element in i:
            tabuleiro.set_piece_at(element,chess.Piece(5, True))
        j += 1
        print("Solução " + str(j))
        print(tabuleiro.unicode())
        print('\n')
