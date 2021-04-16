class DocumentoView:

    def __init__(self):
        pass

    @staticmethod
    def toString(documentos):
        docs = ''
        if len(documentos) == 0:
            return "Nenhum documento encontrado"
        for doc in documentos:
            # docs += "Nome: " + doc.getNome() + "\nCaminho: " + doc.getCaminho()+ "\nTipo: " + doc.getTipo() + "\nData: {}".format(doc.getData()) + "\n"
            docs += "Nome: {} \nCaminho: {} \nTipo: {} \nData: {}/{}/{} \n\n".format(doc.getNome(), doc.getCaminho(), doc.getTipo(), doc.getData().day, doc.getData().month, doc.getData().year)
            # docs = 'Nome: {}'

        return docs.rstrip()
