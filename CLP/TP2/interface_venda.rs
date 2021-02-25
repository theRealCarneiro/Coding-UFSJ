use std::io;
use std::string;
use cliente;
use ItemVenda;
use Venda;
use Cliente;
use Produto;
use Totalizavel;
use GetItemVenda;
use GetProduto;
use GetPessoa;
use GetVenda;
use SetVenda;
use item_venda::*;
use interface_cliente::*;
use interface_produto::*;

pub fn menu_venda(mut vendas: &mut Vec<Venda>, mut clientes: &mut Vec<Cliente>, mut produtos: &mut Vec<Produto>){
    let mut cond = true;
    print!("\x1B[2J\x1B[1;1H");
    while cond == true {
        println!("Selecione");
        println!("1-Vender");
        println!("2-Remove venda");
        println!("3-Busca venda");
        println!("4-Alterar venda");
        println!("_-Sair");
        let mut input = String::new();
        io::stdin().read_line(&mut input);
        match input.as_str().trim(){
            "1" => {
                insere_venda(&mut vendas, &mut clientes, &mut produtos);
                cond = false;
            },
            "2" => {
                print!("\x1B[2J\x1B[1;1H");
                println!("Forneça o numero da venda: ");
                let mut numero = String::new();
                io::stdin().read_line(&mut numero).expect("Input inválido");
                let numero = numero.trim().parse::<u32>().expect("Input inválido");
                remove_venda(&mut vendas, numero);
                cond = false;
            },
            "3" => {
                print!("\x1B[2J\x1B[1;1H");
                println!("Forneça o numero da venda: ");
                let mut numero = String::new();
                io::stdin().read_line(&mut numero).expect("Input inválido");
                let numero = numero.trim().parse::<u32>().expect("Input inválido");
                busca_venda(&mut vendas, numero);
                cond = false;
            },
            "4" => {
                print!("\x1B[2J\x1B[1;1H");
                println!("Forneça o numero da venda: ");
                let mut numero = String::new();
                io::stdin().read_line(&mut numero).expect("Input inválido");
                let numero = numero.trim().parse::<u32>().expect("Input inválido");
                altera_venda(&mut vendas, &mut clientes, &mut produtos, numero);
                cond = false;
            },
            _ => cond = false,
        }
    }
}

pub fn insere_venda(mut vendas: &mut Vec<Venda>, mut clientes: &mut Vec<Cliente>, mut produtos: &mut Vec<Produto>){
    print!("\x1B[2J\x1B[1;1H");

    let mut tamanho = vendas.len() as u32;
    if(tamanho != 0){
        tamanho = vendas[vendas.len() - 1].get_numero() + 1;
    }

    println!("Insira a data");
    let mut data = String::new();
    io::stdin().read_line(&mut data);

    println!("Insira o rg do cliente");
    let mut rg = String::new();
    io::stdin().read_line(&mut rg);
    let cliente = busca_cliente(clientes, rg);

    let mut item: Vec<ItemVenda> = Vec::new();

    let mut cond = true;

    while cond == true {
        println!("Forneça o codigo do produto: ");
        let mut codigo = String::new();
        io::stdin().read_line(&mut codigo).expect("Input inválido");
        let codigo = codigo.trim().parse::<u32>().expect("Input inválido");
        let mut produto = busca_produto(&mut produtos, codigo);

        println!("Forneça a quantidade do produto: ");
        let mut quantidade = String::new();
        io::stdin().read_line(&mut quantidade).expect("Input inválido");
        let quantidade = quantidade.trim().parse::<u32>().expect("Input inválido");

        let mut tem_produto: bool = false;
        for i in item.iter_mut(){
            if(i.get_produto().get_codigo() == codigo){
                i.set_quantidade(i.get_quantidade() + quantidade);
                tem_produto = true;
            }
        }

        println!("Deseja inserir mais um produto? [s/n]: ");
        let mut input = String::new();
        io::stdin().read_line(&mut input);
        if(input.as_str().trim() == "n"){
            cond = false;
        }
        if(tem_produto == false){
            let valor = produto.get_valor();
            let mut itemvenda = ItemVenda{
                produto: produto,
                valor: valor,
                quantidade: quantidade,
            };
            item.push(itemvenda);
        }
    }

    let mut ven = Venda {
        numero: tamanho,
        data: data,
        cliente: cliente,
        item: item,
    };
    vendas.push(ven);
    print!("\x1B[2J\x1B[1;1H");
    println!("Venda Cadastrada com sucesso");
    busca_venda(vendas, tamanho);
}


