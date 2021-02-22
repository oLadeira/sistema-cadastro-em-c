#include <stdio.h>
#include <string.h>
#include <stdlib.h> // biblioteca para o comando system("cls")
#define SIZE 200

typedef struct paciente PACIENTE;

struct paciente{
	char nome[SIZE];
	char idade[SIZE];
	char cpf[SIZE];
	char endereco[SIZE];
	char telefone[SIZE];
	char email[SIZE];
};

int op;

void telaLogin();
void menu();
void pesquisa();
void cadastroPaci();
// void cadastroAgend
// void cadastroMedi
// void cadastroFunci
// void reclama_elogio
// void canc_consulta


int main(void){
	telaLogin();
	menu();
	cadastroPaci();
	pesquisa();			
}

void telaLogin(){
	
	char login[46];
	char senha[46];
	int conf_geral= 0;
	int a=10;
	int b=10;
	int c=10;
	int d=10;
	int e=10;
	
	//Usuários para logar no sistema:
	// Paula123
	// Henrique923
	// MatheusAlmeida2
	// GeralUser939
	// Senha Geral : senhaadm123

	do{
		system("cls");
		printf("\n*Digite o seu login: ");
		scanf("%s", &login);
		printf("*Digite a sua senha: ");
		scanf("%s", &senha);
		
		a= strcmp(login, "Paula123");
		b= strcmp(login, "Henrique923");
		c= strcmp(login, "MatheusAlmeida2");
		d= strcmp(login, "GeralUser939");
		e= strcmp(senha, "senhaadm123");
		
		if (a==0 && e==0){
			printf("\nLogou");
			system("cls");
			conf_geral++;
			}
		else if (b==0 && e==0){
			printf("Logou");
			system("cls");
			conf_geral++;
			}
		else if (c==0 && e==0){
			printf("Logou");
			system("cls");
			conf_geral++;
			}
		else if (d==0 && e==0){
			printf("Logou");
			system("cls");
			conf_geral++;
			}		
		else{
			printf("\nLogin ou senha incorretos.");
			conf_geral = 0;
		}	
					
	}while(conf_geral == 0);		
}// fim da função login

void menu(){
	do{
		printf("\n---MENU---\n");
		printf("\n");
		printf("1 - Cadastrar paciente\n");
		printf("2 - Consultar pacientes\n");
		printf("3 - Sair\n");		
		scanf("%d", &op);
		switch(op){
			case 1:
				cadastroPaci();
				break;
			case 2:
				pesquisa();
				break;
			case 3:
				exit(0);
			default:
				printf("Digite uma opcao valida");
				break;		
		}
		
	}while(op!=3);	
}// fim da função menu

void cadastroPaci(){
	FILE *arquivo;// ponteiro do arquivo .txt.
	FILE *arquivo2;
	static int linha;
	PACIENTE paciente;
	arquivo= fopen("db_Paciente.txt", "a");// abre o arquivo texto. "a" adiciona o texto a um arquivo ja existente.
	arquivo2= fopen("db_binPacientes.txt", "ab");
	do{
		system("cls"); // comando para limpar a tela
		fflush(stdin);
		printf("\nDigite o nome do paciente: ");
		gets(paciente.nome); // limpar buffer do teclado, para registrar frases que possuem espaços.
		fprintf(arquivo, "\n%s\n", paciente.nome);// comando para salvar a variável no arquivo .txt
		
		fflush(stdin);
		printf("\nDigite a idade do paciente: ");
		gets(paciente.idade);
		fprintf(arquivo, "%s\n", &paciente.idade);
		
		fflush(stdin);
		printf("\nDigite o CPF do paciente: ");
		gets(paciente.cpf);
		fprintf(arquivo, "%s\n", &paciente.cpf);
		
		fflush(stdin);
		printf("\nDigite o endereco do paciente: ");
		gets(paciente.endereco);
		fprintf(arquivo, "%s\n", &paciente.endereco);
		
		fflush(stdin);
		printf("\nDigite o telefone do paciente: ");
		gets(paciente.telefone);
		fprintf(arquivo, "%s\n", &paciente.telefone);
		
		fflush(stdin);
		printf("\nDigite o e-mail do paciente: ");
		gets(paciente.email);
		fprintf(arquivo, "%s\n", &paciente.email);
		
		fwrite(&paciente, sizeof(PACIENTE), 1, arquivo2);
		printf("\nDigite 1 para continuar ou qualquer valor para sair. ");
		scanf("%d", &op);
		fclose(arquivo);
		fclose(arquivo2);
			
	}while(op==1);
				
}// fim da função cadastro

void pesquisa(){
	char cpfPesquisa[SIZE];
	char telefonePesquisa[SIZE];
	PACIENTE paciente;
	do{
		printf("\nDigite 1 para pesquisar o paciente pelo CPF ou 2 para pesquisar pelo telefone. ");
		scanf("%d", &op);
		FILE *arquivo2;
		arquivo2=fopen("db_binPacientes.txt", "r");
		switch(op){
			case 1:
				printf("Digite o CPF do paciente: ");
				scanf("%s", &cpfPesquisa);
				while(fread(&paciente, sizeof(PACIENTE), 1, arquivo2)==1){
					if (strcmp(cpfPesquisa, paciente.cpf)==0){
					printf("\nNome: %s\nIdade: %s\nCPF: %s\nEndereco: %s\nTelefone: %s\nE-mail: %s", paciente.nome, paciente.idade, paciente.cpf, paciente.endereco, paciente.telefone, paciente.email);
				}
			}
				break;
			case 2:
				printf("Digite o telefone do paciente: ");
				scanf("%s", &telefonePesquisa);
				while(fread(&paciente, sizeof(PACIENTE), 1, arquivo2)==1){
					if (strcmp(telefonePesquisa, paciente.telefone)==0){
					printf("\nNome: %s\nIdade: %s\nCPF: %s\nEndereco: %s\nTelefone: %s\nE-mail: %s", paciente.nome, paciente.idade, paciente.cpf, paciente.endereco, paciente.telefone, paciente.email);
				}
			}
				break;
			
			default:
				printf("\nOpcao invalida.");
				break;		
		}
		printf("\nDigite 1 para continuar pesquisando ou outro valor para sair. ");
		scanf("%d", &op);
		fclose(arquivo2);
}while(op==1);
			
}// fim da função consulta
