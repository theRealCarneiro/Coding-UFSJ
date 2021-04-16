class Documento:

    def __init__(self, nome, caminho, tipo, data):
        self.__nome = nome
        self.__caminho = caminho
        self.__tipo = tipo
        self.__data = data

    def getNome(self):
        return self.__nome

    def setNome(self, nome):
        self.__nome = nome

    def getCaminho(self):
        return self.__caminho

    def setCaminho(self, caminho):
        set.__caminho = caminho

    def getTipo(self):
        return self.__tipo

    def setTipo(self, tipo):
        set.__tipo = tipo

    def getData(self):
        return self.__data

    def setData(self, data):
        self.__data = data
