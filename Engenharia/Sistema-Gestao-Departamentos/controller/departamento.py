class DepartamentoController:

    def __init__(self):
        pass

    @staticmethod
    def addDocumento(departamento, documento):
        documentos = departamento.getDocumentos()
        documentos.append(documento)
        departamento.setDocumentos(documentos)

    @staticmethod
    def readDocumento(departamento, documento):

        docs = []

        for doc in departamento.getDocumentos():
            if (documento.getNome() == doc.getNome() or
                    documento.getCaminho() == doc.getCaminho() or
                    documento.getTipo() == doc.getTipo() or
                    documento.getData() == doc.getData()):
                docs.append(doc)

        return docs
