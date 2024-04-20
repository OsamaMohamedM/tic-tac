#include "BoardGame_Classes.h"
#include<iostream>
using namespace std;


GameManager::GameManager(Board* boardPtr, Player* player1, Player* player2,bool flag)
{
    this->player1 = player1;
    this->player2 = player2;
    this->boardPtr = boardPtr;
    this->flag = flag;
}

void GameManager::run()
{
    int x, y;
    bool check = true;;
    boardPtr->display_board();
    while (!boardPtr->game_is_over())
    {
        if (check)
            player1->get_move(x, y);
        else
            player2->get_move(x, y);
        while (!boardPtr->update_board(x,y,(check ? player1->get_symbol() : player2->get_symbol())))
        {
            if (!flag)
            {
                cout << "Wrong input 5by\n";
            }
            if (check)
                player1->get_move(x, y);
            else
                player2->get_move(x, y);
        }
        boardPtr->display_board();
        if (boardPtr->is_winner())
        {
            cout << (check? player1->to_string() : player2->to_string())<<" is the winner\n";
            return;
        }
        check = !check;
    }
    if (boardPtr->is_draw())
    {
        cout << "Drawwwwwwwwwwwwwwwwwwwwww\n";
        return;
    }
    if (boardPtr->winner())
    {
        cout << player1->to_string() << " is the winner\n";
        return;
    }
    else{
        cout << player2->to_string() << " is the winner\n";
        return;
    }

}