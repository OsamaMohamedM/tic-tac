#include "Four_in_a_row.h"
#include "Board.h"
#include <bits/stdc++.h>
Four_in_a_row::Four_in_a_row() {
    n_rows = 6, n_cols = 7, n_moves = 0;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; ++i) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; ++j) {
            board[i][j] = 0;
        }
    }
}

bool Four_in_a_row::update_board(int x, int y, char mark) {
    if (x<n_rows && x >=0 && y < n_cols && y >= 0 && board[x][y] == 0){
        n_moves++;
        for (int i = n_rows - 1; i >=0 ; --i) {
            if (board[i][y]==0){
                board[i][y] = toupper(mark);
                break;
            }
        }
        return true;
    }
    return false;
}

void Four_in_a_row::display_board() {
    for (int i = 0; i < n_rows; ++i) {
        cout << "\n|";
        for (int j = 0; j < n_cols; ++j) {
            char a = board[i][j];
            if (board[i][j] == 0)  a = ' ';
            cout << "(" << i << "," << j << ")" << setw(2) << a << " |";
        }
        cout << "\n---------------------------------------------------------";
    }
    cout << '\n';
}

bool Four_in_a_row::is_winner() {
    char x;
    // Check Horizontal
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols - 3; ++j) {
            x = board[i][j] & board[i][j+1] & board[i][j+2] & board[i][j+3];
            if (x && x == board[i][j]){
                return true;
            }
        }
    }
    // Check Vertical
    for (int i = 0; i < n_rows - 3; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            x = board[i][j] & board[i+1][j] & board[i+2][j] & board[i+3][j];
            if (x && x == board[i][j]){
                return true;
            }
        }
    }
    // Check Diagonal (Right)
    for (int i = 0; i < n_rows - 3; ++i) {
        for (int j = 0; j < n_cols - 3; ++j) {
            x = board[i][j] & board[i+1][j+1] & board[i+2][j+2] & board[i+3][j+3];
            if (x && x == board[i][j]){
                return true;
            }
        }
    }
    // Check Diagonal (Left)
    for (int i = 0; i < n_rows - 3; ++i) {
        for (int j = 3; j < n_cols; ++j) {
            x = board[i][j] & board[i+1][j-1] & board[i+2][j-2] & board[i+3][j-3];
            if (x&& x == board[i][j]){
                return true;
            }
        }
    }
    return false;
}

bool Four_in_a_row::is_draw() {
    return (n_rows == 42 && !is_winner());
}

bool Four_in_a_row::game_is_over() {
    return n_rows >= 42;
}
