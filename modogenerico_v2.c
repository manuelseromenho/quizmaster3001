#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define NR 100 // Numero maximo de Registos  
#define STRLN 150
#define NUMPER_RAND 10 //constante para o máximo de 10 perguntas aleatórias
      	
typedef struct
{
	int numero;
	char questao[STRLN];
    char resposta1[STRLN];
    char resposta2[STRLN];
    char resposta3[STRLN];			
	int respostacerta;
	int estado; // 0=livre	1=ocupado	
}perguntas_rand; //estrutura criada para guardar as perguntas aleatórias

typedef struct
{
	int id_rank;		
	int iduser;
	int perg_certas;
	int perg_erradas;
	int jogo_ganho;
	int jogo_perdido;
	int estado;	             	
}aluno_rank;


void classi(int perg_errada, char* out)
{
	if(perg_errada==0)
		strcpy(out, "********Einstein***********");
	else if(perg_errada>0 && perg_errada<=2)
		strcpy(out, "Homo Sapiens Sapiens...");
	else if(perg_errada>2 && perg_errada<=4)
		strcpy(out, "Homo Sapiens...");
	else if(perg_errada>4 && perg_errada<=6)
		strcpy(out, "Homo Erectus...");
	else if(perg_errada>6 && perg_errada<9)
		strcpy(out, "Homo Habilis...");
	else if(perg_errada>9 && perg_errada<=10)
		strcpy(out, "Australopiteco!");

}


void lerperguntas(perguntas_rand *rand_x)	//a funçao para ler do ficheiro
{	
	
	
	int i=0, k=0, n=0,
	usados[NR], //varial necessaria para analisar quais as perguntas já escolhidas, e não repetir.
	nrs_rand[NUMPER_RAND],
	perg_certa=0, perg_errada=0;
	int op;
	
	time_t t; //inicializa a variavel t (tempo) para a função random

	srand(time(NULL));
	srand((unsigned) time(&t)); // inicialização variavel random
	
	FILE *fich;

	fich=fopen("perguntas.txt","r");
			
	for( i = 0 ; i < NR ; i++ )
	{
		fscanf(fich,"%d\n", &rand_x[i].numero);
		fflush(stdin);	
		fscanf(fich,"%[^\n]%*c",&rand_x[i].questao);
		fflush(stdin);							
		fscanf(fich,"%[^\n]%*c",&rand_x[i].resposta1);
		fflush(stdin);	
		fscanf(fich,"%[^\n]%*c",&rand_x[i].resposta2); 
		fflush(stdin);   
 	    fscanf(fich,"%[^\n]%*c",&rand_x[i].resposta3); 
		fflush(stdin); 
		fscanf(fich,"%d\n", &rand_x[i].respostacerta);
		fflush(stdin);	
		fscanf(fich,"%d\n", &rand_x[i].estado);			      
	}
	fclose(fich);
	
	for(i=0; i<NR; i++)
	{
		usados[i] = 0;
	}
	
	for(i=0;i<NUMPER_RAND;i++)
	{
		system("cls");

		do
		{
			k = rand()%(NR-1); // insere numeros aleatórios
			//nrs_rand[n]	= k ;
		}while(rand_x[k].estado!=1 || usados[k] == 1);
		usados[k] = 1;	

	/*******JOGO********/			

		printf("\nPergunta nr %d\n\n%s\n", i+1, rand_x[k].questao);
		printf("\n1) %s\n2) %s\n3) %s\n",rand_x[k].resposta1,rand_x[k].resposta2,rand_x[k].resposta3);
		
		printf("\nEscolha a resposta correta 1, 2 ou 3\n-> ");
		do{
			//op=getch();
			scanf("%d", &op);
			
		}while (op!=1 && op!=2 && op!=3);

		if(rand_x[k].respostacerta == op)
			perg_certa++;
		else
			perg_errada++;
		
		if(perg_errada>=5)
		{
			break;
		}
	/*******************/	
	}
	
	system("cls");
	printf("\nTemos um veredicto!\n");
	char *classific;
	classi(perg_errada, classific);
	printf("A tua classificação é: %s \n", classific);
}



main()
{
	system ("cls");
	system("chcp 1252>null");
	
	int i=0;
	
	printf("\n\t\t\t\t Olá aluno ...... !\n");
	printf("\n\t\t Prima qualquer tecla para começar o jogo...");
	getch();
	
	// LEITURA DAS PERGUNTAS ALEATÓRIAS 
	perguntas_rand rand_x[NR]; // inicializa um array de estrutura tipo "perguntas_rand"
		
	for(i=0;i<NR;i++)
		rand_x[i].estado=0; // coloca todas as variáveis "estado" de todos os membros do array a zero.
	
	lerperguntas(rand_x);
	// *********************************

}

/*
	for(i=0;i<NUMPER_RAND;i++)
	{

		do
		{
			k = rand()%(NR-1); // insere numeros aleatórios
			//nrs_rand[n]	= k ;
		}while(rand_x[k].estado!=1 && usados[k] == 0);
		usados[k] = 1;	

			

		printf("Numero_Questao=%d\nPergunta=%s\nResposta1=%s\nResposta2=%s\nResposta3=%s\nrespostacerta=%d\n\n", 
		rand_x[k].numero,rand_x[k].questao,rand_x[k].resposta1,rand_x[k].resposta2,rand_x[k].resposta3,rand_x[k].respostacerta);
	}
*/
