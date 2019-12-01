#include "car.h"
#include "colors.h"


void Menu(char matriz[COL]){
    int j,i;
    system("color 0E");
    
	printf("\n\n\n\n\n\t\t\t");
    //Linha de Cima
    for (j = 0; j <= 80; j++){
        printf("%c",220);

    }
    printf("\n");

    printf("\t\t\t\t\t\t\tCAR RACING");printf("\n\t\t\t");

    for (j = 0; j <= 80; j++){
        printf("%c",196);
    }
    printf("\n");

    //OPÇÔES
    printf("\t\t\t\t1 - NOVO JOGO");printf("\n");
    printf("\t\t\t\t2 - HIGH SCORES");printf("\n");
    printf("\t\t\t\t3 - SAIR");

    printf("\n\t\t\t");
    for (j = 0; j <= 80; j++){
        printf("%c",196);
    }printf("\n\t\t\t");


    for (j = 0; j <= 80; j++){
        printf("%c",220);

    }
}

    //Desenha a matriz principal com espaços vazios
void init(char matriz[LINHAS][COLUNAS]){
    int i,j;

    for(i=0; i<LINHAS; i++){
        for(j=0; j<COLUNAS; j++){
            matriz[i][j] = ' ';
        }
    }
}


    //Mostra a pista na tela do computador.

void print_Matriz(char matriz[LINHAS][COLUNAS]){
    int i, j;
    
    printf("\t\t\t\t\t");

    //Linha de cima
    for (i = 0; i < COLUNAS + 2; i++)
    {
        printf("*");
    }
    printf("\n");

    //Matriz do jogo
    for (i = 0; i < LINHAS; i++)
    {
        printf("\t\t\t\t\t*");
        //parte da esquerda
        if (i % 2 == 0)
            printf("%c", 178,foreground(YELLOW));
            style(RESETALL);
        else
            printf(" ");

        for (j = 0; j < COLUNAS; j++)
        {
            if (j > 1 & j < COLUNAS)
                printf("%c", matriz[i][j]);
        }

        //parte da direita
        if (i % 2 == 0)
            printf("%c", 178,foreground(YELLOW));
            style(RESETALL);
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


    //Desenha o meu carro passado por parâmetro.

void print_Car(char matriz[LINHAS][COLUNAS], Carro car, int modelo){
        //Cabeça
        matriz[car.i][car.j] = modelo;

        //Bracos
                
        matriz[car.i+1][car.j+1] = modelo;
        matriz[car.i+1][car.j+2] = modelo;
        matriz[car.i+1][car.j-2] = modelo;
        matriz[car.i+1][car.j-1] = modelo;
  
       
        //Tronco
        matriz[car.i+1][car.j] = modelo;
        matriz[car.i+2][car.j] = modelo;

        //Pernas
        matriz[car.i+3][car.j+1] = modelo;
        matriz[car.i+3][car.j+2] = modelo;
        matriz[car.i+3][car.j-2] = modelo;
        matriz[car.i+3][car.j-1] = modelo;   
}


    //Inicializando meu carro na matriz

void printCarro_ADV(Carro *car){
    car->i = -4;
    car->j = COLUNAS - 1;
    car->largura = 5;
    car->altura = 4;
}


    //Verifica a colisão dos Carros

int colisao_carro(char matriz[LINHAS][COLUNAS], Carro car){
    int retorno = 0;

        //Colisão com o carro
        if (matriz[car.i-1][car.j+(car.largura/2)] != EMPTY){
            retorno = 1;
        }

        //Outro lado
        if(matriz[car.i-1][car.j-(car.largura/2)] != EMPTY){
            retorno = 1;
        } 

        //Cabeça do carro
        if(matriz[car.i-1][car.j] != EMPTY){
            retorno = 1;
        }

        return retorno;    
}
