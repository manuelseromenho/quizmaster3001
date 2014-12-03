#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define NP 100 
#define per 100        	   
typedef struct
{
	long int nquestao;
	char pergunta[150];
	char resposta1[60];
	char resposta2[60];
    char resposta3[60];			
	int respostacerta;
	int estado;
			             	
}perguntas;							// 

void inserir(perguntas *x)        //função para inserir Questões
{
	
	int n,k;
	long int inser;
	system ("cls");
	for(n=1;n<NP;n++)

	{
	
		if(x[n].estado!=1)
		{
			x[n].nquestao=n;//vai incrementando sempre um valor ao numero da pergunta
			fflush(stdin); 
			printf("Por favor introduza a pergunta : "); 
			scanf("%[^\n]s",x[n].pergunta);
			fflush(stdin); 
			printf("\nResposta1: "); 
			scanf("%[^\n]s",x[n].resposta1); 
			fflush(stdin); 
			printf("\nresposta2: "); 
			scanf("%[^\n]s",x[n].resposta2);
			fflush(stdin); 
			printf("\nresposta3: "); 
			scanf("%[^\n]s",x[n].resposta3);
            fflush(stdin);
			printf("\nResposta Certa: "); 
			scanf("%d", &x[n].respostacerta);
			
			x[n].estado=1;
			
			printf("\n\n\nRegisto Inserido <Enter para Continuar>");
			getch();
			return;
		}
	
	}
	
} 

void consultarperg(perguntas *x)		//função para consultar as questões
{
	int n;
	system ("cls");
	for(n=1;n<NP;n++)
	{
		if(x[n].estado==1)
		{
			printf("Numero_Questao=%ld\nPergunta=%s\nResposta1=%s\nResposta2=%s\nResposta3=%s\nrespostacerta=%d\n\n",
			x[n].nquestao,x[n].pergunta,x[n].resposta1,x[n].resposta2,x[n].resposta3,x[n].respostacerta);
		}
	}
	printf("\n\n\nListagem Concluida <Enter para Continuar>");getch();
}

int eliminar(perguntas *x)				//função elininar questões
{
	char confere;
	int n;
	long int eli;
	system("cls");
	printf("Qual o Numero da questão que quer Eliminar? "); scanf("%ld",&eli);
	for(n=1;n<NP;n++)
	{
		if(x[n].nquestao==eli)
		{
				printf("Numero_Questao=%ld\nPergunta=%s\nResposta1=%s\nResposta2=%s\nResposta3=%s\nrespostacerta=%d\n\n",
			x[n].nquestao,x[n].pergunta,x[n].resposta1,x[n].resposta2,x[n].resposta3,x[n].respostacerta);
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

void lerperguntas(perguntas *x)					//a funçao para ler do ficheiro
{	
	int n;
	FILE *fich;
		fich=fopen("perguntas.txt","r");
		for(n=1;n<NP;n++)
	{
		fscanf(fich,"%d\n", &x[n].nquestao);
		fflush(stdin);	
		fscanf(fich,"%[^\n]%*c",&x[n].pergunta);
		fflush(stdin);							
		fscanf(fich,"%[^\n]%*c",&x[n].resposta1);
		fflush(stdin);	
		fscanf(fich,"%[^\n]%*c",&x[n].resposta2); 
		fflush(stdin);   
 	    fscanf(fich,"%[^\n]%*c",&x[n].resposta3); 
		fflush(stdin); 
		fscanf(fich,"%d\n", &x[n].respostacerta);
		fflush(stdin);	
		fscanf(fich,"%d\n", &x[n].estado);	      
	}
	fclose(fich);
}

void gravar (perguntas *x)				//função para gravar no ficheiro
{
 		FILE *fich;
	int n;
	fich=fopen("perguntas.txt","w+");//abre o ficheiro em modo write
	

	for(n=1;n<NP;n++)
	{
		if(x[n].estado==1)
		{
			fprintf(fich,"%ld\n%s\n%s\n%s\n%s\n%d\n%d\n",x[n].nquestao,x[n].pergunta,x[n].resposta1,x[n].resposta2,x[n].resposta3, x[n].respostacerta, x[n].estado);
		}
	}
	fclose(fich);
	
}

main()
{
	int n;
	perguntas q[NP];
	for(n=0;n<NP;n++)
	q[n].estado=0;
	
	char op;
	lerperguntas(q);
	do{
	
system("chcp 1252"); system("color f0"); system("cls");
         printf(" ______________________________________________________\n\n");
         printf("|-----------------Menu de questoes---------------------|\n\n");
         printf(" ______________________________________________________\n");
		 printf("|    |  I  |    ---> Inserir Perguntas                 |\n");
		 printf(" ______________________________________________________\n");
		 printf("|    |  E  |    ---> Eliminar Perguntas                |\n");
		 printf(" ______________________________________________________\n");
		 printf("|    |  M  |    ---> Mostrar Todas as Perguntas        |\n");
		 printf(" ______________________________________________________\n");
		 printf("|    |  S  |    ---> Sair                              |\n");
         printf(" ______________________________________________________\n");
         
	printf("\n\nPor Favor introduza a sua escolha:  -->  ");
	
	fflush(stdin);
	op=toupper(getch());//verificar as maisculas e minusculas
	
	switch(op)
	{
		case 'I': inserir(q);break;
		case 'E': eliminar(q);break;
		case 'M': consultarperg(q);break;
		case 'S': gravar(q);
		}
		
			
	}while (op!='S' && op!='s');
		
	
}
