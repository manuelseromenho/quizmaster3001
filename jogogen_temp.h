/*!
* \file
* \brief ficheiro main do Quizmaster 3001
* \details primeiras instru��es do programa Quizmaster 3001
* \author Manuel Seromenho
* \date 14 Janeiro 2015
* \bug sem erros detetados
* \warning nenhum warning
* \version 1.0
* \copyright GNU Public License.
*/


//JOGO GEN�RICO

void jogogen(int iduser, perguntas_rand *rand_x, alunotab *alu, int indice);
void ranking(int iduser, alunotab *alu, char* nome, int indice);


/***** Menu Aluno/User *****/
void jogar(int iduser, alunotab *alu, char* nome, int indice)
{
	int i=0;	
	
	system ("cls");
	system("chcp 1252>null");
	
	printf("\t\t\t\t  Menu _ Jogar\n\n");
	printf("\n\t\t Ol� %s! Vamos jogar?\n", nome);
	printf("\n\n\t (*para ganhares tens de acertar pelo menos 6 perguntas)\n");
	printf("\n\t\t Prima qualquer tecla para come�ar o jogo...");
	getch();
	
	// LEITURA DAS PERGUNTAS ALEAT�RIAS 
	perguntas_rand rand_x[NR]; // inicializa um array de estrutura tipo "perguntas_rand"
		
	for(i=0;i<NR;i++)
		rand_x[i].estado=0; // coloca todas as vari�veis "estado" de todos os membros do array a zero.
	
	jogogen(iduser,rand_x, alu, indice);
	// *********************************
	getch();
	
}


//! relatorio
/**
* funcao para relatorio de informa��o do aluno
* \param iduser : int
* \param *alu : alunotab
* \param nome : *char
* \param indice : indice
* \return void
*/

void relatorio(int iduser, alunotab *alu, char* nome, int indice)
{
	int total_jogos = alu[indice].jganhos + alu[indice].jperdidos;
	float media_respcertas = (alu[indice].rcertas) / (float)total_jogos; 
	float media_resperradas = (alu[indice].rerradas) / (float)total_jogos;
	float media_tempojogo = ((alu[indice].tempojogo) / (float)60)/(float)total_jogos;

	system ("cls");
	
		
	printf(" \t ______________________________________________________\n\n");
	printf(" \t|-------------------  Menu Relat�rio ------------------|\n\n");
	printf(" \t ______________________________________________________\n");
	printf("\n \t Nome: %s ", alu[indice].nome);
	printf("\n \t N�mero de jogos: %d", total_jogos);
	printf("\n \t Repostas Certas: %d", alu[indice].rcertas);
	printf("\n \t M�dia de respostas certas por jogo: %.1f", media_respcertas);
	printf("\n \t Repostas Erradas: %d", alu[indice].rerradas);
	printf("\n \t M�dia de respostas erradas por jogo: %.1f", media_resperradas);
	printf("\n \t Tempo de jogo do aluno: %.2f minutos", alu[indice].tempojogo/60);
	printf("\n \t M�dia de tempo por jogo do aluno: %.2f minutos", media_tempojogo);
	printf("\n \t ______________________________________________________\n");
	printf("\n\n\n-> ");
	

	
	getch();
	aluno(iduser, alu);
}

/**********************/

//! menu aluno
/**
* funcao menu aluno
* \param iduser : int
* \param *alu : alunotab
* \return void
*/
void aluno(int iduser, alunotab *alu)
{
	int op=0, indice, temp;
	char nome[30];
	
	system("cls");
	
	for(indice=1;indice<NA;indice++) // se alu[indice] existir -> mostra o nome 
	{
		if(alu[indice].estado == 1)
		{
			if(alu[indice].iduser == iduser)
			{
				temp = indice; // variavel temporaria para guardar indice, no momento em que a condi��o � verdadeira
				strcpy(nome , alu[indice].nome);
				printf("\t\t\tOl�, %s\n\n", nome);
			}
		}	
	}
	
	indice = temp;
	
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
		case 1: jogar(iduser, alu, nome, indice);break;
		case 2: relatorio(iduser, alu, nome, indice);break;
		case 3: ranking(iduser, alu, nome, indice);break;
		case 4: intro();

		default:exit(0);
	}
}

