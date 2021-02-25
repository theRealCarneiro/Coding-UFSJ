use Pessoa;
use pessoa::SetPessoa;
use pessoa::GetPessoa;

#[derive(Clone)]
pub struct Cliente {
    pub pes: Pessoa,
    pub rg: String,
    pub data_nascimento: String,
}

pub trait SetCliente {
    fn set_rg(&mut self, rg: String);
    fn set_data_nascimento(&mut self, data_nascimento: String);
}

pub trait GetCliente {
    fn get_rg(&self) -> String;
    fn get_data_nascimento(&self) -> String;
}

impl GetPessoa for Cliente {
    fn get_nome(&self) -> String{
        return self.pes.nome.clone();
    }

    fn get_endereco(&self) -> String{
        return self.pes.endereco.clone();
    }
}

impl GetCliente for Cliente {
    fn get_rg(&self) -> String{
        return self.rg.clone();
    }

    fn get_data_nascimento(&self) -> String{
        return self.data_nascimento.clone();
    }
}

impl SetPessoa for Cliente {
    fn set_nome(&mut self, nome: String){
        self.pes.nome = nome;
    }

    fn set_endereco(&mut self, endereco: String){
        self.pes.endereco = endereco;
    }
}

impl SetCliente for Cliente {
    fn set_rg(&mut self, rg: String){
        self.rg = rg;
    }

    fn set_data_nascimento(&mut self, data_nascimento: String){
        self.data_nascimento = data_nascimento;
    }
}
