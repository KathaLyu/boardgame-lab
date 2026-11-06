#include <stdio.h>
#include <stdlib.h>
int main()
{
    char board[3][3];
    int i, j, k, m, n, d = 0, winner = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
    while (d < 9)
    {
        system("cls");
        printf("  1 2 3\n");
        for (i = 0; i < 3; i++)
        {
            k = i + 1;
            printf("%d ", k);
            for (j = 0; j < 3; j++)
            {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        printf(">");

        scanf("%d %d", &m, &n);
        d++;
        if (d % 2 == 1)
            board[m - 1][n - 1] = 'o';
        else
            board[m - 1][n - 1] = 'x';
        system("cls");
        printf("  1 2 3\n");
        for (i = 0; i < 3; i++)
        {
            k = i + 1;
            printf("%d ", k);
            for (j = 0; j < 3; j++)
            {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        if (d >= 5)
        {
            for (k = 0; k < 3; k++)
            {
                if (board[k][0] != ' ' &&
                    board[k][0] == board[k][1] &&
                    board[k][1] == board[k][2])
                {
                    printf("Winner is %c\n", board[k][0]);
                    return 0;
                }

                if (board[0][k] != ' ' &&
                    board[0][k] == board[1][k] &&
                    board[1][k] == board[2][k])
                {
                    printf("Winner is %c\n", board[0][k]);
                    return 0;
                }
            }
            if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
            {
                printf("Winner is %c\n", board[0][0]);
                return 0;
            }
            if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
            {
                printf("Winner is %c\n", board[0][2]);
                return 0;
            }
        }
    }
    if (winner == 0)
        printf("Game tied");

    return 0;
}