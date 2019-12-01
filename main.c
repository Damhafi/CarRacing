#include "car.h"
#include "display.h"
#include <stdlib.h>
#include <time.h>


int jogo(){
    char matriz[LINHAS][COLUNAS];
    //MEU CARRO INICIA AQUI
    Carro car;
    car.i = LINHAS - 4;
    car.j = COLUNAS / 2;
    car.height = 4;
    car.width = 5;

    //POSICAO DOS 3 CARROS IMMIGOS QUE INICIA
    Carro adv;
    adv.i = 0;
    adv.j = COLUNAS - 3;
    adv.height = 4;
    adv.width = 5;

    Carro adv2;
    adv2.i = 0;
    adv2.j = COLUNAS - 3;
    adv2.height = 4;
    adv2.width = 5;

    Carro adv3;
    adv3.i = 0;
    adv3.j = COLUNAS - 3;
    adv3.height = 4;
    adv3.width = 5;

    int keypressed = 0;
    int cont = 0;
    int velocidade = 3;
    int faixa = 0;
    int random = 0;
    int score =0;

    //inicializando matriz
    init(matriz);

    //apagar o cursor da tela
    ShowConsoleCursor(0);
    system("cls");

    //animação do jogo
    while(keypressed != ESC){        
        gotoxy(0,0);
        ShowConsoleCursor(0);

        #if DEBUG == 1
            printf("Posicao = (%d, %d)\n", carro.i, carro.j);
            printf("Dimensao = (%d, %d)\n", carro.largura, carro.altura);
        #endif

        //Printa carro
        
        print_Car(matriz, car, PIXEL);
        print_Car(matriz, car, PIXEL);
        print_Car(matriz, car, PIXEL);
        print_Car(matriz, car, PIXEL);
        

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