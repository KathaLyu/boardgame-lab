#include "board.h"
#include "checkwinner.h"

int count_direction(int board_size, int row, int column,
                      int row_step, int column_step, char player)
{
    int count = 0;
    int next_row = row + row_step;
    int next_column = column + column_step;

    while (next_row >= 0 && next_row < board_size &&
           next_column >= 0 && next_column < board_size &&
           board[next_row][next_column] == player)
    {
        count++;
        next_row += row_step;
        next_column += column_step;
    }

    return count;
}

int checkwinner(int board_size, int row, int column, int target)
{
    char player = board[row][column];
    int count;

    if (player == ' ')
        return 0;

    count = 1;
    count += count_direction(board_size, row, column, 0, -1, player);
    count += count_direction(board_size, row, column, 0, 1, player);
    if (count >= target)
        return 1;

    count = 1;
    count += count_direction(board_size, row, column, -1, 0, player);
    count += count_direction(board_size, row, column, 1, 0, player);
    if (count >= target)
        return 1;

    count = 1;
    count += count_direction(board_size, row, column, -1, -1, player);
    count += count_direction(board_size, row, column, 1, 1, player);
    if (count >= target)
        return 1;

    count = 1;
    count += count_direction(board_size, row, column, -1, 1, player);
    count += count_direction(board_size, row, column, 1, -1, player);
    if (count >= target)
        return 1;

    return 0;
}
