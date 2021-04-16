from model.documento import Documento
from model.departamento import Departamento


class Creator:

    def __init__(self):
        pass

    def getDepartamento(self):
        departamento = Departamento().getInstancia()
        return departamento

    def newDocumento(self, nome, caminho, tipo, data):
        documento = Documento(nome, caminho, tipo, data)
        return documento
