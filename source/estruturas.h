/*!
* \file
* \brief ficheiro das estruturas do Quizmaster 3001
* \details inclui os vários tipos de estrutura utilizado no Quizmaster 3001
* \author Manuel Seromenho
* \date 14 Janeiro 2015
* \bug sem erros detetados
* \warning nenhum warning
* \version 1.0
* \copyright GNU Public License.
*/

//** \brief Estrutura para Perguntas **/
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

//** \brief Estrutura para Perguntas Random**/    	
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

//** \brief Estrutura para Alunos/Users **/        	   
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

