#include "car.h"
#include "colors.h"

void Menu(char matriz[COL])
{
    int j, i;
    system("color 0E");

    printf("\n\n\n\n\n\t\t\t");
    //Linha de Cima
    for (j = 0; j <= 80; j++)
    {
        printf("%c", 220);
    }
    printf("\n");

    printf("\t\t\t\t\t\t\tCAR RACING");
    printf("\n\t\t\t");

    for (j = 0; j <= 80; j++)
    {
        printf("%c", 196);
    }
    printf("\n");

    //OPÇÔES
    printf("\t\t\t\t1 - NOVO JOGO");
    printf("\n");
    printf("\t\t\t\t2 - HIGH SCORES");
    printf("\n");
    printf("\t\t\t\t3 - SAIR");

    printf("\n\t\t\t");
    for (j = 0; j <= 80; j++)
    {
        printf("%c", 196);
    }
    printf("\n\t\t\t");

    for (j = 0; j <= 80; j++)
    {
        printf("%c", 220);
    }
}

//Inicia a matriz do jogo vazia
void init(char matriz[LINHAS][COLUNAS])
{
    int i, j;

    for (i = 0; i < LINHAS; i++)
    {

        for (j = 0; j < COLUNAS; j++)
        {
            matriz[i][j] = ' ';
        }
    }
}

//Mostra o carro na matriz que estava vazia
void print_Matriz(char matriz[LINHAS][COLUNAS], int cont, int faixa)
{

    int i, j;

    printf("\t\t\t\t\t");

    // for (i = 0; i < LINHAS; i++){
    //     for (j = 0; j < COLUNAS + 2; j++){
    //         if(i == 0 || i == LINHAS - 1)
    //             putchar('*');
    //         else if(j == 1 || j == COLUNAS - 2){
    //             printf("%c", 178, foreground(YELLOW));
    //             style(RESETALL);
    //         }
    //         else
    //             putchar(' ');
    //     }
    //     puts("");
    // }
    

    //Linha de cima
    for (j = 0; j < COLUNAS + 2; j++)
    {
        printf("*");
    }
    printf("\n");

    //Matriz do jogo
    for (i = 0; i < LINHAS; i++)
    {
        printf("\t\t\t\t\t*");
        //parte da esquerda
        if (i % 2 == faixa)
        {
            printf("%c", 178, foreground(YELLOW));
            style(RESETALL);
        }
        else
            printf(" ");

        for (j = 0; j < COLUNAS; j++)
        {
            if (j > 1 & j < COLUNAS)
            {
                printf("%c", matriz[i][j]);
            }
        }

        //parte da direita
        if (i % 2 == faixa)
        {
            printf("%c", 178, foreground(YELLOW));
            style(RESETALL);
        }
        else
            printf(" ");

        printf("*\n");
    }

    printf("\t\t\t\t\t");
    //Linha de baixo
    for (j = 0; j < COLUNAS + 2; j++)
    {
        printf("*");
    }
    printf("\n");
}

//Desenha o carro

void print_Car(char matriz[LINHAS][COLUNAS], Carro *car, int modelo)
{
    //Parte superior
    if(car->enabled){
        if (car->i + 1 >= 0 && car->i + 1 <= LINHAS - 1)
        {
            matriz[car->i + 1][car->j + 1] = modelo;
            matriz[car->i + 1][car->j + 2] = modelo;
            matriz[car->i + 1][car->j - 1] = modelo;
            matriz[car->i + 1][car->j - 2] = modelo;
        }

        //Cabeça do carro
        if (car->i >= 0 && car->i <= LINHAS - 1)
        {

            matriz[car->i][car->j] = modelo;
        }

        //Segunda parte do meio abaixo da cabeça do carro
        if (car->i + 1 >= 0 && car->i + 1 <= LINHAS - 1)

            matriz[car->i + 1][car->j] = modelo;

        //Terceira parte do meio
        if (car->i + 2 >= 0 && car->i + 2 <= LINHAS - 1)

            matriz[car->i + 2][car->j] = modelo;

        //Primeira parte inferior
        if (car->i + 3 >= 0 && car->i + 3 <= LINHAS - 1)
        {

            matriz[car->i + 3][car->j + 1] = modelo;
            matriz[car->i + 3][car->j + 2] = modelo;
            matriz[car->i + 3][car->j - 1] = modelo;
            matriz[car->i + 3][car->j - 2] = modelo;
        }

        if(car->i > LINHAS){
            car->i = 0;
            car->enabled = false;
            car->j = (rand() % 10) < 5 ? 4 : COLUNAS - 3;
        }
    }
}

//estrutura do carro inimigo
void printCarro_ADV(Carro *car)
{
    car->i = -4;
    car->j = COLUNAS - 3;
    car->largura = 5;
    car->altura = 4;
}

//colisão do carro
int colisao_carro(char matriz[LINHAS][COLUNAS], Carro car)
{
    int retorno = 0;

    //Colisão com o carro
    if (matriz[car.i - 1][car.j + (car.largura / 2)] != EMPTY)
    {
        retorno = 1;
    }

    //Outro lado
    if (matriz[car.i - 1][car.j - (car.largura / 2)] != EMPTY)
    {
        retorno = 1;
    }

    //Cabeça do carro
    if (matriz[car.i - 1][car.j] != EMPTY)
    {
        retorno = 1;
    }

    return retorno;
}

// void HighScore(Pontos jogador[5]){
//     int i,j;
//     Pontos cont[2];
//     char Nome[30];
//     int quantidade = 0;
//     int quantidade2 = 0;
//     int q2 = 0;
//     char num[10];
//     int fim = 0;
//     File *fp = fopen("HighScore.bin", "rb");
// }