//! 
/**
* funcao para relatorio de informa��o do aluno
* \param iduser : float
* \param *alu : alunotab
* \param nome : *char
* \param indice : indice
* \return void
*/
void classi(int rerrada, char out[30])
{
	if(rerrada==0)
		strcpy(out, "********Einstein***********");
	else if(rerrada>0 && rerrada<=2)
		strcpy(out, "Homo Sapiens Sapiens...");
	else if(rerrada>2 && rerrada<=4)
		strcpy(out, "Homo Sapiens...");
	else if(rerrada>4 && rerrada<=6)
		strcpy(out, "Homo Erectus...");
	else if(rerrada>6 && rerrada<=8)
		strcpy(out, "Homo Habilis...");
	else if(rerrada>8 && rerrada<=10)
		strcpy(out, "Australopiteco!");
}

//! jogo
/**
* funcao do jogo (esta funcao executa o jogo em si)
* \param iduser : int
* \param *rand_x : perguntas_rand
* \param *alu : alunotab
* \param indice : indice
* \return void
*/
void jogogen(int iduser, perguntas_rand *rand_x, alunotab *alu, int indice)	//leitura das perguntas do ficheiro e inicio do jogo
{
	/*****************************/
	/***Inicializa��o Vari�veis***/
	
	int i=0, k=0, n=0,
	usados[NR], //variavel necessaria para analisar quais as perguntas j� escolhidas e n�o repetir.
	nrs_rand[NUMPER_RAND],
	rcertas=0, rerradas=0, jganhos=0, jperdidos=0 , op;
	
	float t_total = 0; //tempo total do jogo
	
	char classific[30];
	
	time_t t; //inicializa a variavel t (tempo) para a fun��o random
	
	/*http://bytes.com/topic/c/answers/879169-how-display-elapsed-time-seconds-c-program*/
	time_t t_inicio = 0; // tempo inicial
    time_t t_fim = 0; // tempo final

	srand(time(NULL));
	srand((unsigned) time(&t)); // inicializa��o variavel random
	
	FILE *fich;
	FILE *fichalu;
	
	/***End Inicializa��o Vari�veis***/
	/*********************************/


	/**********************************************************************/
	/***Leitura do ficheiro perguntas para o array de estrutura rand_x[]***/
	
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
	
	/***End Leitura do ficheiro perguntas para o array de estrutura rand_x[]***/
	/**************************************************************************/

	
	for(i=0; i<NR; i++)
	{
		usados[i] = 0; // init do array, este � utilizado para identificar as perguntas que j� foram lan�adas no jogo(em concreto)
	}
	
	t_inicio = time(NULL); // start CHRON
	
	for(i=0;i<NUMPER_RAND;i++)
	{
		system("cls");

		/***Lan�amento das perguntas aleat�riamente***/
		do
		{
			k = rand()%(NR-1); // insere numeros aleat�rios
			//nrs_rand[n]	= k ;
		}while(rand_x[k].estado != 1 || usados[k] == 1);
		usados[k] = 1;	// coloca uma flag no n�mero aleat�rio j� utilizado(este n�mero representa o nr da pergunta)
		
		/*********************************************/


		/*******JOGO********/
		printf("\nPergunta nr %d\n\n%s\n", i+1, rand_x[k].questao);
		printf("\n1) %s\n2) %s\n3) %s\n",rand_x[k].resposta1,rand_x[k].resposta2,rand_x[k].resposta3);
		
		printf("\nEscolha a resposta correta 1, 2 ou 3\n-> ");
		do{
			//op=getch();
			scanf("%d", &op);
			
		}while (op!=1 && op!=2 && op!=3);

		if(rand_x[k].respostacerta == op)
			rcertas++;
		else
			rerradas++;					
		/******************/
	}
	
	t_fim = time(NULL); //end CHRON
	t_total = t_fim - t_inicio;
	
	printf("\n\nTempo total do jogo em minutos -> %.2f",t_total/60);
	
	getch();
	
	system("cls");
	printf("\n Temos um veredicto!\n");
	
	getch();
	if(rerradas>=5)
		printf("\n Oh...infelizmente perdeste..., n�o desanimes tenta de novo!\n");
	else
		printf("\n Parab�ns!! Ganhaste!\n");

	printf("\n Respostas Certas: %d", rcertas);
	printf("\n Respostas Erradas: %d",rerradas);

	getch();
	classi(rerradas, classific); // funcao para determinar a classifi��o especial
	printf("\n\n A tua classifica��o �: %s \n", classific);
	getch();
	
	
	/*********************************************************************/
	/***Grava��o para ficheiro users, atualizando a informa��o do aluno***/

	fichalu=fopen("users.txt","w+");

	for(n=0;n<NA;n++)
	{
		if(alu[n].estado==1 && n != indice)
		{
			fprintf(fichalu,"%d\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%f\n",alu[n].iduser, alu[n].nome, alu[n].pass, alu[n].turma, alu[n].idade, alu[n].estado, alu[n].rcertas, alu[n].rerradas, alu[n].jganhos, alu[n].jperdidos, alu[n].tempojogo);
		}
		else if (alu[n].estado == 1 && n == indice)
		{
			alu[indice].rcertas = alu[indice].rcertas + rcertas;
			alu[indice].rerradas = alu[indice].rerradas + rerradas;
			alu[indice].tempojogo = alu[indice].tempojogo + t_total;
			
			if(rerradas>=5)
			{		
				jperdidos= jperdidos + 1;
				alu[indice].jperdidos = alu[indice].jperdidos + jperdidos;
			}
			else
			{
				jganhos= jganhos + 1;
				alu[indice].jganhos = alu[indice].jganhos + jganhos;
			}
			
			fprintf(fichalu,"%d\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%f\n",alu[indice].iduser, alu[indice].nome, alu[indice].pass, alu[indice].turma, alu[indice].idade, alu[indice].estado, alu[indice].rcertas, alu[indice].rerradas, alu[indice].jganhos, alu[indice].jperdidos, alu[indice].tempojogo);
		}		
	}

	fclose(fichalu);
	
	/***End Grava��o para ficheiro users, atualizando a informa��o do aluno***/
	/*************************************************************************/
	
	aluno(iduser,alu); //volta para o menu anterior
}

