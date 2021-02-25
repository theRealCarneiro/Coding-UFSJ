use std::io;
use std::string;
use Produto;
use GetProduto;
use SetProduto;

pub fn menu_produto(mut produtos: &mut Vec<Produto>){
    let mut cond = true;
    print!("\x1B[2J\x1B[1;1H");
    while cond == true {
        println!("Selecione");
        println!("1-Insere");
        println!("2-Remove");
        println!("3-Busca");
        println!("4-Alterar");
        println!("_-Sair");
        let mut input = String::new();
        io::stdin().read_line(&mut input);
        match input.as_str().trim(){
            "1" => {
                insere_produto(&mut produtos);
                cond = false;
            },
            "2" => {
                print!("\x1B[2J\x1B[1;1H");
                println!("Forneça o codigo: ");
                let mut codigo = String::new();
                io::stdin().read_line(&mut codigo).expect("Input inválido");
                let codigo = codigo.trim().parse::<u32>().expect("Input inválido");
                remove_produto(&mut produtos, codigo);
                cond = false;
            },
            "3" => {
                print!("\x1B[2J\x1B[1;1H");
                println!("Forneça o codigo: ");
                let mut codigo = String::new();
                io::stdin().read_line(&mut codigo).expect("Input inválido");
                let codigo = codigo.trim().parse::<u32>().expect("Input inválido");
                busca_produto(&mut produtos, codigo);
                cond = false;
            },
            "4" => {
                print!("\x1B[2J\x1B[1;1H");
                println!("Forneça o codigo: ");
                let mut codigo = String::new();
                io::stdin().read_line(&mut codigo).expect("Input inválido");
                let codigo = codigo.trim().parse::<u32>().expect("Input inválido");
                altera_produto(&mut produtos, codigo);
                cond = false;
            },
            _ => cond = false,
        }
    }
}

fn insere_produto(mut produtos: &mut Vec<Produto>){

    println!("Insira o nome");
    let mut nome = String::new();
    io::stdin().read_line(&mut nome).expect("failed to read input.");

    println!("Insira o codigo");
    let mut codigo = String::new();
    io::stdin().read_line(&mut codigo).expect("failed to read input.");
    let codigo = codigo.trim().parse::<u32>().expect("invalid input");

    println!("Insira o valor");
    let mut valor = String::new();
    io::stdin().read_line(&mut valor).expect("failed to read input.");
    let valor = valor.trim().parse::<f32>().expect("invalid input");

    let mut cli = Produto {
        nome: nome,
        codigo: codigo,
        valor: valor,
    };
    produtos.push(cli);
    print!("\x1B[2J\x1B[1;1H");
    println!("Produto inserido com sucesso");
    busca_produto(produtos, codigo);
}

pub fn busca_produto(produtos: &mut Vec<Produto>, codigo: u32) -> Produto{
    let tmp = Produto {
        nome: "".to_string(),
        codigo: 0,
        valor: 0.0,
    };
    for produto in produtos.iter() {
        if(produto.codigo == codigo){
            println!("Nome: {}Código: {}\nValor: {}",produto.get_nome(),produto.get_codigo(),produto.get_valor());
            return produto.clone();
        }
    }
    print!("\x1B[2J\x1B[1;1H");
    println!("Produto não encontrado");
    return tmp;
}

fn remove_produto(produtos: &mut Vec<Produto>, codigo: u32){
    for i in 0..produtos.len() {
        if(produtos[i].get_codigo() == codigo){
            produtos.remove(i);
            print!("\x1B[2J\x1B[1;1H");
            println!("Produto removido com sucesso");
            return;
        }
    }
    print!("\x1B[2J\x1B[1;1H");
    println!("Produto não encontrado");
}
 
fn altera_produto(mut produtos: &mut Vec<Produto>, codigo: u32){
    print!("\x1B[2J\x1B[1;1H");
    for produto in produtos.iter_mut() {
        if(produto.codigo == codigo){
            let mut cond = true;
            while cond == true {
                println!("Selecione");
                println!("1-Nome");
                println!("2-Codigo");
                println!("3-Valor");
                println!("_-Sair");
                let mut input = String::new();
                io::stdin().read_line(&mut input);
                match input.as_str().trim(){
                    "1" => {
                        println!("Forneça um nome");
                        let mut nome = String::new();
                        io::stdin().read_line(&mut nome).expect("Input inválido");
                        produto.set_nome(nome);
                    },

                    "2" => {
                        println!("Forneça um código");
                        let mut codigo = String::new();
                        io::stdin().read_line(&mut codigo).expect("Input inválido");
                        let codigo = codigo.trim().parse::<u32>().expect("Input inválido");
                        produto.set_codigo(codigo);
                    },
                    "3" => {
                        println!("Forneça um valor");
                        let mut valor = String::new();
                        io::stdin().read_line(&mut valor).expect("Input inválido");
                        let valor = valor.trim().parse::<f32>().expect("Input inválido");
                        produto.set_valor(valor);
                    },
                    _ => {
                        print!("\x1B[2J\x1B[1;1H");
                        println!("Alterações realizadas com sucesso");
                        cond = false
                    },
                }
            }
            return;
        }
    }

}
