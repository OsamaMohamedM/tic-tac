#include <iostream>
using namespace std;
#ifndef BOARD_H  // Header guard
#define BOARD_H
class Board {
protected:
    int n_rows, n_cols;
    char** board;
    int  n_moves = 0;

public:
    virtual bool update_board(int x, int y, char symbol) = 0;
    virtual bool is_winner() = 0;
    virtual bool is_draw() = 0;
    virtual void display_board() = 0;
    virtual bool game_is_over() = 0;
};
#endif  // BOARD_H
