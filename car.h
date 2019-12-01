#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Configuração das dimensões da matriz principal do jogo
#define COLUNAS 15
#define LINHAS 25
#define PIXEL 219
#define EMPTY 32
#define LINS 9
#define COL 80

//Configuração de teclas
#define ESC 27
#define ARROWS 224
#define LEFT 75
#define RIGHT 77
#define TECLA_A 65
#define TECLA_a 97
#define TECLA_D 100
#define TECLA_d 68
#define TECLA_ESPACO 32

//Criando a orientação das peças
#define ORIENTACAO

//Configuração de layout
#define CHECK_SIDE 1
#define UNCHECK_SIDE 0
#define NONE 0


//Estrutura padrão de componentes
typedef struct{
    int i; //posição nas linhas da matriz
    int j; //posição nas colunas da matriz
    int largura; //largura da peça
    int altura; //altura da peça
}Carro;


    //Inicializa a matriz principal com 'espaços vazios'
void init(char matriz[LINHAS][COLUNAS]);


    //Mostra a matriz principal na tela 
void print_Matriz(char matriz[LINHAS][COLUNAS], int cont, int faixa);


    //Desenha o carro na matriz vazia
void print_Car(char matriz[LINHAS][COLUNAS], Carro *car, int modelo);


    //Printa o carro inimigo
void printCarro_ADV(Carro *car);


    //Verifica a colisão do carros
int colisao_carro(char matriz[LINHAS][COLUNAS], Carro car);

void Menu();

int jogo();
