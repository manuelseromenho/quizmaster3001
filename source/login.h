void aluno(int iduser, alunotab *alu);

/*!
* \file
* \brief ficheiro login do Quizmaster 3001
* \details instruções para verificar o utilizador Quizmaster 3001
* \author Manuel Seromenho
* \date 14 Janeiro 2015
* \bug sem erros detetados
* \warning nenhum warning
* \version 1.0
* \copyright GNU Public License.
*/


//! Menu Administrador
/**
* funcao do menu Administrador
* \param *alu : alunotab
*/
void admin(alunotab *alu)
{
	int n, op = 0;
	
	do{
	
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

//! Login
/**
* funcao para Login dos Users/Alunos
* \param iduser : int
* \param password : char
* \param *alu : alunotab
* \return login: int
*/
int login(int iduser, char password [15], alunotab *alu)
{
	int i,j=0, test_user, test_pass=0;
	char login_pass[15]={};
	
	for(i=0; i<NA;i++)
	{
		strcpy(login_pass,alu[i].pass);
			
		if (alu[i].iduser == iduser)//testa se o User existe ou não, 0 existe, 1 não existe
			test_user = 0;
		else
			test_user = 1;

		test_pass=strcmp (login_pass,password);
		
		if(test_user == 0)
		{
			if(test_user == 0 && test_pass == 0) 
			{
				if(iduser==1)
				{
					return 1;
				}
				else
				{
					return iduser;
				}
			}
			else
			{
				return 0;
			}
		}
	}
	return 0;
}

//! Menu de Login
/**
* funcao do Menu de Login (onde os users/alunos introduzem a informação para ser verificada pela função login)
*/
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


