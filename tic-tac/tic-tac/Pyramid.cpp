#include "Pyramid.h"
#include<bits/stdc++.h>
pyramid::pyramid():Board()
{
    n_cols = 5;
    n_rows = 3;
    n_moves = 0;
    
    board = new char* [n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
        {
            board[i][j] = ' ';
        }
    }
}

bool pyramid::update_board(int x, int y, char mark)
{
    
    if (board[x][y] == ' ' && x<n_rows && y<n_cols && ~y&&~x)
    {
        board[x][y] = mark;
        n_moves++;
        return true;
    }
    return false;
}

void pyramid::display_board()
{
    string space(25, '*');
    for (int i = 0; i < n_rows; i++) {
        cout << "\n";
        for (int j = 0; j < n_cols; j++) {
            if (i == 0 && j==2)
            {
                cout << "(" << i << "," << j << ")";
            }
            else if (i == 1 && (j != 0 && j != 4))
            {
                cout << "(" << i << "," << j << ")";
            }
            else if (i == 2)
            {
                cout << "(" << i << "," << j << ")";
            }
            cout << setw(2) << board[i][j] << " |";
        }
        cout << '\n' << space<<'\n';
    }
    cout << '\n';
    
}

bool pyramid::is_winner()
{
    if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[2][2] != ' ')
    {
        return true;
    }
    else if (board[1][1] == board[1][2] && board[1][1] == board[1][3] && board[1][1] != ' ')
    {
        return true;
    }
    else if (board[0][2] == board[1][3] && board[1][3] == board[2][4] && board[1][3] != ' ')
    {
        return true;
    }
    else if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')
    {
        return true;
    }
    else if (board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][0] != ' ')
    {
        return true;
    }
    else if (board[2][1] == board[2][2] && board[2][1] == board[2][3] && board[2][1] != ' ')
    {
        return true;
    }
    else if (board[2][2] == board[2][3] && board[2][2] == board[2][3] && board[2][3] != ' ')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool pyramid::is_draw()
{

    return n_moves == 9 && !is_winner();
}

bool pyramid::game_is_over()
{
    return n_moves >= 9;
}
