use std::io;
use std::string;

mod totalizavel;
use totalizavel::*;

mod cliente;
use cliente::*;

mod pessoa;
use pessoa::*;

mod produto;
use produto::*;

mod item_venda;
use item_venda::*;

mod venda;
use venda::*;

mod interface_cliente;
use interface_cliente::*;

mod interface_produto;
use interface_produto::*;

mod interface_venda;
use interface_venda::*;

pub fn menu_principal(mut clientes: &mut Vec<Cliente>, mut produtos: &mut Vec<Produto>, mut vendas: &mut Vec<Venda>){
    let mut cond = true;
    print!("\x1B[2J\x1B[1;1H");
    while cond == true {
        println!("Selecione");
        println!("1-Cliente");
        println!("2-Produto");
        println!("3-Venda");
        println!("4-Sair");
        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Input inválido");
        match input.as_str().trim(){
            "1" => menu_cliente(&mut clientes),
            "2" => menu_produto(&mut produtos),
            "3" => menu_venda(&mut vendas, &mut clientes, &mut produtos),
            _ => cond = false,
        }
    }

}
fn main (){
    let mut clientes: Vec<Cliente> = Vec::new();
    let mut produtos: Vec<Produto> = Vec::new();
    let mut venda: Vec<Venda> = Vec::new();
    menu_principal(&mut clientes, &mut produtos, &mut venda);
}
