class Cliente extends Entidade {

     private String nome;
     private String cpf;

     public Cliente(String nome, String cpf){
          this.nome = nome;
          this.cpf = cpf;
     }

     public Cliente(){
          System.out.println("Insira o nome do cliente");
          setNome(System.console().readLine());
          System.out.println("Insira o cpf do cliente");
          setCPF(System.console().readLine());
     }

     public String getNome(){
          return this.nome;
     }

     public void setNome(String nome){
          this.nome = nome;
     }

     public String getCPF(){
          return this.cpf;
     }

     public void setCPF(String cpf){
          this.cpf = cpf;
     }
}
