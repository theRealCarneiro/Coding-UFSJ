#[derive(Clone)]
pub struct Produto{
    pub nome: String,
    pub codigo: u32,
    pub valor: f32,
}

pub trait SetProduto {
    fn set_nome(&mut self, nome: String);
    fn set_codigo(&mut self, codigo: u32);
    fn set_valor(&mut self, valor: f32);
}

pub trait GetProduto {
    fn get_nome(&self) -> String;
    fn get_codigo(&self) -> u32;
    fn get_valor(&self) -> f32;
}

impl GetProduto for Produto {
    fn get_nome(&self) -> String{
        return self.nome.clone();
    }

    fn get_codigo(&self) -> u32{
        return self.codigo;
    }

    fn get_valor(&self) -> f32{
        return self.valor;
    }
}

impl SetProduto for Produto {
    fn set_nome(&mut self, nome: String){
        self.nome = nome;
    }

    fn set_codigo(&mut self, codigo: u32){
        self.codigo = codigo;
    }

    fn set_valor(&mut self, valor: f32){
        self.valor = valor;
    }
}
