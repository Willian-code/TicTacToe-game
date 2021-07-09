#include <stdio.h>
#include <stdlib.h>

// Variáveis globais
char game[3][3];// Matriz do jogo
int l, c;

// Procedimentos para inicializar todas as posições da matriz com um espaço
void initialize_array()
{
    for(l = 0; l < 3; l++)
    {
        for(c = 0; c < 3; c++)
            game[l][c] = ' ';
    }
}

// Procedimento para imprimir o jogo na tela
void print_out()
{
    printf("\n\n\t0   1   2\n\n");

    for(l = 0; l < 3; l++)
    {
        for(c = 0; c < 3; c++)
        {
            if(c == 0)
                printf("\t");
            printf("%c", game[l][c]);
            
            if(c < 2)
                printf("|");
            
            if(c == 2)
                printf("%d", l);
        }
        printf("\n");

        if(l < 2);
            printf("\t-----------\n");
    }
}

/*
    função para verificar vitória do jogador c a linha i
    1 - ganhou
    0 - não ganhou ainda
*/
int won_by_line(int l, char c)
{
    if(game[l][0] == c && game[l][1] == c && game[l][2] == c)
        return (1);
    else
        return (0);
}

/*
    função para verificar vitória do jogador c nas linhas
    1 - ganhou
    0 - não ganhou ainda
*/
int won_by_lines(char c)
{
    int won = 0;

    for(l = 0; l < 3; l++)
        won += won_by_line(l, c);
    
    return(won);
}

/*
    função para verificar vitória do jogador j na coluna c
    1 - ganhou
    0 - não ganhou ainda
*/
int won_by_column(int c, char j)
{
    if(game[0][c] == j && game[1][c] == j && game[2][c] == j)
        return(1);
    else
        return(0);
}

/*
    função que verifica vitória do jogador j por colunas
    1 - ganhou
    0 - não ganhou ainda
*/
int won_by_columns(char j)
{
    int won = 0;

    for(c = 0; c < 3; c++)
        won += won_by_column(c, j);
    
    return(won);
}

/*
    função para verificar vitória do jogador c na diagonal principal
    1 - vitória
    0 - não ganhou
*/
int won_by_diagprin(char c)
{
    if(game[0][0] == c && game[1][1] == c && game[2][2] == c)
        return(1);
    else
        return(0);
}

/*
    função para verificar vitória do jogador c na diagonal secundária
    1 - vitória
    0 - não ganhou
*/
int won_by_diagsec(char c)
{
    if(game[0][2] == c && game[1][1] == c && game[2][0] == c)
        return(1);
    else
        return(0);
}

/*
    função que diz se uma coordenada é válida ou não
    1 - é válida
    0 - não é válida
*/
int is_valid(int l, int c)
{
    if(l >= 0 && l < 3 && c >= 0 && c < 3 && game[l][c] == ' ')
        return(1);
    else
        return(0);
}

// procedimento para ler as coordenadas digitadas pelo jogador
void read_coordinates(char j)
{
    int line, column;

    printf("Digite linha e coluna: ");
    scanf("%d%d", &line, &column);

    while(is_valid(line, column) == 0)
    {
        printf("Coordenadas inválidas! Digite outra linha e coluna: ");
        scanf("%d%d", &line, &column);
    }
    game[line][column] = j;
}

// função que retorna a quantidade de posições ainda vazias (não jogadas)
int empty_quantity()
{
    int quantity = 0;

    for(l = 0; l < 3; l++)
    {
        for(c = 0; c < 3; c++)
        {
            if(game[l][c] == ' ')
                quantity++;
        }
    }
    return(quantity);
}

// procedimento jogar com loop (repetição) principal do jogo
void play()
{
    int player = 1, victoryx = 0, victory0 = 0;
    char player1 = 'x', player2 = '0';

    do
    {
        print_out();

        if(player == 1)
        {
            read_coordinates(player1);
            player++;
            victoryx += won_by_lines(player1);
            victoryx += won_by_columns(player1);
            victoryx += won_by_diagprin(player1);
            victoryx += won_by_diagsec(player1);
        }
        else
        {
            read_coordinates(player2);
            player = 1;
            victory0 += won_by_lines(player2);
            victory0 += won_by_columns(player2);
            victory0 += won_by_diagprin(player2);
            victory0 += won_by_diagsec(player2);
        }
    }while(victoryx == 0 && victory0 == 0 && empty_quantity() > 0);

    print_out();

    if(victory0 == 1)
        printf("\nParabéns joagdor 2. Você venceu!!!\n");
    else if(victoryx == 1)
        printf("\nParabéns jogador 1. Você venceu!!!\n");
    else
        printf("\nQue pena. Perderam!!!\n");
}

int main()
{
    int option;

    do
    {
        initialize_array();
        play();

        printf("\nDigite 1 para jogar novamente: ");
        scanf("%d", &option);
    }while(option == 1);

    return(0);
}
