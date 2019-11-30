#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Configuração das dimensões da matriz principal do jogo
#define COLUNAS 15
#define LINHAS 25

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

//Configurações do mecanismo de colisão
#define CHECK_SIDE 1
#define UNCHECK_SIDE 0
#define NONE 0

//Estrutura padrão de componentes
typedef struct{
    int i;  //posicao nas linhas da matriz
    int j; //posicao nas colunas da matriz
    int largura; //largura da peça
    int altura; //altura da peça
}Carro;

/*
    Inicializa a matriz principal com 'espaços vazios'
*/
void init(char matriz[LINHAS][COLUNAS]);

/*
    Mostra o conteúdo da matriz principal na tela 
    do computador.
*/
void print_Matriz(char matriz[LINHAS][COLUNAS]);

/*
    Desenhar uma car usando o modelo do caracter ASCII
    passado por parâmetro.
*/
void print_Car(char matriz[LINHAS][COLUNAS], Carro car, int modelo);

/*
    Inicializar a peça do tipo car
*/
void initBar(Carro *car);

/*
    Verifica a colisão de blocos

int collisionDetect(char matriz[LINHAS][COLUNAS], Bloco car);*/
