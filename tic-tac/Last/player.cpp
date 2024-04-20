#include "BoardGame_Classes.h"
#include<iostream>
using namespace std;

Player::Player(char symbol) {
    this->symbol = symbol;
}

Player::Player(int order, char symbol) {
    cout << "Welcome player " << order << '\n';
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}

void Player::get_move(int& x, int& y)
{
    cout << "enter x seprated by space and y\n";
    cin >> x >> y;
}

string Player::to_string()
{
    return "Player : " + name;
}

char Player::get_symbol()
{
    return symbol;
}


RandomPlayer::RandomPlayer(char symbol,int dimention) :Player(symbol)
{
    this->symbol = symbol;
    this->dimention = dimention;
}

void RandomPlayer::get_move(int& x, int& y)
{
    if (dimention == 1)
    {
        x = rand()%3;
        y = rand()%5;
    }
    else if (dimention == 2)
    {
        x = rand() % 6;
        y = rand() % 7;
    }
    else
    {
        x = rand() % 5;
        y = rand() % 5;
    }
}

//RandomAiPlayer::RandomAiPlayer(char symbol, int dimention): RandomPlayer(symbol,dimention) {
//    this->symbol = symbol;
//    this->dimention = dimention;
//}
//
//void RandomAiPlayer::get_move(int &x, int &y) {
//    Four_in_a_row oo;
//    oo.Ai_player();
//}

