#include <stdio.h> 
#define NR 100           	   // Numero maximo de Registos 
typedef struct
{
	long int numero;
	char nome[60];
	char turma [20];		
	int idade;
	int estado;
			             // 0=livre	1=ocupado	
}aluno;

void ler (aluno *x)
{
	FILE *f;
	int n;
	f=fopen("C:\\alunos.txt","r");	
	for(n=1;n<NR;n++)
	{
		fscanf(f,"%ld\n", &x[n].numero);
		fscanf(f,"%[^\n]s",x[n].nome);	
	//	fscanf(f,"%[^\n]s",x[n].turma);     
		fscanf(f,"\n%d\n%d\n", &x[n].idade);	
		fscanf(f,"\n%d\n%d\n", &x[n].estado);	      
	}
	fclose(f);
	printf("\n\n\nFicheiro Lido <Enter para Continuar>");getch();
}

void mostrar(aluno *x)
{
	int n;
	system ("cls");
	for(n=1;n<NR;n++)
	{
		if(x[n].estado==1)
		{
			printf("NUMERO=%ld\nNOME=%s\nturma=%s\nIdade=%d\n\n",
			x[n].numero,x[n].nome,x[n].turma,x[n].idade);
		}
	}
	printf("\n\n\nListagem Concluida <Enter para Continuar>");getch();
}

int inserir(aluno *x)
{
	int n,k;
	long int inser;
	system ("cls");
	printf("Numero do aluno? ");
	scanf("%ld%*c",&inser);
	for(n=1;n<NR;n++)

	{
	
		if(x[n].estado!=1)
		{
			x[n].numero=inser;
			printf("\n\nNOME=?"); gets(x[n].nome);    // scanf("%[^\n]s",x[n].nome);
			printf("\n\nturma=?"); 
			scanf("\n%[^\n]s",x[n].turma);
			printf("\n\nIdade=?"); scanf("%d", &x[n].idade);
			
			x[n].estado=1;
			
			printf("\n\n\nRegisto Inserido <Enter para Continuar>");
			getch();
			return(1);
		}
	
	}
	printf("ERRO! Nao foi possivel Inserir"); getch(); return(0);
}

int eliminar(aluno *x)
{
	char confere;
	int n;
	long int eli;
	system("cls");
	printf("Qual o Numero do aluno que quer Eliminar? "); scanf("%ld",&eli);
	for(n=1;n<NR;n++)
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


void gravar(aluno *x)
{
	FILE *f;
	int n;
	if(!(f=fopen("C:\\alunos.txt","w")))
	{
		printf("\n\n\nErro na Abertura para Gravar <Enter para Sair>");
		getch();  exit(0);
	}

	for(n=1;n<NR;n++)
	{
		if(x[n].estado==1)
		{
			fprintf(f,"%ld\n%s\n%s\n%d\n%d\n",x[n].numero,x[n].nome,x[n].turma,

						      x[n].idade, x[n].estado);
		}
	}
	fclose(f);
	printf("\n\n\nFicheiro Gravado <Enter para Continuar>"); getch();
}

main() //ter atenção que o main não fica neste ficheiro
{
	char op;
	int n;
	aluno alu[NR];
	for(n=0;n<NR;n++)
		alu[n].estado=0;   /* limpa todo o Array de registos */
	do{
		system("cls");
		printf("Alunos\n\n");
		printf("L - Ler Ficheiro\n");
		printf("M - Mostrar Registos\n");
		printf("I - Inserir Registo\n");
		printf("E - Eliminar Registo\n");
		printf("G - Gravar Ficheiro\n");
		printf("S - Sair\n\n");
		printf("Qual a sua opcao? "); op=toupper(getch());
		switch(op)
		{
			case 'L': ler(alu); break;
			case 'M': mostrar(alu); break;
			case 'I': inserir(alu); break;
			case 'E': eliminar(alu); break;
			case 'G': gravar(alu); break;
			case 'S': exit(0);
		}
	}while (op!='S' && op!='s');
}
