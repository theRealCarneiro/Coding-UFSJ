#[derive(Clone)]
pub struct Pessoa{
    pub nome: String,
    pub endereco: String,
}

pub trait SetPessoa {
    fn set_nome(&mut self, nome: String);
    fn set_endereco(&mut self, endereco: String);
}

pub trait GetPessoa {
    fn get_nome(&self) -> String;
    fn get_endereco(&self) -> String;
}


