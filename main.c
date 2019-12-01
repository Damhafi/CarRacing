#include "car.h"
#include "display.h"
#include <stdlib.h>
#include <time.h>
#define DEBUG 1


int main() {
	int opcao;	
	while(opcao != 7){
		Menu();
        printf("\t\t\t\t\t\t\tEntre com a opcao: ");
		scanf("%d",&opcao);
		system("CLS");	
			
		switch(opcao){
			case 1: jogo();break;
			//case 2: hightscores(); break;		
            case 3: exit(0); break;
			}				
	}
	return 0;
}


int jogo()
{
    char matriz[LINHAS][COLUNAS];

    //posição inicial do car car 
    Carro car;
    car.i = LINHAS - 4;
    car.j = COLUNAS / 2;
    car.largura = 4;
    car.altura = 5;

    //posição inicial do car adv
    Carro adv;
    adv.i = 0;
    adv.j = COLUNAS - 3;
    adv.largura = 4;
    adv.altura = 5;

    Carro adv2;
    adv2.i = 0;
    adv2.j = COLUNAS - 3;
    adv2.largura = 4;
    adv2.altura = 5;

    Carro adv3;
    adv3.i = 0;
    adv3.j = COLUNAS - 3;
    adv3.largura = 4;
    adv3.altura = 5;

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
    while ((keypressed) != ESC)
    {
        gotoxy(0, 0);
        ShowConsoleCursor(0);
        #if DEBUG == 1
            printf("SCORE: %d\n", score);
        #endif
    
        //Printa carro
        print_Car(matriz, &car, PIXEL);
        print_Car(matriz, &adv, PIXEL);
        print_Car(matriz, &adv2, PIXEL);
        print_Car(matriz, &adv3, PIXEL);

        //Mostra a matriz na tela
        print_Matriz(matriz, cont, faixa);
        int i;

        if (!colisao_carro(matriz, car)){
       
            //Apaga Carro
            print_Car(matriz, &car, EMPTY);
            print_Car(matriz, &adv, EMPTY);
            print_Car(matriz, &adv2, EMPTY);
            print_Car(matriz, &adv3, EMPTY);

            if ((cont % velocidade) == 0){
                //alternar animação estrada
                if (faixa == 0){
                    faixa = 1;
                }
                    
                else
                    faixa = 0;

                adv2.i++;
                adv3.i++;
                
                if (adv.i < LINHAS){  
                    adv.i++;
                }
                
                srand(time(NULL));
                random = (rand() % 3);
                
                if (random == 0)
                {
                    if (adv3.i == LINHAS - 3)
                    {
                        printCarro_ADV(&adv);
                        adv.j ++;
                        
                    }
                    if (adv.i == 8)
                    {
                        printCarro_ADV(&adv2);
                        adv2.j = 4;
                    }
                    if (adv2.i == 8)
                    {
                        printCarro_ADV(&adv3);
                        adv3.j = 4;
                    }
                }

                else if (random == 1)
                {
                    if (adv3.i == LINHAS - 3)
                    {
                        printCarro_ADV(&adv);
                        adv.j = 4;
                    }
                    if (adv.i == 8)
                    {
                        printCarro_ADV(&adv2);
                        adv2.j = COLUNAS - 3;
                    }
                    if (adv2.i == 8)
                    {
                        printCarro_ADV(&adv3);
                        adv3.j = 4;
                    }
                }

                else if (random == 2)
                {
                    if (adv3.i == LINHAS - 3)
                    {
                        printCarro_ADV(&adv);
                        adv.j = 4;
                    }
                    if (adv.i == 8)
                    {
                        printCarro_ADV(&adv2);
                        adv2.j = 4;
                    }
                    if (adv2.i == 8)
                    {
                        printCarro_ADV(&adv3);
                        adv3.j = COLUNAS - 3;
                    }
                }

            }
            cont++;
            score += 1;
        }
    
    

        //lendo teclas
        keypressed = 0;
        if (kbhit())
            keypressed = getch();
        if (keypressed == ARROWS)
            keypressed = getch();

        switch (keypressed)
        {
        case TECLA_a:
        case TECLA_A:
        case LEFT:
            if (car.j - (car.altura / 2) > 2)
                (car.j = 4); //vai para esquerda

            break;
        case TECLA_d:
        case TECLA_D:
        case RIGHT:
            if (car.j + (car.altura / 2) < (COLUNAS - 1))
                (car.j = 12); //vai para a direita
            break;

        case TECLA_ESPACO:
            if (velocidade == 3){
            
                velocidade = 1;
            }
            else
            {
                velocidade = 3;
            }
            break;
        }
    }
    system("CLS");

    return 0;
}

