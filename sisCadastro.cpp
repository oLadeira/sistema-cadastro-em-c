#include <stdio.h>
#include <string.h>
#include <stdlib.h> // biblioteca para o comando system("cls")
#define SIZE 200 // definindo a palavra SIZE no valor 200 (usado para definir o tamanho das variáveis char)
#include <locale.h> // utilizar acentuação da lingua pt BR
#include <unistd.h> // usada para função de delay (sleep)

typedef struct paciente PACIENTE;
typedef struct medico MEDICO;
typedef struct avaliacao AVALIACAO;
typedef struct funcionario FUNCIONARIO;

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

struct avaliacao{
	char nome[SIZE];
	char avali[SIZE];
	char obs[SIZE];
};

struct funcionario{
	char nome[SIZE];
	char ano_nasci[SIZE];
	char rg[SIZE];
	char telefone[SIZE];
	char email[SIZE];
	char cpf[SIZE];
	char endereco[SIZE];
	char funcao[SIZE];
	char salario[SIZE];
};

int op;

void telaLogin();
void menu();
void pesquisa();
void cadastroPaci();
// void cadastroAgend();
void cadastroMedi();
void pesquisaMedi();
void cadastroFunci();
void pesquisaFunci();
void avaliacao();
// void canc_consulta();
void pesquisaAvali();

int main(void){
	setlocale(LC_ALL, ""); // acentuação pt-BR
	telaLogin();
	menu();
	cadastroPaci();
	cadastroMedi();
	cadastroFunci();
	pesquisa();
	pesquisaMedi();
	pesquisaFunci();
	avaliacao();
	pesquisaAvali();		
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
			printf("\nUsuário Logado !");
			sleep(1.5);
			system("cls");
			conf_geral++;
			}
		else if (b==0 && e==0){
			printf("\nUsuário Logado !");
			sleep(1.5);
			system("cls");
			conf_geral++;
			}
		else if (c==0 && e==0){
			printf("\nUsuário Logado !");
			sleep(1.5);
			system("cls");
			conf_geral++;
			}
		else if (d==0 && e==0){
			printf("\nUsuário Logado !");
			sleep(1.5);
			system("cls");
			conf_geral++;
			}		
		else{
			printf("\nLogin ou senha incorretos.");
			sleep(2);//usado para causar um delay, dando tempo do usuário ler a mensagem de login incorreto
			conf_geral = 0;
		}	
					
	}while(conf_geral == 0);		
}// fim da função login

