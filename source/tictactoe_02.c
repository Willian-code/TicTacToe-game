#include <stdio.h>

int main()
{
    //estrutura de dados?
    int line, column, player, won, plays, option;
    char game[3][3];

    do // deseja jogar novamente?
    {
        player = 1;
        won = 0;
        plays = 0;
        // como inicializar nossa estrutura de dados?
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                game[i][j] = ' ';
        }
        do // repete até alguém ganhar ou atingir 9 jogadas
        { // imprimir jogo
            printf("\n\n\t 0   1   2\n\n");
        
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (j == 0)
                        printf("\t");
                    printf(" %c ", game[i][j]);
                    if (j < 2)
                        printf("|");
                    if (j == 2)
                        printf("   %d", i);
                }
                if (i < 2)
                    printf("\n\t-----------");
                printf("\n");
            }
            // ler coordenadas
            do
            {
                printf("\nJOGADOR 1 = 0\nJOGADOR 2 = X\n");
                printf("\nJOGADOR %d: Digite a linha e a coluna que deseja jogar: ", player);
                scanf("%d%d", &line, &column);
            }while (line < 0 || line > 2 || column < 0 || column > 2 || game[line][column] != ' ');

            // salavar coordenadas
            if (player == 1)
            {
                game[line][column] = '0';
                player++;
            }
            else
            {
                game[line][column] = 'x';
                player = 1;
            }
            plays++;

            // alguém ganhou por linha
            if (game[0][0] == '0' && game[0][1] == '0' && game[0][2] == '0' || game[1][0] == '0' && game[1][1] == '0' && game[1][2] == '0' || game[2][0] == '0' && game[2][1] == '0' && game[2][2] == '0')
            {
                printf("\nParabéns! o jogador 1 venceu por linha!\n");
                won = 1;
            }

            if ( (game[0][0] == 'x' && game[0][1] == 'x' && game[0][2] == 'x') || (game[1][0] == 'x' && game[1][1] == 'x' && game[1][2] == 'x') || (game[2][0] == 'x' && game[2][1] == 'x' && game[2][2] == 'x') )
            {
                printf("\nParabéns! o jogador 2 venceu por linha!\n");
                won = 1;
            }

            // alguém ganhou por coluna
            if (game[0][0] == '0' && game[1][0] == '0' && game[2][0] == '0' || game[0][1] == '0' && game[1][1] == '0' && game[2][1] == '0' || game[0][2] == '0' && game[1][2] == '0' && game[2][2] == '0')
            {
                printf("\nParabéns! o jogador 1 venceu por linha!\n");
                won = 1;
            }

            if (game[0][0] == 'x' && game[1][0] == 'x' && game[2][0] == 'x' || game[0][1] == 'x' && game[1][1] == 'x' && game[2][1] == 'x' || game[0][2] == 'x' && game[1][2] == 'x' && game[2][2] == 'x')
            {
                printf("\nParabéns! o jogador 2 venceu por linha!\n");
                won = 1;
            }

            // alguém ganhou na diagonal principal
            if (game[0][0] == '0' && game[1][1] == '0' && game[2][2] == '0')
            {
                printf("\nParabéns! o jogador 1 venceu na diag. principal!\n");
                won = 1;
            }

            if (game[0][0] == 'x' && game[1][1] == 'x' && game[2][2] == 'x')
            {
                printf("\nParabéns! o jogador 2 venceu na diag. principal!\n");
                won = 1;
            }

            // alguém ganhou na diagonal secundária
            if (game[0][2] == '0' && game[1][1] == '0' && game[2][0] == '0')
            {
                printf("\nParabéns! o jogador 1 vendeu na diag. secundária!\n");
                won = 1;
            }

            if (game[0][2] == 'x' && game[1][1] == 'x' && game[2][0] == '0')
            {
                printf("\nParabéns! o jogador 1 vendeu na diag. secundária!\n");
                won = 1;
            }
        }while (won == 0 && plays < 9);

        // imprimir jogo
        printf("\n\n\t 0   1   2\n\n");

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (j == 0)
                    printf("\t");
                printf(" %c ", game[i][j]);

                if (i < 2)
                    printf("|");
                if (j == 2);
                    printf("  %d", i);
            }
            if (i < 2)
                printf("\n\t-----------");
            printf("\n");
        }
        if (won == 0)
            printf("\nO jogo finalizou sem ganhadores!\n");
    
        printf("\nDigite 1 para jogar novamente: ");
        scanf("%d", &option);
    }while (option == 1);

    return (0);
}
