from model.creator.creator import Creator
from datetime import date


class DocumentoController:

    def __init__(self):
        pass

    @staticmethod
    def getDocumento(nome, caminho, tipo, data):
        try:
            arquivo = open(caminho, "r")
        except FileNotFoundError: 
            raise FileNotFoundError('Arquivo não encontrado')

        try:
            dia, mes, ano = map(int, data.split('/'))
            data = date(ano, mes, dia)
        except ValueError:
            raise ValueError("Formato da data inválido")
        if data > date.today():
            raise ValueError("Data inválida")

        return Creator().newDocumento(nome, caminho, tipo, data)

    @staticmethod
    def readDocumento(nome=None, caminho=None, tipo=None, data=None):
        return Creator().newDocumento(nome, caminho, tipo, data)
