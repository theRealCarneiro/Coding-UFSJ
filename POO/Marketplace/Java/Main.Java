import java.io.IOException;

public class Main{

     static BancoDeDados bd = new BancoDeDados();

     public static void cls() { //limpa o terminal
          try {
               new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor(); //achei no stackoverflow
          }
          catch(Exception E) {
               System.out.println(E);
          }
     }

     static void menuCliente(){
          cls();
          System.out.println("1- Adicionar Cliente \n2- Remover Cliente \n3- Lista Clientes \nQualquer outra opção para sair");
          int selecao = 0;
          try {
               selecao = Integer.parseInt(System.console().readLine()); //Lê no terminal
          }
          catch (NumberFormatException | NullPointerException nfe){
               System.out.println("ERRO");
          }
          switch(selecao){
               case 1: //Add
                    cls();
                    Cliente cliente = new Cliente(); //Cria o objeto e chama o construtor (o sem parametros)
                    cls();
                    bd.insereCliente(cliente);
                    break;
               case 2: //Remover
                    cls();
                    bd.imprimeClientes();
                    System.out.println("Insira o ID do cliente");
                    int id = Integer.parseInt(System.console().readLine()); //Lê no terminal
                    bd.removeCliente(id);
                    break;
               case 3: //imprimir
                    cls();
                    bd.imprimeClientes();
                    break;
               default: //Volta pro menu
                    cls();
          }
     }

     public static void main(String args[]){
          int selecao = 0;
          cls();
          do{ //pra ficar no menu até mandar sair
               System.out.println("1- Clientes \n2- Produtos \n3- Venda \n4- Sair");
               try {//pra não aceitar valor sem ser inteiro
                    selecao = Integer.parseInt(System.console().readLine()); //Lê no terminal
               }
               catch (NumberFormatException | NullPointerException nfe){
                    System.out.println("ERRO");
               }
               switch(selecao){
                    case 1: //abre o menu de cliente
                         menuCliente();
                         break;
                    case 2: //abre o menu de produtos
                         System.out.print(" ");
                         break;
                    case 3: //abre o menu de venda
                         System.out.print(" ");
                         break;
                    default:
                         cls();
               }
          } while(selecao != 4); //se for 4 sai do loop
     }
}
