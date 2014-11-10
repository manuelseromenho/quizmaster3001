#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*http://www.cquestions.com/2011/09/how-to-convert-string-to-int-without.html*/
/*int stringToInt(char str[]){
    int i=0,sum=0;

    while(str[i]!='\0'){
         if(str[i]< 48 || str[i] > 57){
             printf("Unable to convert it into integer.\n");
             return 0;
         }
         else{
             sum = sum*10 + (str[i] - 48);
             i++;
         }
    }
    return sum;
}*/

typedef struct
{
	int idUser;
	char nome[15];
	char pass[15];	
}user;


/***** Menu Aluno *****/
void jogar(void)
{
	system ("cls");
	
	printf("Menu Jogar");
	getch();
	main();
}

void relatorio(void)
{
	system ("cls");
	
	printf("Menu Relatorio");
	getch();
	main();
}

void ranking(void)
{
	system ("cls");
	
	printf("Menu Ranking");
	getch();
	main();
}
/**********************/

void aluno(char username[15])
{
	int op=0;
	
	system("cls");
	
	printf("\t\t\tOlá, %s\n\n", username);
	
	printf("Selecciona uma das seguintes opcoes:\n\n");
	printf("1) Jogar \t");
	printf("2) Relatorio \t");
	printf("3) Ranking \t");
	printf("4) Sair \t");
	printf("\n\n-> ");
	
	fflush(stdin);
	scanf("%d", &op);

	
	switch(op)
	{
		case 1: jogar();break;
		case 2: relatorio();break;
		case 3: ranking();break;
		case 4: main();break;

		default:exit(0);
	}
}



/***** Menu Administrador *****/
void inserirAluno(void)
{
	system ("cls");
	
	printf("\t\t\t\t Inserir Aluno");
	getch();
	main();
}

void consultarAluno(void)
{
	system ("cls");
	
	printf("\t\t\t\t Consultar Aluno");
	getch();
	main();
}

void consultEditQuestoes(void)
{
	system ("cls");
	
	printf("\t\t\t\t Consultar/Editar Questões");
	getch();
	main();
}

void inserirQuestoes(void)
{
	system ("cls");
	
	printf("\t\t\t\t Inserir Questoes");
	getch();
	main();
}

void listarAlunos(void)
{
	system ("cls");
	
	printf("\t\t\t\t Listar Alunos");
	getch();
	main();
}
/******************************/

void admin(void)
{
	system("cls");
	
	int op=0;
	
	printf("\t\t\t\tOlá Administrador!\n\n\n\n\n\n\n");
	
	printf("Seleccione uma das seguintes opcoes:\n\n");
	printf("1) Inserir Aluno\t");
	printf("2) Consultar Aluno\t");
	printf("3) Consultar/Editar Questões\t\n\n");
	printf("4) Inserir Questão \t");
	printf("5) Listar Alunos \t");
	printf("6) Sair \t");
	printf("\n\n-> ");
	
	fflush(stdin);
	scanf("%d", &op);
	
	switch(op)
	{
		case 1: inserirAluno();break;
		case 2: consultarAluno();break;
		case 3: consultEditQuestoes();break;
		case 4: inserirQuestoes();break;
		case 5: listarAlunos();break;
		case 6: main();break;

		default:exit(0);
	}
}

/***** LOGIN *****/
int login(char username[15], char password [15])
{
	user tabela[10]={
	{.idUser=21210,.nome="Manuel",.pass="123456"},
	{.idUser=34638,.nome="Bruna",.pass="654321"},
	{.idUser=52572,.nome="Ricardo",.pass="321456"},
	{.idUser=1,.nome="admin",.pass="admin"}
	};
	
	//int nr_registos = sizeof(tabela)/sizeof(struct user);
	int i,j=0, idUser, test_user, test_pass;
	char nome[15];
	char pass[15];
	
	for(i=0; i<4;i++)
	{
		strcpy(nome,tabela[i].nome);
		strcpy(pass,tabela[i].pass);
		idUser = tabela[i].idUser;
	
		int test_user=strcmp (nome,username);
		int test_pass=strcmp (pass,password);
		
		if(test_user == 0)
		{
			if(test_user == 0 && test_pass == 0) 
			{
				if(idUser==1)
				{
					return 1;
				}
				else
				{
					return idUser;
				}
			}
			else
			{
				return 0;
			}
		}
		else if (i>=3)
		{
			return 0;
		}
			
	}
}
/*****************/


main() 
{
	
	int op,i;
	char username[15];
	char password[15];
	int loginFlag;
	int idUser;
	
	system ("chcp 1252>null");
	system ("cls");

	
	printf("\t\t\t\tQuiz Master 3001\n\n");
	printf("\n\n\nUsername: ");
	fflush(stdin);
	scanf("%[^\n]s", username);
	fflush(stdin);
	printf("Password: ");
	scanf("%[^\n]s", password);
	
	
	loginFlag = login(username,password);
	
	if(loginFlag == 1)
	{
		admin();
	}
	else
	{
		if(loginFlag==0)
		{
			printf("\nTemos um problema :( ... o seu nome de utilizador/password* não existe...\n\n\n\t\tToque em qualquer tecla para tentar de novo...");
			getch();
			main();
		}
		else
		{
			idUser=loginFlag;
			printf("O id de aluno é :\t %d", idUser);
			aluno(username);
		}
	}
}
