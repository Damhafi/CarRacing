#include "car.h"
#include "display.h"
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define DEBUG 1

int main()
{
    srand(time(NULL));

    int opcao;
    while (opcao != 7)
    {
        Menu();
        printf("\t\t\t\t\t\t\tEntre com a opcao: ");
        scanf("%d", &opcao);
        system("CLS");

        switch (opcao)
        {
        case 1:
            jogo();
            break;
        //case 2: hightscores(); break;
        case 3:
            exit(0);
            break;
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

    //posição inicial do car adversario através do sorteio
    Carro adv[3];

    adv[0].i = 0;
    adv[0].j = (rand() % 10) < 5 ? 4 : COLUNAS - 3;
    adv[0].largura = 4;
    adv[0].altura = 5;
    adv[0].enabled = 1;

    adv[1].i = 0;
    adv[1].j = (rand() % 10) < 5 ? 4 : COLUNAS - 3;
    adv[1].largura = 4;
    adv[1].altura = 5;
    adv[1].enabled = 0;

    adv[2].i = 0;
    adv[2].j = (rand() % 10) < 5 ? 4 : COLUNAS - 3;
    adv[2].largura = 4;
    adv[2].altura = 5;
    adv[2].enabled = 0;

    int keypressed = 0;
    int cont = 0;
    int velocidade = 3;
    int faixa = 0;
    int random = 0;
    int score = 0;

    // FILE *fp;

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
            if (score < 50){
                printf("Level 1");
            }
            else printf("Level 2");
        #endif

        //Printa carro
        print_Car(matriz, &car, PIXEL);
        print_Car(matriz, &adv[0], PIXEL);
        print_Car(matriz, &adv[1], PIXEL);
        print_Car(matriz, &adv[2], PIXEL);

        //Mostra a matriz na tela
        print_Matriz(matriz, cont, faixa);
        
        int i;

        if (colisao_carro(matriz, car)){
            system("pause");
            // system("CLS");
            // Pontos jogador;
            // jogador.score = score;
            // fp = fopen("HighScore.bin","ab");
            // printf("Digite o seu nome: ");
            // fflush(stdin);
            // gets(nome);
            // strcpy(jogador.nome,nome);
            // fprintf(fp, "%s %d\n", jogador.nome, jogador.score);
            // fclose(fp);
            // break;
            // system("CLS");
            // main();
        }
            
        else{
            ++score;
            //Aumenta a velocidade a partir do X score;
            if(score>= 100){
                if (velocidade = 3){
                   velocidade = 1;
                } 
            }
        }
            

        //Apaga Carro
        print_Car(matriz, &car, EMPTY);
        print_Car(matriz, &adv[0], EMPTY);
        print_Car(matriz, &adv[1], EMPTY);
        print_Car(matriz, &adv[2], EMPTY);

        //Inicia o primeiro carro e dps em baixo sorteia ele novamente pra cair em outro
        
        if ((cont % velocidade) == 0){
                //alternar animação estrada
            if (faixa == 0)
                faixa = 1;
            else
                faixa = 0;
        
        ++adv[0].i;

        //Pega a posicao anterior
        if (adv[1].enabled)
            ++adv[1].i;
        if (adv[2].enabled)
            ++adv[2].i;

        //Printa a proxima posicao verificando a anterior
        if (adv[0].i > 8)
            adv[1].enabled = true;
        if (adv[1].i > 8)
            adv[2].enabled = true;
        }cont++;
        

        //lendo teclas
        keypressed = 0;
        if (kbhit())
            keypressed = getch();
        if (keypressed == ARROWS)
            keypressed = getch();

        switch (keypressed){
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
        }
    }
    system("CLS");

    return 0;
}


