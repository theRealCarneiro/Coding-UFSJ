use totalizavel::Totalizavel;
use ItemVenda;
use Cliente;
use GetCliente;

pub struct Venda{
    pub numero: u32,
    pub data: String,
    pub cliente: Cliente,
    pub item: Vec<ItemVenda>,
}

pub trait SetVenda {
    fn set_numero(&mut self, numero: u32);
    fn set_data(&mut self, data: String);
    fn set_cliente(&mut self, cliente: Cliente);
    fn set_item(&mut self, item: Vec<ItemVenda>);
    fn append_item(&mut self, item: ItemVenda);
}

pub trait GetVenda {
    fn get_numero(&self) -> u32;
    fn get_data(&self) -> String;
    fn get_cliente(&self) -> Cliente;
    fn get_item(&self) -> Vec<ItemVenda>;
}

impl GetVenda for Venda {
    fn get_numero(&self) -> u32{
        return self.numero;
    }
    fn get_data(&self) -> String{
        return self.data.clone();
    }
    fn get_cliente(&self) -> Cliente{
        return self.cliente.clone();
    }
    fn get_item(&self) -> Vec<ItemVenda>{
        return self.item.clone();
    }
}

impl SetVenda for Venda {
    fn set_numero(&mut self, numero: u32){
        self.numero = numero;
    }

    fn set_data(&mut self, data: String){
        self.data = data;
    }
    fn set_cliente(&mut self, cliente: Cliente){
        self.cliente = cliente;
    }
    fn set_item(&mut self, item: Vec<ItemVenda>){
        self.item = item;
    }

    fn append_item(&mut self, item: ItemVenda){
        self.item.push(item);
    }
}

impl Totalizavel for Venda{
    fn total(&self) -> f32{
        let mut valor: f32 = 0.0;
        for i in self.get_item().iter(){
            valor += i.total();
        }
        return valor;
    }
}
