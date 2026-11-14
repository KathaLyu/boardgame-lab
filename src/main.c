#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int xo()
{
    char board[3][3];
    int row, column, time = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
    printf("\n  1 2 3\n");
    for (int i = 0; i < 3; i++)
    {
        int k = i + 1;
        printf("%d ", k);
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
                printf("， ");
            else
                printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf(">");
    while (time < 9)
    {
        char input[128];
        char extra;

        if (fgets(input, sizeof input, stdin) == NULL)
            return 0;

        int result = sscanf(input, "%d %d %c", &row, &column, &extra);
        if (result != 2)
        {
            printf("Invalid input\n");
            printf(">");
            continue;
        }
        else if (row < 1 || row > 3 || column < 1 || column > 3)
        {
            printf("Out of bounds\n");
            printf(">");
            continue;
        }
        else if (board[row - 1][column - 1] != ' ')
        {
            printf("Position already taken\n");
            printf(">");
            continue;
        }
        time++;
        if (time % 2 == 1)
            board[row - 1][column - 1] = 'o';
        else
            board[row - 1][column - 1] = 'x';
        // system("cls");
        printf("\n  1 2 3\n");
        for (int i = 0; i < 3; i++)
        {
            int k = i + 1;
            printf("%d ", k);
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                    printf("， ");
                else
                    printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        printf(">");
        if (time >= 5)
        {
            for (int k = 0; k < 3; k++)
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

    printf("Game tied");
}

int gomoku()
{
    char board[15][15];
    int time = 0, row, column;
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            board[i][j] = ' ';
        }
    }
    printf("\n   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15\n");
    for (int i = 0; i < 15; i++)
    {
        int k = i + 1;
        printf("%2d ", k);
        for (int j = 0; j < 15; j++)
        {
            if (board[i][j] == ' ')
                printf("，  ");
            else
                printf("%c  ", board[i][j]);
        }
        printf("\n");
    }
    printf(">");
    while (time < 225)
    {
        char input[128];
        char extra;

        if (fgets(input, sizeof input, stdin) == NULL)
            return 0;

        int result = sscanf(input, "%d %d %c", &row, &column, &extra);
        if (result != 2)
        {
            printf("Invalid input\n");
            printf(">");
            continue;
        }
        else if (row < 1 || row > 15 || column < 1 || column > 15)
        {
            printf("Out of bounds\n");
            printf(">");
            continue;
        }
        else if (board[row - 1][column - 1] != ' ')
        {
            printf("Position already taken\n");
            printf(">");
            continue;
        }
        time++;
        if (time % 2 == 1)
            board[row - 1][column - 1] = 'o';
        else
            board[row - 1][column - 1] = 'x';
        printf("\n   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15\n");
        for (int i = 0; i < 15; i++)
        {
            int k = i + 1;
            printf("%2d ", k);
            for (int j = 0; j < 15; j++)
            {
                if (board[i][j] == ' ')
                    printf("，  ");
                else
                    printf("%c  ", board[i][j]);
            }
            printf("\n");
        }
        printf(">");
        if (time >= 9)
        {
            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 11; j++)
                {
                    if (board[i][j] != ' ' &&
                        board[i][j] == board[i][j + 1] &&
                        board[i][j + 1] == board[i][j + 2] &&
                        board[i][j + 2] == board[i][j + 3] &&
                        board[i][j + 3] == board[i][j + 4])
                    {
                        printf("Winner is %c\n", board[i][j]);
                        return 0;
                    }

                    if (board[j][i] != ' ' &&
                        board[j][i] == board[j + 1][i] &&
                        board[j + 1][i] == board[j + 2][i] &&
                        board[j + 2][i] == board[j + 3][i] &&
                        board[j + 3][i] == board[j + 4][i])
                    {
                        printf("Winner is %c\n", board[j][i]);
                        return 0;
                    }
                }
            }
            for (int i = 0; i < 11; i++)
            {
                for (int j = 0; j < 11; j++)
                {
                    if (board[i][j] != ' ' &&
                        board[i][j] == board[i + 1][j + 1] &&
                        board[i + 1][j + 1] == board[i + 2][j + 2] &&
                        board[i + 2][j + 2] == board[i + 3][j + 3] &&
                        board[i + 3][j + 3] == board[i + 4][j + 4])
                    {
                        printf("Winner is %c\n", board[i][j]);
                        return 0;
                    }
                }
                for (int j = 4; j < 15; j++)
                {
                    if (board[i][j] != ' ' &&
                        board[i][j] == board[i + 1][j - 1] &&
                        board[i + 1][j - 1] == board[i + 2][j - 2] &&
                        board[i + 2][j - 2] == board[i + 3][j - 3] &&
                        board[i + 3][j - 3] == board[i + 4][j - 4])
                    {
                        printf("Winner is %c\n", board[i][j]);
                        return 0;
                    }
                }
            }
        }
    }
    printf("Game tied");
}

int main()
{
    char game[10];
    printf("Enter(xo/gomoku): ");
    if (fgets(game, sizeof(game), stdin) == NULL)
    {
        printf("\nInvalid input.\n");
        return 0;
    }
    if (strcmp(game, "xo\n") == 0)
        xo();
    else if (strcmp(game, "gomoku\n") == 0)
        gomoku();
    return 0;
}
