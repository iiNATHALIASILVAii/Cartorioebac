#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel pr cuidar das strings

int registrar() // Fun��o responsavel por cadastrar os usu�rios
{
	//Inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim cria��o de vari�veis/string
	
	//Coletando informa��o do usu�rio 
	printf("Digite o CPF a ser cadastrado: "); 
	scanf("%s", cpf); //%s Refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	//Inicio cria��o do arquivo .txt
	FILE *file; 
	file = fopen(arquivo, "w"); //"W" � referente a escrita
	fprintf(file, cpf); //Salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //"A" atualiza informa��o no arquivo
	fprintf(file, ",");
	fclose(file);
	
	//Coletando informa��o do usu�rio
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ",");
	fclose(file);
	
	//Coletando informa��o do usu�rio
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");		
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file; //Busca na biblioteca para criar um arquivo .txt
	file = fopen(cpf, "r"); //R � de leitura do arquivo
	
	if(file == NULL)//caso o cpf n�o seja localizado
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");	
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); //Deleta o registro
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!. \n");
		system("pause");
	}
}

int main ()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)//La�o de repeti��o
	{
	
		system("cls"); //Limpa a tela
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem 
	
		printf("### Cart�rio de alunos da EBAC ###\n\n"); //Barra + n � espa�o; printf � a mensagem
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");//Barra invertida + t traz um espa�o antes da frase
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: ");
	
		scanf("%d", &opcao); //armazenar variavel inteira - decis�o usuario
	
		system("cls");//Fim do menu
		
		switch(opcao) //Inicio da sele��o do menu
		{
			
			case 1:
				registrar(); //Chamada de fun��es	
			break;
			
			case 2:
				consultar();
			break;
			
			case 3:
				deletar();
			break;
			
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
			default:
				printf("Essa op��o n�o esta disponivel!\n");
				system("pause");
			break;			
				
		}//Fim da sele��o
	}
}

