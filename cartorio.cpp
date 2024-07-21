#include <stdio.h> //biblioteca de comunicação de usuário
#include <stdlib.h> //biblioteca de alocação de empaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável pelas strings


int registro() //Função responsável pelo cadastro
{
//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome [50];
	char sobrenome[40];
	char cargo[40];
//final das variaveis

	printf("Digite o CPF do usuário:");//coleta de informações
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf);//responsável por copiar valores das string
	
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

int consulta() // função responsável pela consulta
{
	setlocale(LC_ALL, "Portuguese_Brazil"); //lingua
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE*file;
	file=fopen(cpf, "r");// "r" lê o arquivo
	
	if(file == NULL)
	{
	printf("CPF não localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	printf("\nInformações do usuário: ");
	printf("%s", conteudo);	
	printf("\n\n");
	}
	
	system("pause");
}

int deletar() //função responsável por deletar
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE*file;
	file=fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuário não encontrado no sistema!\n");
		system("pause");
	}
	
}

int main ()
{
	 setlocale(LC_ALL, "Portuguese_Brazil"); //Definindo a linguagem
	 int opcao=0; //Definindo as variáveis
	 int rep=1;
	 
	 for (rep=1; rep=1;)
	 {
	 
	 system("cls");
	 setlocale(LC_ALL, "Portuguese_Brazil"); //Definindo a linguagem
	 
	 printf("### Registro de usuário ###\n\n"); //Inicio do menu
	 printf ("Escolha sua opção: \n\n");
	 printf("\t1 - Registro de usuário\n");
	 printf("\t2 - Consulta de usuário\n");
	 printf("\t3 - Deletar usuário\n");
	 printf ("\t4 - Sair do programa\n\n"); 
	 printf("Opção: ");//Final do menu
	 
	 scanf("%d", &opcao); //armazenando a escolha do usuário
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
	 	printf ("Opção não disponível!\n");
	 	system ("pause");
	 	break;
	 }
	 
}
}
