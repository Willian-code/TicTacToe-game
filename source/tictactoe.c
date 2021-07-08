#include <stdio.h>
#include <stdlib.h>

char a[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void gameName()
{
    printf("\n\t\t\tTic Tac Toe Game: \n");
}

void show()
{
    printf("\n\n\t\t\t---|---|---\n");
    printf("\t\t\t %c | %c | %c \n", a[0], a[1], a[2]);
    printf("\t\t\t---|---|---\n");
    printf("\t\t\t %c | %c | %c \n", a[3], a[4], a[5]);
    printf("\t\t\t---|---|---\n");
    printf("\t\t\t %c | %c | %c \n", a[6], a[7], a[8]);
    printf("\t\t\t---|---|---\n");
}

void inputSymbol()
{
    printf("\nPlayer 1 symbol :x:");
    printf("\nPlayer 2 symbol :0:\n");
}

void start()
{
    char par;
    printf("\nEnter who will start the game: player 1 or player 2\n");
    scanf("%c",&par);
}

void check(char P, char S);

void play()
{
    char p, s;
    printf("\nEnter position an symbol for the player: \n");
    fflush(stdin);
    scanf("%c", &p);
    fflush(stdin);
    scanf("%c", &s);
    check(p, s);
}

void check(char P, char S)
{
    for (int i = 0; i <= 8; i++)
    {
        if (a[i] == P)
            a[i] = S;
    }
}

void main()
{
    system("clear");
    gameName();
    show();
    inputSymbol();
    start();
    play();

    system("clear");
    show();

    getchar();
}