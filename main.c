#include "car.h"
#include "display.h"
#include <stdlib.h>
#include <time.h>


int main(){
    char matriz[LINHAS][COLUNAS];
    Carro carro;
    int keypressed=0;
    int cont=0;
    int velocidade=2;

    //apagar o cursor da tela
    ShowConsoleCursor(0);
    system("cls");

    //posicao inicial do personagem
    initBar(&carro);

    //inicializando matriz
    init(matriz);

    //animação do jogo
    while(keypressed != ESC){        
        gotoxy(0,0);

        #if DEBUG == 1
            printf("Posicao = (%d, %d)\n", carro.i, carro.j);
            printf("Dimensao = (%d, %d)\n", carro.largura, carro.altura);
        #endif

        //posicionar o @ no meio da tela
        
        print_Car(matriz, carro, PIXEL);

        //mostro a matriz na tela
        print_Matriz(matriz);

        //faça posição anterior do @ ser apagada
        
        print_Car(matriz, carro, EMPTY);
            
            
        //lendo teclas
        keypressed = 0;         
        if(kbhit()) keypressed = getch();            
        if(keypressed==ARROWS) keypressed = getch();

        switch(keypressed){
            case (int)'a':
            case (int)'A':
            case LEFT: 
                if (carro.j - (carro.largura / 2) > 2)
                    (carro.j = 4); //vai para esquerda
            break; 
            case TECLA_d:
            case TECLA_D:
            case RIGHT: 
                if (carro.j + (carro.largura / 2) < (COLUNAS - 1))
                    carro.j = 12; //vai para a direita 
            break; 
        }
    }

    system("pause");

    return 0;
}