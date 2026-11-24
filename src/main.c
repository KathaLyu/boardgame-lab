#include <stdio.h>
#include <string.h>

#include "board.h"
#include "initialboard.h"
#include "printboard.h"
#include "checkinput.h"
#include "checkplayer.h"
#include "checkwinner.h"

int playgame(int board_size, int target)
{
    int round = 0;
    int input_result;
    char current_player = 'o';

    initialboard(board_size);
    printboard(board_size);

    while (round < board_size * board_size)
    {
        printf(">");
        input_result = checkinput(board_size);

        if (input_result == -1)
            return 0;
        if (input_result == 0)
            continue;

        current_player = checkplayer(row, column, current_player);
        round++;

        printboard(board_size);

        if (round >= target * 2 - 1 &&
            checkwinner(board_size, row - 1, column - 1, target))
        {
            char winner = current_player == 'o' ? 'x' : 'o';
            printf("Winner is %c\n", winner);
            return 0;
        }
    }

    printf("Game tied\n");
    return 0;
}

int main()
{
    char game[10];

    printf("Enter(xo/gomoku): ");
    if (fgets(game, sizeof game, stdin) == NULL)
        return 0;

    game[strcspn(game, "\r\n")] = '\0';

    if (strcmp(game, "xo") == 0)
        return playgame(3, 3);
    if (strcmp(game, "gomoku") == 0)
        return playgame(15, 5);

    printf("Unknown game. Choose xo or gomoku.\n");
    return 1;
}