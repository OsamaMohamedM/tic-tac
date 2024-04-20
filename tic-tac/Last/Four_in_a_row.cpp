#include "BoardGame_Classes.h"
#include <bits/stdc++.h>
Four_in_a_row::Four_in_a_row(){
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
                //winner = (x=='X')? 2:-2;
                return true;
            }
        }
    }
    // Check Vertical
    for (int i = 0; i < n_rows - 3; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            x = board[i][j] & board[i+1][j] & board[i+2][j] & board[i+3][j];
            if (x && x == board[i][j]){
                //winner = (x=='X')? 2:-2;
                return true;
            }
        }
    }
    // Check Diagonal (Right)
    for (int i = 0; i < n_rows - 3; ++i) {
        for (int j = 0; j < n_cols - 3; ++j) {
            x = board[i][j] & board[i+1][j+1] & board[i+2][j+2] & board[i+3][j+3];
            if (x && x == board[i][j]){
                //winner = (x=='X')? 2:-2;
                return true;
            }
        }
    }
    // Check Diagonal (Left)
    for (int i = 0; i < n_rows - 3; ++i) {
        for (int j = 3; j < n_cols; ++j) {
            x = board[i][j] & board[i+1][j-1] & board[i+2][j-2] & board[i+3][j-3];
            if (x&& x == board[i][j]){
                //winner = (x=='X')? 2:-2;
                return true;
            }
        }
    }
    return false;
}

bool Four_in_a_row::is_draw() {
    return (n_moves == 42 && !is_winner());
}

bool Four_in_a_row::game_is_over() {
    return n_moves >= 42;
}

bool Four_in_a_row::winner() {
    return false;
}


//void Four_in_a_row::Ai_player() {
//    minMax(200, false, true);
//}
//
//int Four_in_a_row::minMax(int dep, bool IsMax, bool IsFirst) {
//    int res;
//    if (!is_winner()){
//        if (is_draw()) res = 0;
//        else res = 1;
//    }
//    else {
//        res = get_winner();
//    }
//    if (res != 1 || dep == 0){
//        return res;
//    }
//    if(IsMax) {
//        int fS = -1e3, fI, fJ, score;
//        for(int i = 0; i < n_rows; i++) {
//            for(int j = 0; j < n_cols; j++) {
//                if(board[i][j] == ' ') {
//                    board[i][j] = 'X';
//                    score = minMax(dep - 1, false, false);
//                    if(score > fS) {
//                        fI = i, fJ = j, fS = score;
//                    }
//                    board[i][j] = ' ';
//                }
//            }
//        }
//        if(IsFirst) {
//            Final_i = fI, Finalj = fJ;
//        }
//        return fS;
//    } else {
//        int fS = 1e3, fI, fJ, score;
//        for(int i = 0; i < n_rows; i++) {
//            for(int j = 0; j < n_cols; j++) {
//                if(board[i][j] == ' ') {
//                    board[i][j] = 'O';
//                    score = minMax(dep - 1, true, false);
//                    if(score < fS) {
//                        fS = score, fI = i, fJ = j;
//                    }
//                    board[i][j] = ' ';
//                }
//            }
//        }
//        if(IsFirst) {
//            Final_i = fI, Finalj = fJ;
//        }
//        return fS;
//    }
//}
//
//int Four_in_a_row::get_winner() {
//    return winner;
//}

