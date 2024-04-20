#include "Board.h"
#include<iostream>
using namespace std;
class pyramid :public Board {
public:
    pyramid();
    bool update_board(int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};