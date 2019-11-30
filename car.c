#include "car.h"

/*
    Inicializa a matriz principal com 'espaços vazios'
*/
void init(char matriz[LINHAS][COLUNAS]){
    int i,j;

    for(i=0; i<LINHAS; i++){
        for(j=0; j<COLUNAS; j++){
            matriz[i][j] = ' ';
        }
    }
}

/*
    Mostra o conteúdo da matriz principal na tela 
    do computador.
*/
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
            printf("%c", 178);
        else
            printf(" ");

        for (j = 0; j < COLUNAS; j++)
        {
            if (j > 1 & j < COLUNAS)
                printf("%c", matriz[i][j]);
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
    for (j = 0; j < COLUNAS + 2; j++)
    {
        printf("*");
    }
    printf("\n");
}

/*
    Desenhar uma car usando o modelo do caracter ASCII
    passado por parâmetro.
*/
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

/*
    Inicializar a peça do tipo car
*/
void initBar(Carro *car){
    car->i = 15;
    car->j = COLUNAS/2;
    car->largura = 5;
    car->altura = 4;

    #if DEBUG == 1
        printf("posI: %d  posJ: %d \n", car->i, car->j);
        system("pause");
    #endif
}

/*
    Verifica a colisão dos Carros

int collisionBar(char matriz[LINHAS][COLUNAS], Carro car, int collideSides, int side){
}*/