fn busca_venda(vendas: &mut Vec<Venda>, numero: u32){
    for venda in vendas.iter() {
        if(venda.numero == numero){
            println!("Venda: {} Cliente: {}", venda.get_numero(), venda.get_cliente().get_nome().trim());
            for i in venda.get_item().iter(){
                println!("Produto: {} Codigo: {} Valor: {} Quantidade: {}", i.get_produto().get_nome().trim(), 
                         i.get_produto().get_codigo(), i.get_valor(), i.get_quantidade());
            }
            println!("Total da venda: {}\n",venda.total());
            return;
        }
    }
    print!("\x1B[2J\x1B[1;1H");
    println!("Venda não encontrado");
}

 
fn remove_venda(vendas: &mut Vec<Venda>, numero: u32){
    for i in 0..vendas.len() {
        if(vendas[i].get_numero() == numero){
            vendas.remove(i);
            print!("\x1B[2J\x1B[1;1H");
            println!("Venda removida com sucesso");
            return;
        }
    }
    print!("\x1B[2J\x1B[1;1H");
    println!("Venda não encontrado");
}

fn altera_venda(mut vendas: &mut Vec<Venda>, mut clientes:&mut Vec<Cliente>, mut produtos:&mut Vec<Produto>, numero: u32){
    print!("\x1B[2J\x1B[1;1H");
    for venda in vendas.iter_mut() {
        if(venda.numero == numero){
            let mut cond = true;
            while cond == true {
                println!("Selecione");
                println!("1-Data");
                println!("2-Cliente");
                println!("3-Adicionar item");
                println!("4-Remover item");
                println!("_-Sair");
                let mut input = String::new();
                io::stdin().read_line(&mut input);
                match input.as_str().trim(){
                    "1" => {
                        println!("Insira a data");
                        let mut data = String::new();
                        io::stdin().read_line(&mut data);
                        venda.set_data(data);
                    },
                    "2" => {
                        println!("Insira o rg do cliente");
                        let mut rg = String::new();
                        io::stdin().read_line(&mut rg);
                        let cliente = busca_cliente(clientes, rg);
                        venda.set_cliente(cliente);
                    },
                    "3" => {
                        while cond == true {
                            println!("Forneça o codigo do produto: ");
                            let mut codigo = String::new();
                            io::stdin().read_line(&mut codigo).expect("Input inválido");
                            let codigo = codigo.trim().parse::<u32>().expect("Input inválido");
                            let mut produto = busca_produto(&mut produtos, codigo);

                            println!("Forneça a quantidade do produto: ");
                            let mut quantidade = String::new();
                            io::stdin().read_line(&mut quantidade).expect("Input inválido");
                            let quantidade = quantidade.trim().parse::<u32>().expect("Input inválido");

                            let mut tem_produto: bool = false;
                            let mut lista = venda.get_item();
                            for i in lista.iter_mut(){
                                if(i.get_produto().get_codigo() == codigo){
                                    i.set_quantidade(i.get_quantidade() + quantidade);
                                    tem_produto = true;

                                }
                            }

                            println!("Deseja inserir mais um produto? [s/n]: ");
                            let mut input = String::new();
                            io::stdin().read_line(&mut input);
                            if(input.as_str().trim() == "n"){
                                cond = false;
                            }
                            if(tem_produto == false){
                                let valor = produto.get_valor();
                                let mut itemvenda = ItemVenda{
                                    produto: produto,
                                    valor: valor,
                                    quantidade: quantidade,
                                };
                                venda.append_item(itemvenda);
                            }
                            else {
                                venda.set_item(lista);                                    
                            }

                        }
                    }
                    "4" => {
                        let mut vetor_item = venda.get_item();
                        for i in vetor_item.iter(){
                            println!("Produto: {} Valor: {} Quantidade: {}", i.get_produto().get_nome().trim(), i.get_valor(), i.get_quantidade());
                        }
                        let mut cond: bool = true;
                        while(cond == true){
                            println!("Insira o codigo");
                            let mut codigo = String::new();
                            io::stdin().read_line(&mut codigo).expect("failed to read input.");
                            let codigo = codigo.trim().parse::<u32>().expect("invalid input");
                            for i in 0..vetor_item.len(){
                                if(vetor_item[i].get_produto().get_codigo() == codigo){
                                    vetor_item.remove(i);
                                }
                            }

                            println!("Deseja remover mais um produto? [s/n]: ");
                            let mut input = String::new();
                            io::stdin().read_line(&mut input);
                            if(input.as_str().trim() == "n"){
                                cond = false;
                            }
                        }
                        venda.set_item(vetor_item);
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
