#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��ao de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro()//fun��o respons�vel por cadatrar os usu�rios no sistema (int main)
{
	//in�cio da cria��o de vari�veis/strings[]
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings[]
	
	printf("\n");
	printf(" Digite o CPF a ser cadastrado: ");//coletando informa��es do usu�rio
	scanf("%s", cpf);//salvando essas informa�oes
	//%s referese a strings

	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo // o "w" significa escrever
	fprintf(file, "CPF:");//nome da informa��o a ser coletada
	fprintf (file, cpf); //salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //acessar o arquivo // o "a" significa atualizar as informa��es do file
	fprintf(file, ", oie "); //salvar no arquivo
	fclose(file);
	
	printf(" Digite o nome a ser cadastrado: ");
	scanf("%s", nome);

	file = fopen(arquivo, "a");
	fprintf(file, "Nome:");
	fprintf(file, nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);

	printf(" Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);

	file = fopen(arquivo, "a");
	fprintf(file, "Sobrenome:");
	fprintf(file, sobrenome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);

	printf(" Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);

	file = fopen(arquivo, "a");
	fprintf(file, "Cargo:");
	fprintf(file, cargo);
	fclose(file);
	
	printf("\n");
	printf("___________________________________________\n\n\n");
	
	system("pause");
	
}


int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem

	char cpf[40];
	char conteudo[200];

	printf("\n");
	printf(" Digite o CPF a ser consultado: ");
	scanf("%s", cpf);

	FILE *file;
	file = fopen(cpf, "r"); 
	
	if(file == NULL)
	{
		printf("\n");
		printf(" CPF n�o localizado! \n N�o foi poss�vel abrir o arquivo.\n Tente novamente!\n\n\n");
		printf("___________________________________________\n\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n -Estas s�o as informa��es do usu�rio:\n\n ");
		printf("%s", conteudo);
		printf("\n\n");
		printf("___________________________________________\n\n\n");
	}

	system("pause"); 
	
}


int deletar()
{
	char cpf[40];

	printf(" Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file != NULL)
	
	{
		fclose(file);
		remove(cpf);
		printf("\n");
		printf(" Usu�rio deletado com sucesso!\n\n");
		printf("___________________________________________\n\n\n");
		system("pause");
	}
		
	else
	
	{
        printf("\n");
		printf(" O usu�rio n�o se encontra no sistema! \n\n");
		printf("___________________________________________\n\n\n");
        system("pause");
	}
	

}


int main()
{
	int opcao = 0;//definindo as vari�veis
	int laco = 1;//vari�vel utilizada para a repetic�o
	
	for(laco=1; laco=1;)
	{
		system ("cls");
		
		setlocale(LC_ALL, "Portuguese"); //escolhendo o idioma/linguagem 
	
		printf("   ###\t Cart�rio da EBAC\t ###\n\n");//in�cio do menu
		printf("___________________________________________\n\n\n");
		printf(" Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n");
		printf("\t4 - Sair do Sistema\n\n\n");
		printf("___________________________________________\n\n\n");
		printf(" Op��o escolhida: ");//fim do menu
	
		scanf("%d", &opcao);//armazenando a escolha do usu�rio
	
		system("cls");//limpando a tela
		
		switch(opcao)//in�cio da sele��o
		{
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
			printf(" Obrigado por utilizar o Sistema!\n");
			return 0;//quebra la�o, e sai do sistema
			break;
			
			default://quando n�o � nenhuma das op��es mapeadas
			printf(" Desculpe, esta op��o n�o est� dispon�vel.\n\n Tente novamente!\n\n");
			printf("___________________________________________\n\n\n");
			system("pause");
			break;
					
		}//final da sele��o
	
	}
}
