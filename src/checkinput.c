#include <stdio.h>

#include "board.h"
#include "checkinput.h"

int checkinput(int board_size)
{
    char input[128];
    char extra;
    int result;

    if (fgets(input, sizeof input, stdin) == NULL)
        return -1;

    result = sscanf(input, "%d %d %c", &row, &column, &extra);
    if (result != 2)
    {
        printf("Invalid input\n");
        return 0;
    }

    if (row < 1 || row > board_size || column < 1 || column > board_size)
    {
        printf("Out of bounds\n");
        return 0;
    }

    if (board[row - 1][column - 1] != ' ')
    {
        printf("Position already taken\n");
        return 0;
    }

    return 1;
}