//! ranking alunos
/**
* funcao ranking, analisa a pontua��o de casa jogador e lista ordenadamente
* \param iduser : int
* \param *alu : alunotab
* \param nome : char*
* \param indice : indice
* \return void
*/
void ranking(int iduser, alunotab *alu, char* nome, int indice)
{
	int n , i , k=0, temp[NA]={0}, tempo=0;
	
	system ("cls");
	
	printf("\t\tMenu Ranking\n\n");
	
	printf("Posi��o\t Jogador \t Jogos \t Perg.Certas \t Perg.Erradas \t Classifica��o\n");
	
	/*for(i=1;i<=NA-1;i++)
	{	
		for(n=NA;n>i;n--)
		{
			if(alu[n].estado == 1)
			{
				if(alu[n-1].jganhos>alu[n].jganhos)
				{
					tempo=alu[n-1];
					
				}
			}
		}
	}*/
	
	/*for(i=0;i<5;i++)
	{	
		
		for(n=k;n<NA;n++)
		{
			if(alu[n].estado == 1)
			{
				if(tempo>alu[n].jganhos)
				{
					printf("%d\n", alu[n].jganhos);

					temp[i] = n;
				}
				else if(tempo<alu[n].jganhos)
				{
					printf("%d\n", alu[n].jganhos);

					temp[i] = n;
					tempo=alu[n].jganhos;
				}
			}
		}
	}*/
	
	for(i=0;i<5;i++)
	{		
		for(n=k;n<NA;n++)
		{
			if(alu[n].estado == 1)
			{
				if(alu[k].jganhos>alu[n].jganhos)
				{
					//printf("%d\n", alu[n].jganhos);
					temp[i] = k;
				}
				else
				{
					//printf("%d\n", alu[n].jganhos);
					if(alu[n].jganhos>temp[i])
					{
						temp[i] = n;
					}
				}
			}
		}
		k=k+1;
	}
	
	for(i=0;i<5;i++)
	{
		printf("\n%s\n",alu[temp[i]].nome);
	}
	

	getch();
	aluno(iduser,alu);
}
