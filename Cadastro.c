#include <stdio.h> //Biblioteca de Comunica��o com o Usu�rio
#include <stdlib.h> //Biblioteca de Aloca��o de Espa�os de Mem�ria
#include <locale.h> //Biblioteca de Aloc��o de Texto por Regi�o 
#include <string.h> //Biblioteca respons�vel por cuidar das strings

int registro()				// Fun��o respons�vel por registrar os usu�rios no sistema
	{
	printf("\tVoc� escolheu Registrar Nomes!\n");			// Exibi para o usu�rio qual fun��o foi escolhida
	
// In�cio da cria��o das vari�veis   

	char arquivo[40];								
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
// Final da cria��o das vari�veis/string
 
	printf("\nDigite o CPF a ser cadastrado: ");		// Coletando informa��o do usu�rio para cadastrar o CPF
	scanf("%s", cpf);										//"%s" refere-se a string, usada para salvar uma string
		
	strcpy(arquivo, cpf);							// Respons�vel por copiar os valores das strings
	
	FILE *file; 								// Chamando a fun��o file para depois criar o arquivo 
	file = fopen (arquivo, "w"); 						// Criando um novo arquivo e utilizando o "w" que significa escrever utilizado para cria��o do arquivo
	fprintf(file,cpf); 										// Salvando o valor vari�vel 
	fclose(file); 										// Fecha o arquivo pois quando aberto sempre ter� que fechar
		
	file = fopen(arquivo, "a");							// Abrindo o arquivo para atualizar a irforma��o ("a",significa atualizar uma nova informa��o)
	fprintf(file,",");								// Salvando a informa��o de separ��o utilizando a "," depois do CPF
	fclose(file);								// Fecha o arquivo
								
	printf("\nDigite o Nome a ser cadastrado: ");		// Menssagem que aparece para o usu�rio para cadastrar o Nome
	scanf("%s",nome);								// Salvando na string na vari�vel "nome"
	
	file = fopen(arquivo, "a");					// Abrindo o arquivo e atualizando 
	fprintf(file,nome);						// Salvando conte�do da vari�vel "nome" dentro do arquivo
	fclose(file);								//Fecha o arquivo
	
	file = fopen(arquivo, "a");										
	fprintf(file,",");						// Adicionando uma "," depois do nome 
	fclose(file);													
	
	printf("\nDigite o Sobrenome a ser cadastrado: ");			// Menssagem que aparece para o usu�rio para cadastrar o Sobrenome
	scanf("%s",sobrenome);									// Salvando na string na vari�vel "sobrenome"
	
	file = fopen(arquivo, "a");							// Abrindo e atulizando o arquivo utilizando "a" 
	fprintf(file,sobrenome);								// Salvando cante�do da vari�vel "sobrenome" dentro do arquivo
	fclose(file);												// Fechando o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");										// Adicionando uma "," depois do sobrenome 
	fclose(file);
	
	printf("\nDigite o Cargo a ser cadastrado: ");			// Menssagem que aparece para o usu�rio para cadastrar o Cargo
	scanf("%s",cargo);
	printf("\n");
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);							// Salvando cante�do da vari�vel "cargo" dentro do arquivo
	fclose(file);
	
	system("pause");		// Comando que pausa na Tela em que o usu�rio est�									
		
}

int consultar()				// Fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); 					//Definindo o Idioma
	
	printf("\tVoc� escolheu Consultar Nomes!\n");			// Menssagem que aparece para o usu�rio quando seleciona a op��o Consultar Nomes
	
	char cpf[40];									// Criando a vari�vel CPF
	char conteudo[200];								// Criando uma vari�vel para armazenar o conte�do para o sistema trazer a informa��o
	
	printf("\nDigite o CPF a ser consultado: ");		// Perguntando para o usu�rio qual CPF ser� consultado
	scanf("%s",cpf);										// Salvando dentro da string "cpf"
	
	FILE *file;											// Consultando o arquivo
	file= fopen(cpf,"r");							// Abrindo o arquivo cpf para ler o conte�do ("r" significa ler)
	
	if(file == NULL)							// Criando uma valida��o se caso o CPF n�o for encontrado
	{						
		printf("\nN�o foi possivel abrir o arquivo, n�o localizado!\n");		// Menssagem que aparece para o usu�rio
		printf("\n");								
	}
	
	while(fgets(conteudo, 200, file) != NULL)					// Salvando o conte�do os 200 caracterez que est�o dentro do arquivo at� for NULL(Nulo)
	{
			printf("\nEssas s�o as informa��es do usu�rio: ");		// Menssagem exibida para o usu�rio
			printf("%s", conteudo);										// salvando o conte�do que est� dentro da string "conte�do"
			printf("\n\n");											 
	}
	
	system("pause");		// Comando que pausa na Tela em que o usu�rio est�
	
	}

int deletar()				// Fun��o respons�vel por Deletar os usu�rios no sistema
{
	printf("\tVoc� escolheu Deletar Nomes!\n");
	
	char cpf[40];									// Criando vari�vel CPF
	
	printf("\nDigite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);								// Remove o arquivo CPF
	
	FILE *file;									// Abrindo o arquivo referente ao CPF e dando comando "r" para leitura
	file = fopen(cpf,"r");
	
	if(file == NULL)							// Em caso de numero digirado n�o encontrado no arquivo
	{
		printf("\nCPF n�o encontrado ou j� foi deletado!\n\n");				// Menssagem exibida para o Usu�rio
		
		system("pause");														// Comando que pausa na Tela em que o usu�rio est�
	}

}

int main()
{
		
	int opcao=0; 			// Definindo vari�veis
	int laco=1;					// Definindo a vari�vel "la�o"
	
	for(laco=1;laco=1;)		// Crinado la�o de repeti��o
	 
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); 		//Definindo o Idioma 

		printf("\tCart�rio da EBAC\n\n"); 			//In�cio do Menu
		printf("Escolha a op��o desejada:\n\n\n");
		printf("\t1 - Registrar Nomes\n\n");
		printf("\t2 - Consultar Nomes\n\n");
		printf("\t3 - Deletar Nomes\n\n");
		printf("\t4 - Sair do Sistema\n\n\n"); 
		printf("Selecione uma Op��o: "); 			//Fim do Menu 
	
		scanf( "%d", &opcao); 		//Armazenando as escolhas do usu�rio
	
		system("cls");					// Respons�vel por limpar a tela	
		
		switch(opcao)				// Definindo op��es de escolhas
		{
		//In�cio das escolhas
			case 1:
			registro();				// Chamada de fun��o 
			break;						// Encerra a op��o (break)
			
			case 2:
			consultar();			
			break;
			
			case 4:
			printf("\n\tObrigado por uitlizar nosso sistema!\n");		// Adicionando a fun��o para sair do sistema 
			return 0;										
			break;
			
			case 3:
			deletar();				
			break;
			
			default:
			printf("Essa op��o n�o existe!\n\n"); 
			system("pause");
			break;	
		//Fim das escolhas		 		
		}					
		
	}
	
}
