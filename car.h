#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Configuração das dimensões da matriz principal do jogo
#define COLUNAS 15
#define LINHAS 25
#define LINS 9
#define COL 80

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

//Criando a orientação das peças
#define ORIENTACAO

//Configurações do mecanismo de colisão
#define CHECK_SIDE 1
#define UNCHECK_SIDE 0
#define NONE 0

//Estrutura padrão dos carros
typedef struct{
    int i;  //posicao nas linhas da matriz
    int j; //posicao nas colunas da matriz
    int largura; //largura da peça
    int altura; //altura da peça
}Carro;

    //Inicializa a matriz do jogo com 'espaços vazios'

void init(char matriz[LINHAS][COLUNAS]);


    //Preenche a matriz que está vazia na tela.

void print_Matriz(char matriz[LINHAS][COLUNAS]);


    //Desenhar uma carro passado por parâmetro.

void print_Car(char matriz[LINHAS][COLUNAS], Carro car, int modelo);



    //Verifica a colisão de blocos

int colisao_carro(char matriz[LINHAS][COLUNAS], Carro car);

    //MENU
void Menu();

    //Main que inicia o jogo
int jogo();