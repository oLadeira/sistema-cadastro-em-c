#include <stdio.h>
#include <string.h>
#include <stdlib.h> // biblioteca para o comando system("cls")
#define SIZE 200
#include <locale.h> // utilizar acentuação da lingua pt BR

typedef struct paciente PACIENTE;
typedef struct medico MEDICO;

struct paciente{
	char nome[SIZE];
	char idade[SIZE];
	char cpf[SIZE];
	char endereco[SIZE];
	char telefone[SIZE];
	char email[SIZE];
};

struct medico{
	char nome[SIZE];
	char data_nasci[SIZE];
	char crm[SIZE];
	char situacao[SIZE];
	char cpf[SIZE];
	char rg[SIZE];
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
void cadastroMedi();
void pesquisaMedi();
// void cadastroFunci
// void reclama_elogio
// void canc_consulta

int main(void){
	setlocale(LC_ALL, ""); // acentuação pt-BR
	telaLogin();
	menu();
	cadastroPaci();
	cadastroMedi();
	pesquisa();
	pesquisaMedi();			
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
		printf("2 - Cadastrar medico\n");
		printf("3 - Consultar pacientes\n");
		printf("4 - Consultar medico\n");
		printf("5 - Sair\n");		
		scanf("%d", &op);
		switch(op){
			case 1:
				cadastroPaci();
				break;
			case 2:
				cadastroMedi();
				break;
			case 3:
				pesquisa();
				break;
			case 4:
				pesquisaMedi();
				break;
			case 5:
				exit(0);	
			default:
				printf("\nDigite uma opção válida\n");
				break;		
		}
		
	}while(op!=3);	
}// fim da função menu

void cadastroPaci(){
	FILE *arquivo;// ponteiro do arquivo .txt.
	FILE *arquivo2;// ponteiro arquivo db_binPacientes.
	PACIENTE paciente;
	do{
		arquivo= fopen("db_Paciente.txt", "a");// abre o arquivo texto. "a" adiciona o texto a um arquivo ja existente.
		arquivo2= fopen("db_binPacientes.txt", "ab");// abre o arquivo texto. "ab" adiciona um texto em binario a um arquivo ja existente.
		system("cls"); // comando para limpar a tela
		fflush(stdin);
		printf("\nDigite o nome do paciente: ");
		gets(paciente.nome); // limpar buffer do teclado, para registrar frases que possuem espaços.
		fprintf(arquivo, "\nNome: %s\n", paciente.nome);// comando para salvar a variável no arquivo .txt
		
		fflush(stdin);
		printf("\nDigite a idade do paciente: ");
		gets(paciente.idade);
		fprintf(arquivo, "Idade: %s\n", &paciente.idade);
		
		fflush(stdin);
		printf("\nDigite o CPF do paciente: ");
		gets(paciente.cpf);
		fprintf(arquivo, "CPF: %s\n", &paciente.cpf);
		
		fflush(stdin);
		printf("\nDigite o endereço do paciente: ");
		gets(paciente.endereco);
		fprintf(arquivo, "Endereço: %s\n", &paciente.endereco);
		
		fflush(stdin);
		printf("\nDigite o telefone do paciente: ");
		gets(paciente.telefone);
		fprintf(arquivo, "Telefone: %s\n", &paciente.telefone);
		
		fflush(stdin);
		printf("\nDigite o e-mail do paciente: ");
		gets(paciente.email);
		fprintf(arquivo, "Email: %s\n", &paciente.email);
		
		fwrite(&paciente, sizeof(PACIENTE), 1, arquivo2);
		printf("\nDigite 1 para continuar cadastrando ou qualquer valor para sair. ");
		scanf("%d", &op);
		system("cls");
		fclose(arquivo);
		fclose(arquivo2);
			
	}while(op==1);
				
}// fim da função cadastro

void pesquisa(){
	FILE *arquivo2;
	char cpfPesquisa[SIZE];
	char telefonePesquisa[SIZE];
	PACIENTE paciente;
	do{
		system("cls");
		arquivo2=fopen("db_binPacientes.txt", "r");
		printf("\nDigite 1 para pesquisar o paciente pelo CPF ou 2 para pesquisar pelo telefone. ");
		scanf("%d", &op);
		switch(op){
			case 1:
				printf("Digite o CPF do paciente: ");
				scanf("%s", &cpfPesquisa);
				while(fread(&paciente, sizeof(PACIENTE), 1, arquivo2)==1){
					if (strcmp(cpfPesquisa, paciente.cpf)==0){
					printf("\nNome: %s\nIdade: %s\nCPF: %s\nEndereco: %s\nTelefone: %s\nE-mail: %s\n", paciente.nome, paciente.idade, paciente.cpf, paciente.endereco, paciente.telefone, paciente.email);
				}			
			}
				break;
			case 2:
				printf("Digite o telefone do paciente: ");
				scanf("%s", &telefonePesquisa);
				while(fread(&paciente, sizeof(PACIENTE), 1, arquivo2)==1){
					if (strcmp(telefonePesquisa, paciente.telefone)==0){
					printf("\nNome: %s\nIdade: %s\nCPF: %s\nEndereco: %s\nTelefone: %s\nE-mail: %s\n", paciente.nome, paciente.idade, paciente.cpf, paciente.endereco, paciente.telefone, paciente.email);
				}
			}
				break;
			
			default:
				printf("\nOpcao invalida.");
				break;		
		}
		printf("\nDigite 1 para continuar pesquisando ou outro valor para sair. ");
		scanf("%d", &op);
		system("cls");
		fclose(arquivo2);
}while(op==1);
			
}// fim da função consulta

