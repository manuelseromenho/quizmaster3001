void aluno(int iduser, alunotab *alu);

/***** Menu Administrador *****/
void admin(alunotab *alu)
{
	int n, op = 0;
	
	do{
	
	system("cls");
	/*system("chcp 1252");*/ 
	/*system("color f0");*/
	system("cls");
	
	printf(" \t\t\tOlá Administrador!\n\n");
	printf(" \t ______________________________________________________\n\n");
	printf(" \t|--------------------  Menu Admin  --------------------|\n\n");
	printf(" \t ______________________________________________________\n");
	printf(" \t|    |  1  |    ---> Gerir Alunos                      |\n");
	printf(" \t ______________________________________________________\n");
	printf(" \t|    |  2  |    ---> Gerir Perguntas                   |\n");
	printf(" \t ______________________________________________________\n");
	printf(" \t|    |  3  |    ---> Sair                              |\n");
	printf(" \t ______________________________________________________\n");
	printf("\n\n\n-> ");
	
	fflush(stdin);
	scanf("%d", &op);
	
	switch(op)
	{
		case 1: gest_alunos(alu);break;
		case 2: mainperguntas();break;
		case 3: intro();
		}
	
	}while (op!='6');
}

/***** LOGIN *****/
int login(int id_user, char password [15], alunotab *alu)
{
	int i,j=0, test_user, test_pass;
	char login_pass[15]={};
	
	for(i=0; i<NA;i++)
	{
		strcpy(login_pass,alu[i].pass);
			
		if (alu[i].iduser == id_user)
			test_user = 0;
		else
			test_user = 1;
		
		int test_pass=strcmp (login_pass,password);
		
		if(test_user == 0)
		{
			if(test_user == 0 && test_pass == 0) 
			{
				if(id_user==1)
				{
					return 1;
				}
				else
				{
					return id_user;
				}
			}
			else
			{
				return 0;
			}
		}
		/*else if (i>=3)
		{
			return 0;
		}*/
			
	}
}
/*****************/

void intro(void)
{
	system ("cls");
	
	int op , i , n , loginFlag , iduser;
	char password[15]={};	
	
	alunotab alu[NA]={0};
	perguntas perg[NP]={0};
	
	leraluno(alu); //popula a tabela alunos/users com a informação do ficheiro de texto
	
	printf("\t\t\tQuiz Master 3001\n\n");
	
	printf(" \t ______________________________________________________\n\n");
	printf(" \t|-------------------  Login ---------------------------|\n\n");
	printf(" \t ______________________________________________________\n");
	//printf(" \n\n\t\t *para sair do programa use o atalho ctrl + c");
	printf("\n\n\n\n\n\t\tiD de Utilizador: ");
	fflush(stdin);
	scanf("%d", &iduser);
	fflush(stdin);
	printf("\t\tPassword: ");
	scanf("%[^\n]s", password);
	fflush(stdin);
	printf("\n \t ______________________________________________________\n");
	printf("\n\n\n-> ");
	
	
	loginFlag = login(iduser, password, alu);
	
	if(loginFlag == 1)
	{
		admin(alu);
	}
	else
	{
		if(loginFlag==0)
		{
			printf(" Temos um problema :( ... o seu id utilizador/password* não existe...\n\n\n\t\tToque em qualquer tecla para tentar de novo...");
			getch();
			intro();
		}
		else
		{
			iduser = loginFlag;
			aluno(iduser, alu);
		}
	}
}


