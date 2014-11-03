#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char username[32];
char password [32];

void aluno(void)
{
	int op;
	
	printf("Olá, %s", username);
	scanf("%d", op);
	
	/*switch(op)
	{
		case 1: jogar();break;
		case 2: relatorio();break;
		case 3: ranking();break;
		case 4: main();break;

		default:exit(0);
	}*/
}

void admin(void)
{
	int op;
	
	printf("Olá Administrador!/n");
	
	/*switch(op)
	{
		case 1: inserirAluno();break;
		case 2: consultarAluno();break;
		case 3: consultEditQuestoes();break;
		case 4: inserirQuestoes();break;
		case 5: listarAlunos();break;
		case 6: main();break;

		default:exit(0);
	}*/
}




main() {
	
	int op,i;

	
	printf("\t\t\t\tQuiz Master 3001\n\n");
	printf("\n\n\nUsername: ");
	scanf("%[^\n]s", &username);
	printf("\nPassword:");
	for(i=3;username[i]!='\0';i++)
	{
		printf("%c", username[i]);
	}
	
	
	

	printf("\n%s\n",username);
	
	
	switch(op)
	{
		case 1: aluno();break;
		case 2: admin();break;
		
		default:exit(0);
	}
	
	
	
	//return 0;
}
