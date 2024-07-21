#include <stdio.h> //biblioteca de comunica��o de usu�rio
#include <stdlib.h> //biblioteca de aloca��o de empa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas strings


int registro() //Fun��o respons�vel pelo cadastro
{
//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome [50];
	char sobrenome[40];
	char cargo[40];
//final das variaveis

	printf("Digite o CPF do usu�rio:");//coleta de informa��es
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf);//respons�vel por copiar valores das string
	
	FILE*file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo "w" escreve/cria
	fprintf(file, cpf); //salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%S", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");//coleta de info
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Qual seu cargo? ");
	scanf("%s", cargo);
	
	file=fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
		
	system("pause");
}

int consulta() // fun��o respons�vel pela consulta
{
	setlocale(LC_ALL, "Portuguese_Brazil"); //lingua
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE*file;
	file=fopen(cpf, "r");// "r" l� o arquivo
	
	if(file == NULL)
	{
	printf("CPF n�o localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	printf("\nInforma��es do usu�rio: ");
	printf("%s", conteudo);	
	printf("\n\n");
	}
	
	system("pause");
}

int deletar() //fun��o respons�vel por deletar
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE*file;
	file=fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o encontrado no sistema!\n");
		system("pause");
	}
	
}

int main ()
{
	 setlocale(LC_ALL, "Portuguese_Brazil"); //Definindo a linguagem
	 int opcao=0; //Definindo as vari�veis
	 int rep=1;
	 
	 for (rep=1; rep=1;)
	 {
	 
	 system("cls");
	 setlocale(LC_ALL, "Portuguese_Brazil"); //Definindo a linguagem
	 
	 printf("### Registro de usu�rio ###\n\n"); //Inicio do menu
	 printf ("Escolha sua op��o: \n\n");
	 printf("\t1 - Registro de usu�rio\n");
	 printf("\t2 - Consulta de usu�rio\n");
	 printf("\t3 - Deletar usu�rio\n");
	 printf ("\t4 - Sair do programa\n\n"); 
	 printf("Op��o: ");//Final do menu
	 
	 scanf("%d", &opcao); //armazenando a escolha do usu�rio
	 system("cls");//responsavel por limpar a tela do app
	 
	 switch (opcao)
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
	 	printf("Obrigado por utilizar o sistema\n");
	 	return 0;
	 	break;
	 	
	 	default:
	 	printf ("Op��o n�o dispon�vel!\n");
	 	system ("pause");
	 	break;
	 }
	 
}
}
