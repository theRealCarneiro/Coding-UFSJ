use totalizavel::Totalizavel;
use Produto;
use GetProduto;

#[derive(Clone)]
pub struct ItemVenda{
    pub produto: Produto,
    pub valor: f32,
    pub quantidade: u32,
}

pub trait SetItemVenda {
    fn set_produto(&mut self, produto: Produto);
    fn set_valor(&mut self, produto: Produto);
    fn set_quantidade(&mut self, quantidade: u32);
}

pub trait GetItemVenda {
    fn get_produto(&self) -> Produto;
    fn get_valor(&self) -> f32;
    fn get_quantidade(&self) -> u32;
}

//pub trait Total{
    //fn Total(&mut self)-> f32{
        //return;
    //}
//}

impl Totalizavel for ItemVenda{
    fn total(&self) -> f32{
        let mut valor: f32 = 0.0;
        for i in 0..self.quantidade {
            valor += self.get_valor();
        }
        return valor;
    }
}

impl SetItemVenda for ItemVenda{
    fn set_produto(&mut self, produto: Produto){
        self.produto = produto;
    }
    fn set_valor(&mut self, produto: Produto){
        self.valor = produto.valor;
    }
    fn set_quantidade(&mut self, quantidade: u32){
        self.quantidade = quantidade;
    }
}

impl GetItemVenda for ItemVenda{
    fn get_produto(&self) -> Produto{
        return self.produto.clone();
    }
    fn get_valor(&self) -> f32{
        return self.valor;
    }
    fn get_quantidade(&self) -> u32{
        return self.quantidade;
    }
}

//impl Total for ItemVenda{
    //fn Total(&mut self) -> f32{
        //let total: f32;
        //total = self.quantidade * self.valor;
        //println!("O total é {}", total);
        //return total;
    //}

//}
