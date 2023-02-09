#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocaççao de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

int registro()//função responsável por cadatrar os usuários no sistema (int main)
{
	//início da criação de variáveis/strings[]
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings[]
	
	printf("\n");
	printf(" Digite o CPF a ser cadastrado: ");//coletando informações do usuário
	scanf("%s", cpf);//salvando essas informaçoes
	//%s referese a strings

	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo // o "w" significa escrever
	fprintf(file, "CPF:");//nome da informação a ser coletada
	fprintf (file, cpf); //salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //acessar o arquivo // o "a" significa atualizar as informações do file
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
		printf(" CPF não localizado! \n Não foi possível abrir o arquivo.\n Tente novamente!\n\n\n");
		printf("___________________________________________\n\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n -Estas são as informações do usuário:\n\n ");
		printf("%s", conteudo);
		printf("\n\n");
		printf("___________________________________________\n\n\n");
	}

	system("pause"); 
	
}


int deletar()
{
	char cpf[40];

	printf(" Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file != NULL)
	
	{
		fclose(file);
		remove(cpf);
		printf("\n");
		printf(" Usuário deletado com sucesso!\n\n");
		printf("___________________________________________\n\n\n");
		system("pause");
	}
		
	else
	
	{
        printf("\n");
		printf(" O usuário não se encontra no sistema! \n\n");
		printf("___________________________________________\n\n\n");
        system("pause");
	}
	

}


int main()
{
	int opcao = 0;//definindo as variáveis
	int laco = 1;//variável utilizada para a repeticão
	
	for(laco=1; laco=1;)
	{
		system ("cls");
		
		setlocale(LC_ALL, "Portuguese"); //escolhendo o idioma/linguagem 
	
		printf("   ###\t Cartório da EBAC\t ###\n\n");//início do menu
		printf("___________________________________________\n\n\n");
		printf(" Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n");
		printf("\t4 - Sair do Sistema\n\n\n");
		printf("___________________________________________\n\n\n");
		printf(" Opção escolhida: ");//fim do menu
	
		scanf("%d", &opcao);//armazenando a escolha do usuário
	
		system("cls");//limpando a tela
		
		switch(opcao)//início da seleção
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
			return 0;//quebra laço, e sai do sistema
			break;
			
			default://quando não é nenhuma das opções mapeadas
			printf(" Desculpe, esta opção não está disponível.\n\n Tente novamente!\n\n");
			printf("___________________________________________\n\n\n");
			system("pause");
			break;
					
		}//final da seleção
	
	}
}
