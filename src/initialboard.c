#include "board.h"
#include "initialboard.h"

int initialboard(int board_size)
{
    int row, column;

    /* 只清空本局使用的棋盘区域：井字棋是 3x3，五子棋是 15x15。 */
    for (row = 1; row <= board_size; row++)
    {
        for (column = 1; column <= board_size; column++)
            board[row - 1][column - 1] = ' ';
    }

    return 0;
}
