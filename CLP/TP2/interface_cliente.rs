use std::io;
use std::string;
use Pessoa;
use Cliente;
use GetPessoa;
use SetPessoa;
use GetCliente;
use SetCliente;

pub fn menu_cliente(mut clientes: &mut Vec<Cliente>){
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
                insere_cliente(&mut clientes);
                cond = false;
            },
            "2" => {
                print!("\x1B[2J\x1B[1;1H");
                println!("Forneça o rg: ");
                let mut rg = String::new();
                io::stdin().read_line(&mut rg);
                remove_cliente(&mut clientes,rg);
                cond = false;
            },
            "3" => {
                print!("\x1B[2J\x1B[1;1H");
                println!("Forneça o rg: ");
                let mut rg = String::new();
                io::stdin().read_line(&mut rg);
                busca_cliente(&mut clientes,rg);
                cond = false;
            },
            "4" => {
                print!("\x1B[2J\x1B[1;1H");
                println!("Forneça o rg: ");
                let mut rg = String::new();
                io::stdin().read_line(&mut rg);
                altera_cliente(&mut clientes,rg);
                cond = false;
            },
            _ => cond = false,
        }
    }
}

fn insere_cliente(mut clientes: &mut Vec<Cliente>){

    println!("Insira o nome");
    let mut nome = String::new();
    io::stdin().read_line(&mut nome);

    println!("Insira o endereço");
    let mut end = String::new();
    io::stdin().read_line(&mut end);

    println!("Insira o rg");
    let mut rg = String::new();
    io::stdin().read_line(&mut rg);

    println!("Insira a data de nascimento");
    let mut nasc = String::new();
    io::stdin().read_line(&mut nasc);

    let mut cli = Cliente {
        pes: Pessoa {nome: nome, endereco:end},
        rg: rg.clone(),
        data_nascimento: nasc,
    };
    clientes.push(cli);
    print!("\x1B[2J\x1B[1;1H");
    println!("Cliente inserido com sucesso");
    busca_cliente(clientes, rg);
}

pub fn busca_cliente(clientes: &mut Vec<Cliente>, rg: String) -> Cliente{
    let tmp = Cliente {
        pes: Pessoa {nome: "".to_string(), endereco: "".to_string()},
        rg: "".to_string(),
        data_nascimento: "".to_string(),
    };

    for cliente in clientes.iter() {
        if(cliente.rg == rg){
            println!("Nome: {}RG: {}Endereço: {}Nascimento: {}",cliente.get_nome(),cliente.get_rg(),cliente.get_endereco(),cliente.get_data_nascimento());
            return cliente.clone();
        }
    }
    print!("\x1B[2J\x1B[1;1H");
    println!("Cliente não encontrado");
    return tmp;
}

fn remove_cliente(clientes: &mut Vec<Cliente>, rg: String){
    for i in 0..clientes.len() {
        if(clientes[i].get_rg() == rg){
            clientes.remove(i);
            print!("\x1B[2J\x1B[1;1H");
            println!("Cliente removido com sucesso");
            return;
        }
    }
    print!("\x1B[2J\x1B[1;1H");
    println!("Cliente não encontrado");
}
 
fn altera_cliente(mut clientes: &mut Vec<Cliente>, rg: String){
    print!("\x1B[2J\x1B[1;1H");
    for cliente in clientes.iter_mut() {
        if(cliente.rg == rg.to_string()){
            let mut cond = true;
            while cond == true {
                println!("Selecione");
                println!("1-Nome");
                println!("2-RG");
                println!("3-Endereço");
                println!("4-Data de Nascimento");
                println!("_-Sair");
                let mut input = String::new();
                io::stdin().read_line(&mut input);
                match input.as_str().trim(){
                    "1" => {
                        println!("Forneça um nome");
                        let mut nome = String::new();
                        io::stdin().read_line(&mut nome);
                        cliente.set_nome(nome);
                    },

                    "2" => {
                        println!("Forneça um RG");
                        let mut rg = String::new();
                        io::stdin().read_line(&mut rg);
                        cliente.set_rg(rg);
                    },
                    "3" => {
                        println!("Forneça um Endereço");
                        let mut end = String::new();
                        io::stdin().read_line(&mut end);
                        cliente.set_endereco(end);
                    },
                    "4" => {
                        println!("Forneça uma Data de Nascimento");
                        let mut nas = String::new();
                        io::stdin().read_line(&mut nas);
                        cliente.set_data_nascimento(nas);
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

