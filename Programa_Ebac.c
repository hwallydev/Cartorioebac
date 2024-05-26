 #include <stdio.h> //biblioteca de comunica��o com o usu�rio.
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria.
#include <locale.h> //biblioteca de aloca��o de texto por regi�o.
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro(){ // responsavel por cadastrar os usu�rios no sistema.
	
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	// inicio na cria��o de vari�vel.
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informa��o do usu�rio.
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // Esse cara � responsavel por copiar os valores das strings
	
	FILE *file; //Cria arquivo
	file = fopen(arquivo, "w"); //cria arquivo e o "w" significa escrever.
	fprintf(file,cpf); // salva o valor da vari�vel
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
	
	system("pause"); // pausa para que o usu�ria consiga ver a msg.
	
	
	
	
	
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
		printf("N�o foi possivel encontrar este CPF!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar(){
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
		FILE *file;
	file = fopen(cpf, "r");

	
	if(file == NULL){

		printf("Registro n�o encontrado.\n\n");
		
		
	}else{
		fclose(file);
	}
	
	
	remove(cpf); // fun��o j� pronta para remover.
	printf("Usu�rio foi deletado com sucesso!\n\n");
	system("pause");
		

	
}


int main(){
	
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;){
	
		system("cls"); // rspons�vel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
		
		printf("\t### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n ");
		printf("\t2 - Consultar nomes\n ");
		printf("\t3 - Deletar nomes\n ");
		printf("\t4 - Sair do Sistema: \n\n");
		printf("Digite a op��o: "); //Fim do menu
		
		
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
		
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
				printf("Essa op��o n�o esta disponivel\n");
				break;
				
					
				
		}
		}
		
}
	


