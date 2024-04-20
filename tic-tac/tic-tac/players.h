#include <iostream>
using namespace std;
#ifndef PLAYERS_H
#define PLAYERS_H
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
#endif // PLAYERS_H