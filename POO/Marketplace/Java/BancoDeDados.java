import java.util.ArrayList;

class BancoDeDados{

     ArrayList<Cliente> listaClientes = new ArrayList<Cliente>();//Tipo lista encadeada, o tamanho varia de acordo com oq vc coloca (eu acho)
     ArrayList<Produto> listaProdutos = new ArrayList<Produto>();

     public void insereCliente(Cliente cliente){
          int novoID = listaClientes.size(); //Novo ID = tamanho da lista (porque na remoção os ids são sempre atualizados)
          cliente.setID(novoID);
          listaClientes.add(cliente);
          System.out.println("Cliente registrado com sucesso! \nNome: " + cliente.getNome() + "\nCPF: " + cliente.getCPF() + "\nID: " + cliente.getID());
     }

     public void removeCliente(int id){
          if(listaClientes.size() > id){ //Se o tamanho for menor ou igual, significa que o id não existe
               System.out.println(listaClientes.remove(id).getNome() + " removido com sucesso!");
               if(id < listaClientes.size()) { //Se o id não era o ultimo, significa que agora as posições não estão de acordo com os ids
                    for(int i = id; i < listaClientes.size(); i++){ //percorre a lista para corrigir os ids
                         int novoID = listaClientes.get(id).getID() - 1; //ID--
                         listaClientes.get(id).setID(novoID); //recebe o id correto
                    }
               }
          }
          else {
               System.out.println("ERRO, ID NÃO EXISTE OU LISTA VAZIA");
          }
     }

     public void imprimeClientes(){
          if(listaClientes.size() > 0){ //testa se a lista não está vazio
               for(int i = 0; i < listaClientes.size(); i++){
                    System.out.println(listaClientes.get(i).getID() + " " + listaClientes.get(i).getNome() + " " + listaClientes.get(i).getCPF()); //imprime as informações dos clientes
               }
          }
          else {
               System.out.println("Nenhum cliente registrado");
          }
     }
}
