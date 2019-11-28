#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Configuração das dimensões da matriz principal do jogo
#define COLUMNS 15
#define ROWS 25

//Configurações de layout
#define PIXEL 219
#define EMPTY 32

//Configuração de teclas
#define ESC 27
#define ARROWS 224
#define LEFT 75
#define RIGHT 77
#define TECLA_a 97
#define TECLA_d 100
#define TECLA_A 65
#define TECLA_D 68
#define TECLA_ESPACO 32

//Criando as orientações para as peças
#define ORIENTACAO_LEFT 2
#define TIPO_I 7



//Configurações do mecanismo de colisão
#define CHECK_SIDE 1
#define UNCHECK_SIDE 0
#define NONE 0

//Estrutura padrão de componentes
typedef struct{
    int i;  //posicao nas linhas da matriz
    int j; //posicao nas colunas da matriz
    int orientacao; //orientacao da peça
    int tipo; //o tipo de peça (7 possíveis)
    int width; //largura da peça
    int height; //altura da peça
}Bloco;

/*
    Inicializa a matriz principal com 'espaços vazios'
*/
void init(char matrix[ROWS][COLUMNS]);

/*
    Mostra o conteúdo da matriz principal na tela 
    do computador.
*/
void printMatrix(char matrix[ROWS][COLUMNS]);

/*
    Desenhar uma barra usando o simbolo do caracter ASCII
    passado por parâmetro.
*/
void drawBar(char matrix[ROWS][COLUMNS], Bloco barra, int simbolo);

/*
    Inicializar a peça do tipo barra
*/
void initBar(Bloco *barra);

/*
    Verifica a colisão de blocos

int collisionDetect(char matrix[ROWS][COLUMNS], Bloco barra);*/

/*
    Verifica a colisão de barras

int collisionBar(char matrix[ROWS][COLUMNS], Bloco barra, int collideSides, int side);*/