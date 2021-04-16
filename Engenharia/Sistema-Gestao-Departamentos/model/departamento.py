class Departamento:

    def __init__(self):
        self.__nome = "Departamento tal da UFSJ"
        self.__cursos = []
        self.__funcionarios = []
        self.__documentos = []

    __instancia = None

    # Singleton
    def getInstancia(self):
        if self.__instancia is None:
            self.__instancia = Departamento()
        return self.__instancia

    def getNome(self):
        return self.__nome

    def setNome(self, nome):
        self.__nome = nome

    def getCursos(self):
        return self.__cursos

    def setCursos(self, cursos):
        self.__cursos = cursos

    def getFuncionarios(self):
        return self.__funcionarios

    def setFuncionarios(self, funcionarios):
        self.__funcionarios = funcionarios

    def getDocumentos(self):
        return self.__documentos

    def setDocumentos(self, documentos):
        self.__documentos = documentos
