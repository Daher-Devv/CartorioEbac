#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região  
#include <string.h>// biblioteca responsável por cuidae das strings

int registro()
// função de cadastrar o usuario do sistema
 {
	// inicio de variáveis/strings
    
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // final da criação de variáveis
    
    printf("Digite o CPF a ser Cadastrado: "); 
    // coletando informação do usuário
    scanf("%s", cpf);// %s refere-se a string
    
    strcpy(arquivo, cpf); // copia o cpf para o nome do arquivo
    
    FILE *file; // cria o arquivo
    file = fopen(arquivo, "w"); // abre o arquivo para escrita "w" SIGNIFICA ESCRITA
    if (file == NULL){
    	     printf("Erro ao abrie o arquivo! \n");
    	     return 1; // retorna erro se não conseguir abrir 
    }
    
    //escreve os dados no arquivoem uma unica linha
    fprintf(file, "%s,%s,%s,%s \n", cpf, nome, sobrenome, cargo);//salva o valor da variavel
    fprintf(file, "%s \n", cpf); // salva o cpf
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    fprintf(file, "%s \n", nome) ;
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    fprintf(file, "%s \n", sobrenome);
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    fprintf(file, "%s \n", cargo);
    fclose(file); //fecha o arquivo
    
    printf("Resgistro salvo com sucesso! \n");
    system("pause");
    return 0; // Retorna sucesso
    
}

int consultar()
{
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
    
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF  a Ser Consultado: ");
    scanf("%s",cpf);
     
    FILE *file;// FILE =  ARQUIVO , *FILE (ABRA O ARQUIVO FILE)
    file = fopen(cpf, "r"); //abre o arquivo FILE para leitura
    
    if(file == NULL){  //NULL = NULO , IF(FILE == NULL) SE O ARQUIVO NÃO EXISTE 
        printf("Não foi possivel abrir o arquivo, não localizado!.\n");
        system("pause");
        return 1; // retorna pós o erro 
    }

    printf("Essas são as informações do usuário: \n");
    while (fgets(conteudo, sizeof(conteudo), file) != NULL) { 
     printf("%s", conteudo); // imprime o conteudo lido
    }
    fclose(file); //fecha o arquivo
    system("pause");
    return 0; //retorna com sucesso
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF  a ser Deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file; // abre o arquivo 
	file = fopen(cpf,"r");//escreve o cpf
	
	if(file ==  NULL) // e se for nulo
	{
		printf("o Usuário não se Encontra no Sistema!.\n");
		system("pause");
		//volta pro inicio quando não encontrado/ deletado
	}
	
}

int main()
    {
	int opcao=0; // definindo as variáveis 

while(1) {// loop infinito
	    system("cls");//limpar tela 
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
	
	    printf("###Cartório Da EBAC###\n\n"); // Inicio do menu 
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar Nomes\n");
	    printf("\t2 - Consultar Nomes\n");
	    printf("\t3 - Deletar Nomes\n\n"); 
	    printf("Opção: ");// Fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usuário
	    
	    system("cls"); // apagar a tela // limpar tela 
	    
	    
	    switch(opcao)// inivio das seleções 
	    {
	    	case 1:
	    		registro();// CHAMADA DE FUNÇAÕ 
	    		break;
	    		 // tirei o printf e coloquei uma funcao resgistro (funçao int).
	     case 2:
	        	consultar();// chamda de funçaõ
	        	break;
	        	 // tirei o printf e coloquei uma funcao consultar(funçao int).
	        
	     case 3:
	        	deletar();// chamada de função
	        	break;
	             // tirei o printf e coloquei uma funcao deletar (funçao int).
	      default:
	        	printf("Está opção não Está Disponivel!\n");
	        	system("pause");
	        	break;
	        	// FIM DA SELEÇAO
		}

   }
}



