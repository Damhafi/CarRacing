#include "car.h"

/*
    Inicializa a matriz principal com 'espaços vazios'
*/
void init(char matrix[ROWS][COLUMNS]){
    int i,j;

    for(i=0; i<ROWS; i++){
        for(j=0; j<COLUMNS; j++){
            matrix[i][j] = ' ';
        }
    }
}

/*
    Mostra o conteúdo da matriz principal na tela 
    do computador.
*/
void printMatrix(char matrix[ROWS][COLUMNS]){
    int i, j;

    printf("\t\t\t\t\t");

    //Linha de cima
    for (i = 0; i < COLUMNS + 2; i++)
    {
        printf("*");
    }
    printf("\n");

    //Matriz do jogo
    for (i = 0; i < ROWS; i++)
    {
        printf("\t\t\t\t\t*");
        //parte da esquerda
        if (i % 2 == 0)
            printf("%c", 178);
        else
            printf(" ");

        for (j = 0; j < COLUMNS; j++)
        {
            if (j > 1 & j < COLUMNS)
                printf("%c", matrix[i][j]);
        }

        //parte da direita
        if (i % 2 == 0)
            printf("%c", 178);
        else
            printf(" ");

        printf("*\n");
    }

    printf("\t\t\t\t\t");
    //Linha de baixo
    for (j = 0; j < COLUMNS + 2; j++)
    {
        printf("*");
    }
    printf("\n");
}

/*
    Desenhar uma barra usando o simbolo do caracter ASCII
    passado por parâmetro.
*/
void drawBar(char matrix[ROWS][COLUMNS], Bloco barra, int simbolo){
        //Cabeça
        matrix[barra.i][barra.j] = simbolo;

        //Bracos
        matrix[barra.i+1][barra.j+1] = simbolo;
        matrix[barra.i+1][barra.j+2] = simbolo;
        matrix[barra.i+1][barra.j-2] = simbolo;
        matrix[barra.i+1][barra.j-1] = simbolo;

        //Tronco
        matrix[barra.i+1][barra.j] = simbolo;
        matrix[barra.i+2][barra.j] = simbolo;

        //Pernas
        matrix[barra.i+3][barra.j+1] = simbolo;
        matrix[barra.i+3][barra.j+2] = simbolo;
        matrix[barra.i+3][barra.j-2] = simbolo;
        matrix[barra.i+3][barra.j-1] = simbolo;    
}

/*
    Inicializar a peça do tipo barra
*/
void initBar(Bloco *barra){
    barra->i = 15;
    barra->j = COLUMNS/2;
    barra->tipo = TIPO_I;
    barra->orientacao = ORIENTACAO_LEFT;
    barra->width = 5;
    barra->height = 1;

    #if DEBUG == 1
        printf("posI: %d  posJ: %d \n", barra->i, barra->j);
        system("pause");
    #endif
}

/*
    Verifica a colisão de blocos

int collisionDetect(char matrix[ROWS][COLUMNS], Bloco barra){
}*/

/*
    Verifica a colisão de barras

int collisionBar(char matrix[ROWS][COLUMNS], Bloco barra, int collideSides, int side){
}*/
