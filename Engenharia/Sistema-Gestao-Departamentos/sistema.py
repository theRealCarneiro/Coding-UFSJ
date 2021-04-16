import subprocess
from controller.departamento import DepartamentoController
from controller.documento import DocumentoController
from model.creator.creator import Creator
from view.documento import DocumentoView
import os
import sys


def getDocumento(caminho, data):
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

    return caminho, data


def buscaDocumento(opt, valor):
    nome = None
    caminho = None
    tipo = None
    data = None

    if opt == "Nome":
        nome = valor
    elif opt == "Caminho":
        caminho = valor
    elif opt == "Tipo":
        tipo = valor
    elif opt == "Data":
        data = valor

    return DocumentoController.readDocumento(nome, caminho, tipo, data)


def getEntrada():
    opt = None

    print("Selecione a opcao:")
    print("1) Cadastrar documento")
    print("2) Visualizar documento")
    print("0) Sair")
    opt = int(input())

    while opt not in [0, 1, 2]:
        print("Entrada invalida!! Digite outra")
        opt = int(input())

    return opt


def generateJanela(texto):
    sys.stdout.flush()
    os.system('./view/interface.sh --show \'' + texto + '\'')


def startJanela():
    sys.stdout.flush()
    MyOut = subprocess.Popen(['./view/interface.sh'], 
        stdout=subprocess.PIPE, 
        stderr=subprocess.STDOUT)
    stdout,stderr = MyOut.communicate()
    return stdout.decode().rstrip().split('#')


def main():
    departamento = Creator().getDepartamento()

    while True:
        texto = ''
        info = startJanela()

        if (info[0] == "Sair"):
            quit()

        if (info[0] == "CADASTRO"):
            try:
                documento = DocumentoController.getDocumento(info[1], info[2], info[3], info[4])
                DepartamentoController.addDocumento(departamento, documento)
                texto = "Cadastrado com sucesso"
            except Exception as e:
                texto = str(e)

        if (info[0] == "BUSCA"):
            documento_busca = buscaDocumento(info[1],info[2])
            documentos = DepartamentoController.readDocumento(departamento, documento_busca)
            texto = DocumentoView.toString(documentos)

        generateJanela(texto)


if __name__ == "__main__":
    main()
