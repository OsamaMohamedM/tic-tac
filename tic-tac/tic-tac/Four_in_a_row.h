#include "Board.h"
#ifndef ASSIGNMENT3_PART2_FOUR_IN_A_ROW_H
#define ASSIGNMENT3_PART2_FOUR_IN_A_ROW_H


class Four_in_a_row: public Board{
public:
    Four_in_a_row();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};


#endif //ASSIGNMENT3_PART2_FOUR_IN_A_ROW_H
