
/***** Estrutura para perguntas ******/ 
typedef struct
{
	int nquestao;
	char pergunta[150];
	char resposta1[60];
	char resposta2[60];
    char resposta3[60];			
	int respostacerta;
	int estado;
}perguntas;	
/*************************************/

/***** Estrutura para perguntas random ******/     	
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
/********************************************/

/***** Estrutura para alunos/users ******/          	   
typedef struct
{
	int iduser;
	char pass[30];
	char nome[30];
	char turma [20];		
	int idade;
	int rcertas;
	int rerradas;
	int jganhos;
	int jperdidos;
	float tempojogo;
	int estado;
}alunotab;
/****************************************/

