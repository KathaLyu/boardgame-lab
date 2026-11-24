#include "board.h"
#include "checkplayer.h"

char checkplayer(int row, int column, char current_player)
{
    board[row - 1][column - 1] = current_player;

    if (current_player == 'o')
        return 'x';
    return 'o';
}