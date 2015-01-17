void intro(void);
void admin(alunotab *alu);

void leraluno(alunotab *x)
/** \brief funcao para ler do ficheiro do aluno/user */
{	
	/**
 	\ esta função irá ler de um ficheiro .txt todos os alunos/user já inseridos e passar para a memoria
	\ recebe oomo parametros de entrada uma estrutura do tipo alunotab
	\ 
	*/

	int n, k;
	char nome[15]={};
	FILE *fich;
	
	fich=fopen("users.txt","r");
	
	for(n=1;n<NB;n++)
	{
		if(fscanf(fich,"%d\n", &k)==-1) //
			break;
		x[n].iduser = k;

		fscanf(fich," %[^\n]s",nome);
		strcpy (x[n].nome, nome);
			
		fscanf(fich,"%s\n",x[n].pass);				
		fscanf(fich,"%s\n",x[n].turma);   
		fscanf(fich,"%d\n", &x[n].idade);
		fscanf(fich,"%d\n", &x[n].estado);	      
		fflush(stdin);	
		fscanf(fich,"%d\n", &x[n].rcertas);   
		fflush(stdin);	
		fscanf(fich,"%d\n", &x[n].rerradas);  
		fflush(stdin);	
		fscanf(fich,"%d\n", &x[n].jganhos);   
		fflush(stdin);	
		fscanf(fich,"%d\n", &x[n].jperdidos);
		fflush(stdin);
		fscanf(fich,"%f\n", &x[n].tempojogo);		
	}
	fclose(fich);
}

/** \brief função para inserir novos alunos */
void inserirAluno(alunotab *x)        
{
	/**
 	\função para inserir novos alunos
	\recebe uma varialvel do tipo alunotab
	*/
	int n,k;
	int inser;
		
	do{
		system ("cls");
		printf("Numero do aluno? ");
		fflush(stdin);
	}while(!scanf("%d%*c",&inser));

	for(k=1;k<NA;k++)
	{
		if(x[k].iduser==inser)
		{
			printf("\n\nO número já existe");
			getch();
			return;
		}
	}
	
	for(n=1;n<NA;n++)
	{
		if(x[n].estado!=1)
		{
			x[n].iduser=inser;
			printf("\nNome:"); 
			scanf("%[^\n]s",x[n].nome); 
			fflush(stdin);
			printf("PASSWORD:"); 
			scanf("%[^\n]s",x[n].pass);
			fflush(stdin);
			printf("\nTurma:"); 
			scanf("%[^\n]s",x[n].turma);
			fflush(stdin);
			printf("\nIdade:"); 
			scanf("%d", &x[n].idade);
			
			x[n].estado=1;
			x[n].rcertas=0;
			x[n].rerradas=0;
			x[n].jganhos=0;
			x[n].jperdidos=0;
			x[n].tempojogo=0;
			
			printf("\n\n\nRegisto Inserido <Enter para Continuar>");
			getch();
			return;
		}
	
	}
	
} 

/** \brief funcao para consultar os alunos */
void consultarAluno(alunotab *x)	
{
	/**
 	\Função que permite consultar todos os alunos já inseridos
	\recebe uma varialvel do tipo alunotab
	*/

	int n;
	float tempojogominut=0;
	
	system ("cls");
	
	 // tempo total jogado em minutos
	
	for(n=1;n<NA;n++)
	{
		if(x[n].estado==1)
		{
			tempojogominut = (x[n].tempojogo)/60;
			
			printf("NUMERO=%d\nNOME=%s\nPASSWORD=%s\nturma=%s\nIdade=%d\nPerguntas certas=%d\nperguntas erradas=%d\njogos ganhos=%d\njogos perdidos=%d\nTempo de jogo=%.1f min.\n\n",
			x[n].iduser,x[n].nome,x[n].pass,x[n].turma,x[n].idade,x[n].rcertas,x[n].rerradas,x[n].jganhos,x[n].jperdidos, tempojogominut);
		}
	}
	printf("\n\n\nListagem Concluida <Enter para Continuar>");getch();
}


