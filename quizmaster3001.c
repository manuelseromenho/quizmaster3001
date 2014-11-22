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

/* #define NA 100           	   // para o menu de alunos 
typedef struct
{
	long int numero;
	char nome[60];
	char turma [20];		
	int idade;
	int estado;
			             	
}aluno;							// */



 #define NA 100 
 #define NB 100          	   
typedef struct
{
	long int numero;
	char nome[60];
	char turma [20];		
	int idade;
	int estado;
			             	
}alunotab;							// 










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
 void inserir(alunotab *x)
{
	
	int n,k;
	long int inser;
	system ("cls");
	printf("Numero do aluno? ");
	scanf("%ld%*c",&inser);
	for(n=1;n<NA;n++)

	{
	
		if(x[n].estado!=1)
		{
			x[n].numero=inser;
			printf("\n\nNome:"); 
			gets(x[n].nome);   
			printf("\n\nTurma:"); 
			scanf("\n%[^\n]s",x[n].turma);
			printf("\n\nIdade:"); 
			scanf("%d", &x[n].idade);
			
			x[n].estado=1;
			
			printf("\n\n\nRegisto Inserido <Enter para Continuar>");
			getch();
			return;
		}
	
	}
	printf("ERRO! Nao foi possivel Inserir"); getch(); return;
} 

void consultarAluno(alunotab *x)
{
	int n;
	system ("cls");
	for(n=1;n<NA;n++)
	{
		if(x[n].estado==1)
		{
			printf("NUMERO=%ld\nNOME=%s\nturma=%s\nIdade=%d\n\n",
			x[n].numero,x[n].nome,x[n].turma,x[n].idade);
		}
	}
	printf("\n\n\nListagem Concluida <Enter para Continuar>");getch();
}

void elimAlunos(alunotab *x)
{
	char confere;
	int n;
	long int eli;
	system("cls");
	printf("Qual o Numero do aluno que quer Eliminar? "); scanf("%ld",&eli);
	for(n=1;n<NA;n++)
	{
		if(x[n].numero==eli)
		{
			printf("\n\nNUMERO=%ld\nNOME=%s\nturma=%s\nidade=%d\nESTADO=%d\n\n",
			x[n].numero,x[n].nome,x[n].turma,x[n].idade,x[n].estado);
			printf("\n\nQuer mesmo eliminar? <S/N>");confere=getch();

			if (confere!='S' && confere!='s')    return(0);

			x[n].estado=0;
		
			printf("\n\n\nRegisto eliminado <enter para continuar>");
				
			getch();  return (1);
		}
	}
	printf("ERRO! Numero nao Encontrado <Enter para Continuar>");
	getch(); return(0);
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
/* lergravar(alunotab *x)
{	
	int n;
	FILE *fich;
		fich=fopen("C:\\alunos.txt","w+");
		for(n=1;n<NB;n++)
	{
		fscanf(fich,"%ld\n", &x[n].numero);								a funçao para gravar para o ficheira
		fscanf(fich,"%[^\n]s",x[n].nome);	
		fscanf(fich,"%[^\n]s",x[n].turma);     
		fscanf(fich,"\n%d\n%d\n", &x[n].idade);	
		fscanf(fich,"\n%d\n%d\n", &x[n].estado);	      
	}
	fclose(fich);
}
/*
/******************************/

void admin(void)
{
	int n;
	alunotab alu[NA];
	for(n=0;n<NA;n++)
	alu[n].estado=0;
	
	int op=0;
	do{
	//	lergarvar(alu);
	system("cls");
	printf("\t\t\t\tOlá Administrador!\n\n\n\n\n\n\n");
	
	printf("Seleccione uma das seguintes opcoes:\n\n");
	printf("1) Inserir Aluno\t");
	printf("2) Consultar Alunos\t");
	printf("3) Eliminar Alunos\t\n\n");
	printf("4) Inserir Questão \t");
	printf("5) Consultar/Editar Questões \t");
	printf("6) Sair \t");
	printf("\n\n-> ");
	
	fflush(stdin);
	scanf("%d", &op);
	
	switch(op)
	{
		case 1: inserir(alu);break;
		case 2: consultarAluno(alu);break;
		case 3: elimAlunos(alu);break;
		case 4: inserirQuestoes();break;
		case 5: consultEditQuestoes();break;
		case 6: main();break;
	
		}
		
			
	}while (op!='6');
		
	
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
