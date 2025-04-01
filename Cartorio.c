#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel pr cuidar das strings

int registrar() // Função responsavel por cadastrar os usuários
{
	//Inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim criação de variáveis/string
	
	//Coletando informação do usuário 
	printf("Digite o CPF a ser cadastrado: "); 
	scanf("%s", cpf); //%s Refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	//Inicio criação do arquivo .txt
	FILE *file; 
	file = fopen(arquivo, "w"); //"W" é referente a escrita
	fprintf(file, cpf); //Salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //"A" atualiza informação no arquivo
	fprintf(file, ",");
	fclose(file);
	
	//Coletando informação do usuário
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ",");
	fclose(file);
	
	//Coletando informação do usuário
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
	file = fopen(cpf, "r"); //R é de leitura do arquivo
	
	if(file == NULL)//caso o cpf não seja localizado
	{
		printf("Não foi possivel abrir o arquivo, não localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuario: ");
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
		printf("O usuário não se encontra no sistema!. \n");
		system("pause");
	}
}

int main ()
{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)//Laço de repetição
	{
	
		system("cls"); //Limpa a tela
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem 
	
		printf("### Cartório de alunos da EBAC ###\n\n"); //Barra + n é espaço; printf é a mensagem
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");//Barra invertida + t traz um espaço antes da frase
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: ");
	
		scanf("%d", &opcao); //armazenar variavel inteira - decisão usuario
	
		system("cls");//Fim do menu
		
		switch(opcao) //Inicio da seleção do menu
		{
			
			case 1:
				registrar(); //Chamada de funções	
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
				printf("Essa opção não esta disponivel!\n");
				system("pause");
			break;			
				
		}//Fim da seleção
	}
}