/** \brief função para eliminar os alunos */
int elimAlunos(alunotab *x)	
{
	/**
 	\Função para eliminar alunos que estejam presentes na memoria
	\recebe uma varialvel do tipo alunotab
	*/

	char confere;
	int n;
	float tempojogominut=0;
	long int eli;

	system("cls");
	
	tempojogominut= x[n].tempojogo/60; // tempo total jogado em minutos
	
	printf("Qual o Numero do aluno que quer Eliminar? "); scanf("%ld",&eli);
	for(n=1;n<NA;n++)
	{
		if(x[n].iduser==eli)
		{
			printf("NUMERO=%d\nNOME=%s\nPASSWORD=%s\nturma=%s\nIdade=%d\nPerguntas certas=%d\nperguntas erradas=%d\njogos ganhos=%d\njogos perdidos=%d\nTempo de jogo=%f min.\n\n",
			x[n].iduser,x[n].nome,x[n].pass,x[n].turma,x[n].idade,x[n].rcertas,x[n].rerradas,x[n].jganhos,x[n].jperdidos, tempojogominut);
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

/** \brief função para editar alunos */
void editAluno(alunotab *x) 
{
	/**
 	\Função para editar as passwordsd e turmas dos alunos
	\recebe uma varialvel do tipo alunotab
	*/
	int n,op;

	float tempojogominut=0;
	long int eli;
	
	system("cls");
	
	tempojogominut= x[n].tempojogo/60;
	
	
	op=0;
	
	do{
	
		system("cls");
			
		printf("Seleccione uma das seguintes opcoes:\n\n\n\n\n");
		printf("1) Alterar Password\t\t");
		printf("2) Alterar Turma\t\t");
		printf("3) Sair\n\n>");
		
		
		fflush(stdin);
		scanf("%d", &op);
		
		switch(op)
		{
			case 1: system("cls");
					printf("Insira o numero de aluno que pretende mudar a password?\n\n\n>"); scanf("%ld",&eli);
							for(n=1;n<NA;n++)
							{
								if(x[n].iduser==eli)
								{
									printf("NUMERO=%d\nNOME=%s\nPASSWORD=%s\nturma=%s\nIdade=%d\nPerguntas certas=%d\nperguntas erradas=%d\njogos ganhos=%d\njogos perdidos=%d\nTempo de jogo=%f min.\n\n",
									x[n].iduser,x[n].nome,x[n].pass,x[n].turma,x[n].idade,x[n].rcertas,x[n].rerradas,x[n].jganhos,x[n].jperdidos, tempojogominut);
									printf("\n\n Digite a nova password:\n\n\n>");
									fflush(stdin); 
									scanf("%[^\n]s",x[n].pass);
									printf("\nNova password inserida");
									getch();
									return;
								}
							};break;
					
			case 2: system("cls");
					printf("Insira o numero de aluno que pretende alterar a turma?\n\n\n\n>"); scanf("%ld",&eli);
							for(n=1;n<NA;n++)
							{
								if(x[n].iduser==eli)
								{
									printf("NUMERO=%d\nNOME=%s\nPASSWORD=%s\nturma=%s\nIdade=%d\nPerguntas certas=%d\nperguntas erradas=%d\njogos ganhos=%d\njogos perdidos=%d\nTempo de jogo=%f min.\n\n",
									x[n].iduser,x[n].nome,x[n].pass,x[n].turma,x[n].idade,x[n].rcertas,x[n].rerradas,x[n].jganhos,x[n].jperdidos, tempojogominut);
									printf("\n\n Digite uma nova tuma: ");
									fflush(stdin); 
									scanf("%[^\n]s",x[n].turma);
									printf("\nNova turma inserida");
									getch();
									return;
								}
							};break;
					
			case 3: return;break;
			}	
	}while (op!='3');
				
}	

/** \brief função para gravar */
void gravarAluno(alunotab *x)				
{
	/**
 	\Função para gravar todos os alunos da memoria para um ficheiro .txt
	\recebe uma varialvel do tipo alunotab
	*/

 	int n;
	FILE *fich;
	fich=fopen("users.txt","w+");
	

	for(n=1;n<NB;n++)
	{
		if(x[n].estado==1)
		{
			fprintf(fich,"%d\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%f\n",x[n].iduser,x[n].nome, x[n].pass,x[n].turma, x[n].idade, x[n].estado,x[n].rcertas,x[n].rerradas,x[n].jganhos,x[n].jperdidos,x[n].tempojogo);
		}
	}
	fclose(fich);
	
	admin(x);
}

/******************************/

/** \brief função gestao de alunos */
void gest_alunos(alunotab *alu)
{
	/**
 	\Função do menu gestão de alunos, contendo as várias opções de gestão do aluno
	*/
	
	int n, op = 0;
	
	do{
	
	system("cls");
	
	printf(" \t ______________________________________________________\n\n");
	printf(" \t|------------------  Gestão de alunos  ----------------|\n\n");
	printf(" \t ______________________________________________________\n");
	printf(" \t|    |  1  |    ---> Inserir Aluno                     |\n");
	printf(" \t ______________________________________________________\n");
	printf(" \t|    |  2  |    ---> Lista de Alunos                   |\n");
	printf(" \t ______________________________________________________\n");
	printf(" \t|    |  3  |    ---> Eliminar Alunos                   |\n");
	printf(" \t ______________________________________________________\n");
	printf(" \t|    |  4  |    ---> Editar Password/Turma do Aluno    |\n");
	printf(" \t ______________________________________________________\n");
	printf(" \t|    |  5  |    ---> Sair e gravar                     |\n");
	printf(" \t ______________________________________________________\n");
	printf("\n\n\n-> ");
	
	fflush(stdin);
	scanf("%d", &op);
	
	switch(op)
	{
		case 1: inserirAluno(alu);break;
		case 2: consultarAluno(alu);break;
		case 3: elimAlunos(alu);break;
		case 4: editAluno(alu);break;
		case 5: gravarAluno(alu);
		}
	
	}while (op!='6');
}
