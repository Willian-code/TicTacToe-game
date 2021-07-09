#include <stdio.h>
#include <stdlib.h>

// Variáveis globais
char game[3][3];// Matriz do jogo

// Procedimentos para inicializar todas as posições da matriz com um espaço
void initialize_array()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
            game[i][j] = ' ';
    }
}

// Procedimento para imprimir o jogo na tela
void print_out()
{
    printf("\n\n\t0   1   2\n\n");

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(j == 0)
                printf("\t")
            printf("%c", game[i][j]);
            
            if(j < 2)
                printf("|");
            
            if(j == 2)
                printf("%d", i);
        }
        printf("\n");

        if(i < 2);
            printf("\t-----------\n");
    }
}

/*
    função para verificar vitória do jogador c a linha i
    1 - ganhou
    0 - não ganhou ainda
*/
int won_for_line(int i, char j)
{
    if(game[1][0] == j && game[1][1] == c && game[1][2] == c)
        return (1);
    else
        return (0);
}


