#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro(){
	
	//inicio da cria��o de variaveis
	char arquivo[40];	
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //$s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo 
	fprintf(file,cpf);//salvo o valor
	fclose(file);//fecha o arquivo 
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o seu cargo na empresa: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	printf("Voc� foi cadastrado com sucesso!\n\n");
	system("pause");
}

int consultar(){
	setlocale(LC_ALL, "Portuguese"); //Definindo o idioma
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL){
		printf("N�o foi possivel abrir o arquivo, n�o localizado! \n");	
	}
	
	while(fgets(conteudo, 200, file) !=NULL){
		printf("\nEssas s�o as informa��es do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
}

int deletar(){
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL){
		printf("O usu�rio n�o se encontra no sistema!. \n");
		system("pause");		
	}else{
		printf("O usu�rio foi deletado com sucesso! \n");
		system("pause");
	}
}

int main(){
	int opcao=0; //Definindo variaveis
	int laco=1; //variavel do for
	
	for(laco=1;laco=1;)
	{
		system("cls");//responsavel por limpar a tela retirando o historico 
		
		setlocale(LC_ALL, "Portuguese"); //Definindo o idioma
		
		printf("###- Cart�rio da EBAC -###");
		printf("Escolha a op��o desejada do menu \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("Op��o: "); //fim do menu
		
		scanf("%d", &opcao); //armazenando a escolha do usuario
		
		system("cls");
		
		switch(opcao)
		{
			case 1:
			registro();//chamada de fun��es
			break;
			case 2:
			consultar();
			break;
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break; //fim da sele��o
		}
	}
}