#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define NR 20           	   // Numero maximo de Registos  


typedef struct
{
	long int numero;
	char questao[60];
    char resposta1[20];
    char resposta2[20];
    char resposta3[20];			
	int respostacerta;
	int estado;		             // 0=livre	1=ocupado	
}perguntas;
void gotoxy(int x, int y) //função para colocar o cursor num determinado ponto

{

  COORD coord;

  coord.X = x;

  coord.Y = y;

  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}



void ler (perguntas *x)   //função ler o ficheiro
{
	FILE *f;
	int n;
	f=fopen("perguntas.txt","r");
	/*{
		printf("Erro na Abertura de Leitura <Enter para Sair>");
		getch(); exit(0);
	}*/
/*	for(n=1;n<NR;n++)
	{
		fscanf(f,"%ld\n", &x[n].numero);
		fscanf(f,"%[^\n]s",x[n].questao);
        fscanf(f,"%[^\n]s",x[n].resposta1);
        fscanf(f,"%[^\n]s",x[n].resposta2);
        fscanf(f,"%[^\n]s",x[n].resposta3);	     	
		fscanf(f,"\n%d\n%d\n",&x[n].respostacerta, &x[n].estado);		      
	}
	fclose(f);
	printf("\n\n\nFicheiro Lido <Enter para Continuar>");getch();
}
*/
for(n=1;n<NR;n++)
	{
		fscanf(f,"%ld\n",&x[n].numero);
	/*	fscanf(f,"%s\n",x[n].questao);
        fscanf(f,"%s\n",x[n].resposta1);
        fscanf(f,"%s\n",x[n].resposta2);
        fscanf(f,"%s\n",x[n].resposta3);	     	
		fscanf(f,"%d\n",&x[n].respostacerta);	      
        fscanf(f,"%d\n",&x[n].estado);*/		
    }
	fclose(f);
	printf("\n\n\nFicheiro Lido <Enter para Continuar>");getch();
}
void mostrar(perguntas *x)//função para mostrar registos 
{
	int n;
	system ("cls");
	for(n=1;n<NR;n++)
	{
		if(x[n].estado==1)
		{
			printf("NUMERO=%ld\nQuestão=%s\nResposta1=%s\nResposta2=%s\nResposta3=%s\nREspostaCerta=%d\nESTADO=%d\n\n",
			&x[n].numero,x[n].questao,x[n].resposta1,x[n].resposta2,x[n].resposta3,&x[n].respostacerta, &x[n].estado);
		}
	}
	printf("\n\n\nListagem Concluida <Enter para Continuar>");getch();
}

int inserir(perguntas *x) //função para inserir as perguntas
{
	int n;
	long int inser;
	system ("cls");
	printf("Qual o Numero da Pergunta que quer Inserir? ");
	scanf("%ld%*c",&inser);
	for(n=1;n<NR;n++)
	{
		if(x[n].estado!=1)
		{
			x[n].numero=inser;			
            printf("\n\n Por favor introduza a questao = "); gets(x[n].questao); 
            printf("\n\n Por favor introduza a Resposta 1 = "); gets(x[n].resposta1);
            printf("\n\n Por favor introduza a Resposta 2 = "); gets(x[n].resposta2);
            printf("\n\n Por favor introduza a Resposta 3 = "); gets(x[n].resposta3);
			printf("\n\n Por favor introduza o numero da Resposta Certa = "); scanf("%d", &x[n].respostacerta);
			x[n].estado=1;
			printf("\n\n\nRegisto Inserido <Enter para Continuar>");
			getch();
			return(1);
		}
	}
	printf("ERRO! Nao foi possivel Inserir"); getch(); return(0);
}

int eliminar(perguntas *x)//função eliminar registo
{
	char confere;
	int n;
	long int eli;
	system("cls");
	printf("Qual o Numero da questão que quer Eliminar? "); scanf("%ld",&eli);
	for(n=1;n<NR;n++)
	{
		if(x[n].numero==eli)
		{
			printf("NUMERO=%ld\nQuestão=%s\nResposta1=%s\nResposta2=%s\nResposta3=%s\nREspostaCerta=%d\nESTADO=%d\n\n",
			x[n].numero,x[n].questao,x[n].resposta1,x[n].resposta2,x[n].resposta3,x[n].respostacerta, x[n].estado);
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


void gravar(perguntas *x) //função gravar ficheiro
{
	FILE *f;
	int n;
	if(!(f=fopen("perguntas.txt","w+")))
	{
		printf("\n\n\nErro na Abertura para Gravar <Enter para Sair>");
		getch();  exit(0);
	}

	for(n=1;n<NR;n++)
	{
		if(x[n].estado==1)
		{
			fprintf(f,"%ld\n%s\n%s\n%s\n%s\n%d\n%d\n",x[n].numero,x[n].questao,x[n].resposta1,x[n].resposta2,x[n].resposta3,
						      x[n].respostacerta, x[n].estado);
		}
	}
	fclose(f);
	printf("\n\n\nFicheiro Gravado <Enter para Continuar>"); getch();
}

main()
{
	char op;
	int n;
	perguntas per[NR];
	for(n=0;n<NR;n++)
		per[n].estado=0;   /* limpa todo o Array de registos */
	do{
int calen[12][31]; 
		system("chcp 1252"); system("color f0"); system("cls");
         gotoxy(1,1); printf(" ______________________________________________________\n\n");
         gotoxy(1,2); printf("|-----------------Menu de questoes---------------------|\n\n");
         gotoxy(1,3); printf(" ______________________________________________________\n");
		 gotoxy(1,4); printf("|    |  I  |    ---> Inserir Perguntas                 |\n");
		 gotoxy(1,5); printf(" ______________________________________________________\n");
		 gotoxy(1,6); printf("|    |  E  |    ---> Eliminar Perguntas                |\n");
		 gotoxy(1,7); printf(" ______________________________________________________\n");
		 gotoxy(1,8); printf("|    |  M  |    ---> Mostrar Todas as Perguntas        |\n");
		 gotoxy(1,9); printf(" ______________________________________________________\n");
		 gotoxy(1,10); printf("|    |  G  |    ---> Gravar Ficheiro                   |\n");
		 gotoxy(1,11); printf(" ______________________________________________________\n");
	     gotoxy(1,12); printf("|    |  S  |    ---> S para Sair                       |\n");
	     gotoxy(1,13); printf(" ______________________________________________________\n");
		 gotoxy(1,15); printf("|  Qual a sua opcao:   "); op=toupper(getch());
		switch(op)
		{
       case 'I': inserir(per); break;
       case 'E': eliminar(per); break;
	   case 'M': mostrar(per); break;
	   case 'G': gravar(per); break;
	   case 'S': exit(0);
		}
	}while (op!='S' && op!='s');
}
