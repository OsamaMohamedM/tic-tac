//
// Created by Lenovo on 12/17/2023.
//
#ifndef ASSIGNMENT3_PART2_BOARDGAME_CLASSES_H
#define ASSIGNMENT3_PART2_BOARDGAME_CLASSES_H
#include <bits/stdc++.h>
using namespace std;
class Player {
protected:
    string name;
    char symbol;
public:
    Player(char symbol);
    Player(int order, char symbol);

    virtual void get_move(int& x, int& y);
    string to_string();
    char get_symbol();
};

class RandomPlayer : public Player {
protected:
    int dimention;
public:
    RandomPlayer(char symbol, int dimention);
    void get_move(int& x, int& y);
};

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
    virtual bool winner() = 0;
};

class GameManager {
private:
    Board* boardPtr;
    Player* player1 ,*player2;
    bool  flag;
public:
    GameManager(Board*, Player*player1,Player* player2,bool flag);
    void run();
};


class Four_in_a_row: public Board{
    // int Final_i, Finalj, winner;
public:
    Four_in_a_row();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    bool winner();
//    void Ai_player();
//    int minMax(int depth, bool IsMax, bool IsFirst);
//    int get_winner();
//    pair<int, int> get_i_j();
};


class pyramid :public Board {
public:
    pyramid();
    bool update_board(int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    bool winner();
};

class FiveByFiveBoard : public Board {
    int count_X, count_O;
public:
    FiveByFiveBoard();
    bool update_board(int x, int y, char symbol);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    bool winner();
};




#endif //ASSIGNMENT3_PART2_BOARDGAME_CLASSES_H
