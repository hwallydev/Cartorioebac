 #include <stdio.h> //biblioteca de comunicação com o usuário.
#include <stdlib.h> //biblioteca de alocação de espaço em memória.
#include <locale.h> //biblioteca de alocação de texto por região.
#include <string.h> //biblioteca responsável por cuidar das strings

int registro(){ // responsavel por cadastrar os usuários no sistema.
	
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	// inicio na criação de variável.
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	// final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informação do usuário.
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // Esse cara é responsavel por copiar os valores das strings
	
	FILE *file; //Cria arquivo
	file = fopen(arquivo, "w"); //cria arquivo e o "w" significa escrever.
	fprintf(file,cpf); // salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e "a" atualiza.
	fprintf(file,", Nome:"); 
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", Sobrenome:");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", Cargo:");
	fclose(file);
	
	printf("Digite o seu cargo: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); // pausa para que o usuária consiga ver a msg.
	
	
	
	
	
}


int consulta(){
	
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF que deseja consultar: ");
	scanf("%s",cpf);
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL){
		printf("Não foi possivel encontrar este CPF!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar(){
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
		FILE *file;
	file = fopen(cpf, "r");

	
	if(file == NULL){

		printf("Registro não encontrado.\n\n");
		
		
	}else{
		fclose(file);
	}
	
	
	remove(cpf); // função já pronta para remover.
	printf("Usuário foi deletado com sucesso!\n\n");
	system("pause");
		

	
}


int main(){
	
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;){
	
		system("cls"); // rsponsável por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
		
		printf("\t### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n ");
		printf("\t2 - Consultar nomes\n ");
		printf("\t3 - Deletar nomes\n ");
		printf("\t4 - Sair do Sistema: \n\n");
		printf("Digite a opção: "); //Fim do menu
		
		
		scanf("%d", &opcao); //Armazenando a escolha do usuário
		
		system("cls");
		
		switch(opcao){
			
			case 1:
				registro();
				break;
			
			case 2:
				consulta();
				break;
			
			case 3:
				deletar();
				break;
			
			case 4:
				printf("Obrigado por utilizar o sistema\n\n");
				return 0;
				break;
				
			default:
				printf("Essa opção não esta disponivel\n");
				break;
				
					
				
		}
		}
		
}
	