void menu(){
	do{
		printf("\n--------------------------------------\n");
		printf("      CONSULTÓRIOS SANTA TEREZA         ");
		printf("\n--------------------------------------\n");
		printf("\n");
		printf("\n");
		printf("\n Digite uma das opções para prosseguir ! \n");
		printf("\n");
		printf("---------------------------\n");
		printf(" 1 - Cadastrar paciente\n");
		printf(" 2 - Cadastrar médico\n");
		printf(" 3 - Cadastrar funcionário\n");
		printf("---------------------------\n");
		printf(" 4 - Consultar pacientes\n");
		printf(" 5 - Consultar médico\n");
		printf(" 6 - Consultar funcionário\n");
		printf("---------------------------\n");
		printf(" 7 - Registrar avaliação\n");
		printf(" 8 - Consultar avaliações\n");
		printf("---------------------------\n");
		printf(" 9 - Sair\n");		
		scanf("%d", &op);
		switch(op){
			case 1:
				cadastroPaci();
				break;
			case 2:
				cadastroMedi();
				break;
			case 3:
				cadastroFunci();
				break;
			case 4:
				pesquisa();
				break;
			case 5:
				pesquisaMedi();
				break;
			case 6:
				pesquisaFunci();
				break;
			case 7:
				avaliacao();
				break;
			case 8:
				pesquisaAvali();
				break;
			case 9:
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

void avaliacao(){
	int validacao=0;
	AVALIACAO avaliacao;
	FILE *arquivo5;
	FILE *arquivo6;
	system("cls");
	do{
	arquivo5 = fopen("db_Avaliacao.txt", "a");
	arquivo6 = fopen("db_BinAvaliacao.txt", "ab");
	
	fflush(stdin);
	printf("\nDigite o nome do cliente: ");
	gets(avaliacao.nome);
	fprintf(arquivo5, "\nNome: %s\n", avaliacao.nome);
	
	fflush(stdin);
	printf("\nA avaliação é positiva ou negativa ? ");
	gets(avaliacao.avali);
	fprintf(arquivo5, "Avaliação: %s\n", avaliacao.avali);

	fflush(stdin);
	printf("\nDigite a observação : ");
	gets(avaliacao.obs);
	fprintf(arquivo5, "Obs: %s\n", avaliacao.obs);
	
	fwrite(&avaliacao, sizeof(AVALIACAO), 1, arquivo6);

	printf("\nDigite 1 para continuar registrando as avaliações, ou qualquer valor para sair. ");
	scanf("%d", &op);
	system("cls");
	fclose(arquivo5);
	fclose(arquivo6);
	}while(op==1);
}//fim da função avaliacao

void pesquisaAvali(){
	
	FILE *arquivo6;
	AVALIACAO avaliacao;
	do{
	arquivo6 = fopen("db_BinAvaliacao.txt", "r");
	system("cls");
	while(fread(&avaliacao, sizeof(AVALIACAO), 1, arquivo6)==1){
		printf("\n\nNome: %s \nAvaliação: %s \nObs: %s", avaliacao.nome, avaliacao.avali, avaliacao.obs);		
	}
	printf("\n\nDigite 1 para retornar para o menu ");
	scanf("%d", &op);
	system("cls");
	fclose(arquivo6);
	}while(op!=1);
}// fim da função consulta avaliacao

void cadastroFunci(){
	system("cls");
	FILE *arquivo7;
	FILE *arquivo8;
	FUNCIONARIO funcionario;
	do{
		arquivo7 = fopen("db_Funcionario.txt", "a");
		arquivo8 = fopen("db_BinFuncionario.txt", "ab");
		
		fflush(stdin);
		printf("\nDigite o nome do funcionário: ");
		gets(funcionario.nome);
		fprintf(arquivo7, "\nNome: %s\n", funcionario.nome);
		
		fflush(stdin);
		printf("\nDigite o ano de nascimento do funcionário: ");
		gets(funcionario.ano_nasci);
		fprintf(arquivo7, "Ano nascimento: %s\n", funcionario.ano_nasci);
		
		fflush(stdin);
		printf("\nDigite o RG do funcionário: ");
		gets(funcionario.rg);
		fprintf(arquivo7, "RG: %s\n", funcionario.rg);
		
		fflush(stdin);
		printf("\nDigite o CPF do funcionário: ");
		gets(funcionario.cpf);
		fprintf(arquivo7, "CPF: %s\n", funcionario.cpf);
		
		fflush(stdin);
		printf("\nDigite o telefone do funcionário: ");
		gets(funcionario.telefone);
		fprintf(arquivo7, "Telefone: %s\n", funcionario.telefone);
		
		fflush(stdin);
		printf("\nDigite o E-mail do funcionário: ");
		gets(funcionario.email);
		fprintf(arquivo7, "E-mail: %s\n", funcionario.email);
		
		fflush(stdin);
		printf("\nDigite o endereço do funcionário: ");
		gets(funcionario.endereco);
		fprintf(arquivo7, "Endereço: %s\n", funcionario.endereco);
		
		fflush(stdin);
		printf("\nDigite o cargo do funcionário: ");
		gets(funcionario.funcao);
		fprintf(arquivo7, "Cargo: %s\n", funcionario.funcao);
		
		fflush(stdin);
		printf("\nDigite o salário do funcionário: ");
		gets(funcionario.salario);
		fprintf(arquivo7, "Salário: %s\n", funcionario.salario);

		fwrite(&funcionario, sizeof(FUNCIONARIO), 1, arquivo8);
		
		printf("\nDigite 1 para continuar cadastrando ou outro valor para sair. ");
		scanf("%d", &op);
		system("cls");
		fclose(arquivo7);
		fclose(arquivo8);
	}while(op==1);
}

void pesquisaFunci(){
	FILE *arquivo8;
	FUNCIONARIO funcionario;
	char pesquisaCPF[SIZE];
	char pesquisaNome[SIZE];
	do{	
		system("cls");	
		arquivo8 = fopen("db_BinFuncionario.txt", "r");
		printf("Digite 1 para pesquisar o funcionário pelo nome, ou 2 para pesquisar pelo CPF: ");
		scanf("%d", &op);
		fflush(stdin);
		switch(op){
			case 1:
				printf("\nDigite o nome do funcionário: ");
				gets(pesquisaNome);
				while(fread(&funcionario, sizeof(FUNCIONARIO), 1, arquivo8)==1){
					if (strcmp(pesquisaNome, funcionario.nome)==0){
					printf("\nNome: %s \nAno Nascimento: %s \nRG: %s \nCPF: %s \nTelefone: %s \nE-mail: %s \nEndereço: %s \nCargo: %s \nSalário: %s\n", funcionario.nome, funcionario.ano_nasci, funcionario.rg, funcionario.cpf, funcionario.telefone, funcionario.email, funcionario.endereco, funcionario.funcao, funcionario.salario);
				}
		}	
				break;
	
			case 2:
				printf("\nDigite o CPF do funcionário: ");
				gets(pesquisaCPF);
				while(fread(&funcionario, sizeof(FUNCIONARIO), 1, arquivo8)==1){
					if (strcmp(pesquisaCPF, funcionario.cpf)==0){
					printf("\nNome: %s \nAno Nascimento: %s \nRG: %s \nCPF: %s \nTelefone: %s \nE-mail: %s \nEndereço: %s \nCargo: %s \nSalário: %s\n", funcionario.nome, funcionario.ano_nasci, funcionario.rg, funcionario.cpf, funcionario.telefone, funcionario.email, funcionario.endereco, funcionario.funcao, funcionario.salario);					
				}
						
		}
				break;
		}		
		printf("\nDigite 1 para continuar pesquisando, ou outro valor para sair");
		scanf("%d", &op);
		system("cls");
		fclose(arquivo8);
	}while(op==1);
}
