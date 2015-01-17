void gravar (perguntas *x)	//função para gravar no ficheiro
{
 	FILE *fich;
	int n;
	fich=fopen("perguntas.txt","w+");	//abre o ficheiro em modo write
	

	for(n=1;n<NP;n++)
	{
		if(x[n].estado==1)
		{
			fprintf(fich,"%ld\n%s\n%s\n%s\n%s\n%d\n%d\n",x[n].nquestao,x[n].pergunta,x[n].resposta1,x[n].resposta2,x[n].resposta3, x[n].respostacerta, x[n].estado);
		}
	}
	fclose(fich);
}

void inserirperg(perguntas *x)	//função para inserir Questões
{
	
	int n,k;
	long int inser;
	system ("cls");
	for(n=1;n<NP;n++)

	{
	
		if(x[n].estado!=1)
		{
			x[n].nquestao=n;	//vai incrementando sempre um valor ao numero da pergunta
			fflush(stdin); 
			printf("Por favor introduza a pergunta : "); 
			scanf("%[^\n]s",x[n].pergunta);
			fflush(stdin); 
			printf("\nResposta1: "); 
			scanf("%[^\n]s",x[n].resposta1); 
			fflush(stdin); 
			printf("\nResposta2: "); 
			scanf("%[^\n]s",x[n].resposta2);
			fflush(stdin); 
			printf("\nResposta3: "); 
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

void consultarperg(perguntas *x)	//função para consultar as questões
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
	
	gravar (x);
}

int eliminarperg(perguntas *x)	//função elininar questões
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

void lerperguntas(perguntas *x)	//a funçao para ler do ficheiro
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



mainperguntas()
{
	int n;
	perguntas q[NP];
	for(n=0;n<NP;n++)
	q[n].estado=0;
	
	char op;
	lerperguntas(q);
	do{
		system("chcp 1252"); /*system("color f0");*/ system("cls");
		
		printf(" \t ______________________________________________________\n\n");
		printf(" \t|-----------------  Menu de questões  -----------------|\n\n");
		printf(" \t ______________________________________________________\n");
		printf(" \t|    |  I  |    ---> Inserir Perguntas                 |\n");
		printf(" \t ______________________________________________________\n");
		printf(" \t|    |  E  |    ---> Eliminar Perguntas                |\n");
		printf(" \t ______________________________________________________\n");
		printf(" \t|    |  M  |    ---> Mostrar Perguntas                 |\n");
		printf(" \t ______________________________________________________\n");
		printf(" \t|    |  S  |    ---> Sair                              |\n");
		printf(" \t ______________________________________________________\n");
		printf("  \n\t -->  ");
		
		
		fflush(stdin);
		op = toupper(getch());//verificar as maisculas e minusculas
		
		switch(op)
		{
			case 'I': inserirperg(q);break;
			case 'E': eliminarperg(q);break;
			case 'M': consultarperg(q);break;
			case 'S': gravar(q);
		}
		
			
	}while (op!='S' && op!='s');
		
	
}