void cadastroMedi(){
	FILE *arquivo3; // ponteiro do arquivo db_Medico.
	FILE *arquivo4; // ponteiro do arquivo db_binMedico.
	MEDICO medico;
do{
	arquivo3 = fopen("db_Medico.txt", "a");
	arquivo4 = fopen("db_binMedico.txt", "ab");
	
	system("cls");
	fflush(stdin);
	printf("\nDigite o nome: ");
	gets(medico.nome);
	fprintf(arquivo3, "\nNome: %s\n", medico.nome);
	
	fflush(stdin);
	printf("\nDigite o ano de nascimento: ");
	gets(medico.data_nasci);
	fprintf(arquivo3, "Data de Nascimento: %s\n", medico.data_nasci);
	
	fflush(stdin);
	printf("\nDigite o numero de CRM: ");
	gets(medico.crm);
	fprintf(arquivo3, "CRM: %s\n", medico.crm);
	
	fflush(stdin);
	printf("\nDigite a situacao do medico: ");
	gets(medico.situacao);
	fprintf(arquivo3, "Situação: %s\n", medico.situacao);
	
	fflush(stdin);
	printf("\nDigite o CPF: ");
	gets(medico.cpf);
	fprintf(arquivo3, "CPF: %s\n", medico.cpf);
	
	fflush(stdin);
	printf("\nDigite o RG: ");
	gets(medico.rg);
	fprintf(arquivo3, "RG: %s\n", medico.rg);
	
	fflush(stdin);
	printf("\nDigite o endereco: ");
	gets(medico.endereco);
	fprintf(arquivo3, "Endereço: %s\n", medico.endereco);
	
	fflush(stdin);
	printf("\nDigite o telefone: ");
	gets(medico.telefone);
	fprintf(arquivo3, "Telefone: %s\n", medico.telefone);
	
	fflush(stdin);
	printf("\nDigite o Email: ");
	gets(medico.email);
	fprintf(arquivo3, "Email: %s\n", medico.email);
	
	fwrite(&medico, sizeof(MEDICO), 1, arquivo4);
	printf("\nDigite 1 para continuar cadastrando ou outro valor para sair. ");
	scanf("%d", &op);
	system("cls");
	fclose(arquivo3);
	fclose(arquivo4);
	
}while(op==1);	
}

void pesquisaMedi(){
	FILE *arquivo4; // ponteiro arquivo db_binMedi
	char cpfPesquisa[SIZE];
	char crmPesquisa[SIZE];
	MEDICO medico;
	do{
	system("cls");	
	arquivo4 = fopen("db_binMedico.txt", "r");
	printf("Digite 1 para pesquisar o doutor(a) pelo cpf, ou 2 para pesquisar pelo CRM: ");
	scanf("%d", &op);
	switch(op){
		case 1:
			printf("\nDigite o CPF: ");
			scanf("%s", &cpfPesquisa);
			while(fread(&medico, sizeof(MEDICO), 1, arquivo4)==1){
					if (strcmp(cpfPesquisa, medico.cpf)==0){
					printf("\nNome: %s\nData de Nascimento: %s\nCRM: %s\nSituacao: %s\nCPF: %s\nRG: %s\n Endereco: %s\nTelefone: %s\nEmail: %s" , medico.nome, medico.data_nasci, medico.crm, medico.situacao, medico.cpf, medico.rg, medico.endereco, medico.telefone, medico.email);	
				}
					else if (strcmp(cpfPesquisa, medico.cpf)==1){
						printf("\nInformação não encontrada!.");
						break;
					}
			}
				break;
		case 2:
			printf("\nDigite o CRM: ");
			scanf("%s", &crmPesquisa);
			while(fread(&medico, sizeof(MEDICO), 1, arquivo4)==1){
					if (strcmp(crmPesquisa, medico.crm)==0){
					printf("\nNome: %s\nData de Nascimento: %s\nCRM: %s\nSituacao: %s\nCPF: %s\nRG: %s\n Endereco: %s\nTelefone: %s\nEmail: %s\n" , medico.nome, medico.data_nasci, medico.crm, medico.situacao, medico.cpf, medico.rg, medico.endereco, medico.telefone, medico.email);
				}
					else if (strcmp(crmPesquisa, medico.crm)==1){
						printf("\nInformação não encontrada!.");
						break;
					}	
			}
				break;
		default:
			printf("\nOpção invalida.");
			break;		
	}	
	printf("\nDigite 1 para continuar pesquisando ou outro valor para sair. ");
	scanf("%d", &op);
	system("cls");
	fclose(arquivo4);		
	}while(op==1);	
} // fim da função pesquisaMedi


