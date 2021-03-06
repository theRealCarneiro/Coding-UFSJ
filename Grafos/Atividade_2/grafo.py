from networkx import *
grafo = read_gml("dolphins.gml")
caminho_minimo=shortest_path(grafo)
centroide = distance_measures.barycenter(grafo)
centro = distance_measures.center(grafo)
diametro = distance_measures.diameter(grafo)
excentricidade = distance_measures.eccentricity(grafo)
raio = distance_measures.radius(grafo)
periferia = distance_measures.periphery(grafo)
#print(caminho_minimo)
print("excentricidade: ", excentricidade)
print("raio: ", raio)
print("diametro: ", diametro)
print("centroide: ", centroide)
print("centro: ", centro)
print("periferia: ", periferia)
