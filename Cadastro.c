#include <stdio.h> //Biblioteca de Comunicação com o Usuário
#include <stdlib.h> //Biblioteca de Alocação de Espaços de Memória
#include <locale.h> //Biblioteca de Alocção de Texto por Região 
#include <string.h> //Biblioteca responsável por cuidar das strings

int registro()				// Função responsável por registrar os usuários no sistema
	{
	printf("\tVocê escolheu Registrar Nomes!\n");			// Exibi para o usuário qual função foi escolhida
	
// Início da criação das variáveis   

	char arquivo[40];								
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
// Final da criação das variáveis/string
 
	printf("\nDigite o CPF a ser cadastrado: ");		// Coletando informação do usuário para cadastrar o CPF
	scanf("%s", cpf);										//"%s" refere-se a string, usada para salvar uma string
		
	strcpy(arquivo, cpf);							// Responsável por copiar os valores das strings
	
	FILE *file; 								// Chamando a função file para depois criar o arquivo 
	file = fopen (arquivo, "w"); 						// Criando um novo arquivo e utilizando o "w" que significa escrever utilizado para criação do arquivo
	fprintf(file,cpf); 										// Salvando o valor variável 
	fclose(file); 										// Fecha o arquivo pois quando aberto sempre terá que fechar
		
	file = fopen(arquivo, "a");							// Abrindo o arquivo para atualizar a irformação ("a",significa atualizar uma nova informação)
	fprintf(file,",");								// Salvando a informação de separção utilizando a "," depois do CPF
	fclose(file);								// Fecha o arquivo
								
	printf("\nDigite o Nome a ser cadastrado: ");		// Menssagem que aparece para o usuário para cadastrar o Nome
	scanf("%s",nome);								// Salvando na string na variável "nome"
	
	file = fopen(arquivo, "a");					// Abrindo o arquivo e atualizando 
	fprintf(file,nome);						// Salvando conteúdo da variável "nome" dentro do arquivo
	fclose(file);								//Fecha o arquivo
	
	file = fopen(arquivo, "a");										
	fprintf(file,",");						// Adicionando uma "," depois do nome 
	fclose(file);													
	
	printf("\nDigite o Sobrenome a ser cadastrado: ");			// Menssagem que aparece para o usuário para cadastrar o Sobrenome
	scanf("%s",sobrenome);									// Salvando na string na variável "sobrenome"
	
	file = fopen(arquivo, "a");							// Abrindo e atulizando o arquivo utilizando "a" 
	fprintf(file,sobrenome);								// Salvando canteúdo da variável "sobrenome" dentro do arquivo
	fclose(file);												// Fechando o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");										// Adicionando uma "," depois do sobrenome 
	fclose(file);
	
	printf("\nDigite o Cargo a ser cadastrado: ");			// Menssagem que aparece para o usuário para cadastrar o Cargo
	scanf("%s",cargo);
	printf("\n");
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);							// Salvando canteúdo da variável "cargo" dentro do arquivo
	fclose(file);
	
	system("pause");		// Comando que pausa na Tela em que o usuário está									
		
}

int consultar()				// Função responsável por consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); 					//Definindo o Idioma
	
	printf("\tVocê escolheu Consultar Nomes!\n");			// Menssagem que aparece para o usuário quando seleciona a opção Consultar Nomes
	
	char cpf[40];									// Criando a variável CPF
	char conteudo[200];								// Criando uma variável para armazenar o conteúdo para o sistema trazer a informação
	
	printf("\nDigite o CPF a ser consultado: ");		// Perguntando para o usuário qual CPF será consultado
	scanf("%s",cpf);										// Salvando dentro da string "cpf"
	
	FILE *file;											// Consultando o arquivo
	file= fopen(cpf,"r");							// Abrindo o arquivo cpf para ler o conteúdo ("r" significa ler)
	
	if(file == NULL)							// Criando uma validação se caso o CPF não for encontrado
	{						
		printf("\nNão foi possivel abrir o arquivo, não localizado!\n");		// Menssagem que aparece para o usuário
		printf("\n");								
	}
	
	while(fgets(conteudo, 200, file) != NULL)					// Salvando o conteúdo os 200 caracterez que estão dentro do arquivo até for NULL(Nulo)
	{
			printf("\nEssas são as informações do usuário: ");		// Menssagem exibida para o usuário
			printf("%s", conteudo);										// salvando o conteúdo que está dentro da string "conteúdo"
			printf("\n\n");											 
	}
	
	system("pause");		// Comando que pausa na Tela em que o usuário está
	
	}

int deletar()				// Função responsável por Deletar os usuários no sistema
{
	printf("\tVocê escolheu Deletar Nomes!\n");
	
	char cpf[40];									// Criando variável CPF
	
	printf("\nDigite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);								// Remove o arquivo CPF
	
	FILE *file;									// Abrindo o arquivo referente ao CPF e dando comando "r" para leitura
	file = fopen(cpf,"r");
	
	if(file == NULL)							// Em caso de numero digirado não encontrado no arquivo
	{
		printf("\nCPF não encontrado ou já foi deletado!\n\n");				// Menssagem exibida para o Usuário
		
		system("pause");														// Comando que pausa na Tela em que o usuário está
	}

}

int main()
{
		
	int opcao=0; 			// Definindo variáveis
	int laco=1;					// Definindo a variável "laço"
	
	for(laco=1;laco=1;)		// Crinado laço de repetição
	 
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); 		//Definindo o Idioma 

		printf("\tCartório da EBAC\n\n"); 			//Início do Menu
		printf("Escolha a opção desejada:\n\n\n");
		printf("\t1 - Registrar Nomes\n\n");
		printf("\t2 - Consultar Nomes\n\n");
		printf("\t3 - Deletar Nomes\n\n");
		printf("\t4 - Sair do Sistema\n\n\n"); 
		printf("Selecione uma Opção: "); 			//Fim do Menu 
	
		scanf( "%d", &opcao); 		//Armazenando as escolhas do usuário
	
		system("cls");					// Responsável por limpar a tela	
		
		switch(opcao)				// Definindo opções de escolhas
		{
		//Início das escolhas
			case 1:
			registro();				// Chamada de função 
			break;						// Encerra a opção (break)
			
			case 2:
			consultar();			
			break;
			
			case 4:
			printf("\n\tObrigado por uitlizar nosso sistema!\n");		// Adicionando a função para sair do sistema 
			return 0;										
			break;
			
			case 3:
			deletar();				
			break;
			
			default:
			printf("Essa opção não existe!\n\n"); 
			system("pause");
			break;	
		//Fim das escolhas		 		
		}					
		
	}
	
}
