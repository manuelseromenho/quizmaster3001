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



 #define NA 100 
 #define NB 100          	   
typedef struct
{
	long int numero;
	char pass[60];
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
	
	printf("\t\t\tOl�, %s\n\n", username);
	
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
void inserir(alunotab *x)        //fun��o para inserir alunos|useres
{
	
	int n,k;
	long int inser;
	system ("cls");
	printf("Numero do aluno? ");
	scanf("%ld%*c",&inser);
	fflush(stdin);
	for(n=1;n<NA;n++)

	{
	
		if(x[n].estado!=1)
		{
			x[n].numero=inser;
			printf("PASSWORD:"); 
			scanf("%[^\n]s",x[n].pass);
			fflush(stdin); 
			printf("\nNome:"); 
			scanf("%[^\n]s",x[n].nome); 
			fflush(stdin); 
			printf("\nTurma:"); 
			scanf("%[^\n]s",x[n].turma);
			fflush(stdin);
			printf("\nIdade:"); 
			scanf("%d", &x[n].idade);
			
			x[n].estado=1;
			
			printf("\n\n\nRegisto Inserido <Enter para Continuar>");
			getch();
			return;
		}
	
	}
	
} 

void consultarAluno(alunotab *x)		//fun��o para consultar os alunos
{
	int n;
	system ("cls");
	for(n=1;n<NA;n++)
	{
		if(x[n].estado==1)
		{
			printf("NUMERO=%ld\nPASSWORD=%s\nNOME=%s\nturma=%s\nIdade=%d\n\n",
			x[n].numero,x[n].pass,x[n].nome,x[n].turma,x[n].idade);
		}
	}
	printf("\n\n\nListagem Concluida <Enter para Continuar>");getch();
}

int elimAlunos(alunotab *x)				//fun��o para eliminar
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
			printf("\n\nNUMERO=%ld\nPASSWORD=%s\nNOME=%s\nturma=%s\nidade=%d\nESTADO=%d\n\n",
			x[n].numero,x[n].pass,x[n].nome,x[n].turma,x[n].idade,x[n].estado);
			printf("\n\nQuer mesmo eliminar? <S/N>");confere=getch();

			if (confere!='S' && confere!='s')   
			 return(0);
			
			
			x[n].estado=0;
		
			printf("\n\n\nRegisto eliminado <enter para continuar>");
			
			getch();  return (1);
		}
	}
	printf("ERRO! Numero nao Encontrado <Enter para Continuar>");
	getch(); return(0);
}

void edit(alunotab *x)							//fun��o para editar a password
{
	
	int n;
	long int eli;
	system("cls");
	printf("Insira o numero de aluno que pretende mudar a password? "); scanf("%ld",&eli);
	for(n=1;n<NA;n++)
	{
		if(x[n].numero==eli)
		{
			printf("\n\nNUMERO=%ld\nPASSWORD=%s\nNOME=%s\nturma=%s\nidade=%d\n\n",x[n].numero,x[n].pass,x[n].nome,x[n].turma,x[n].idade);
			printf("\n\n Digite a nova password: ");
			fflush(stdin); 
			scanf("%[^\n]s",x[n].pass);
			printf("\nNova password inserida");
			getch();
			return;
		}
	}
}
void consultEditQuestoes(void)
{
	system ("cls");
	
	printf("\t\t\t\t Consultar/Editar Quest�es");
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
void leraluno(alunotab *x)					//a fun�ao para ler do ficheiro
{	
	int n;
	FILE *fich;
		fich=fopen("alunos.txt","r");
		for(n=1;n<NB;n++)
	{
		fscanf(fich,"%ld\n", &x[n].numero);
		fflush(stdin);	
		fscanf(fich,"%s\n",x[n].pass);
		fflush(stdin);							
		fscanf(fich,"%s\n",x[n].nome);
		fflush(stdin);	
		fscanf(fich,"%s\n",x[n].turma); 
		fflush(stdin);    
		fscanf(fich,"%d\n", &x[n].idade);
		fflush(stdin);	
		fscanf(fich,"%d\n", &x[n].estado);	      
	}
	fclose(fich);
}

void gravar (alunotab *x)				//fun��o para gravar no ficheiro
{
 		FILE *fich;
	int n;
	fich=fopen("alunos.txt","w+");
	

	for(n=1;n<NB;n++)
	{
		if(x[n].estado==1)
		{
			fprintf(fich,"%ld\n%s\n%s\n%s\n%d\n%d\n",x[n].numero,x[n].pass,x[n].nome,x[n].turma, x[n].idade, x[n].estado);
		}
	}
	fclose(fich);
	main();
}

/******************************/

void admin(void)
{
	int n;
	alunotab alu[NA];
	for(n=0;n<NA;n++)
	alu[n].estado=0;
	
	int op=0;
	leraluno(alu);
	do{
	
	system("cls");
	printf("\t\t\t\tOl� Administrador!\n\n\n\n\n\n\n");
	
	printf("Seleccione uma das seguintes opcoes:\n\n");
	printf("1) Inserir Aluno\t");
	printf("2) Consultar Alunos\t");
	printf("3) Eliminar Alunos\t");
	printf("4) Editar password \t\n\n");
	printf("5) Inserir Quest�o \t");
	printf("6) Consultar/Editar Quest�es \t");
	printf("7) Sair \t");
	printf("\n\n-> ");
	
	fflush(stdin);
	scanf("%d", &op);
	
	switch(op)
	{
		case 1: inserir(alu);break;
		case 2: consultarAluno(alu);break;
		case 3: elimAlunos(alu);break;
		case 4: edit(alu);break;
		case 5: inserirQuestoes();break;
		case 6: consultEditQuestoes();break;
		case 7: gravar(alu);
	
		}
		
			
	}while (op!='7');
		
	
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
			printf("\nTemos um problema :( ... o seu nome de utilizador/password* n�o existe...\n\n\n\t\tToque em qualquer tecla para tentar de novo...");
			getch();
			main();
		}
		else
		{
			idUser=loginFlag;
			printf("O id de aluno � :\t %d", idUser);
			aluno(username);
		}
	}
}
