#include <stdio.h>

#include "board.h"
#include "printboard.h"

void printboard(int board_size)
{
    int row, column;

    printf("\n   ");
    for (column = 1; column <= board_size; column++)
        printf("%2d ", column);
    printf("\n");

    for (row = 1; row <= board_size; row++)
    {
        printf("%2d  ", row);
        for (column = 1; column <= board_size; column++)
        {
            if (board[row - 1][column - 1] == ' ')
                printf("¡¤  ");
            else
                printf("%c  ", board[row - 1][column - 1]);
        }
        printf("\n");
    }
}
