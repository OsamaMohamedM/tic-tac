#include<bits/stdc++.h>
#include "BoardGame_Classes.h"
using namespace std;
int main() {

    char choose = 'y';
    cout << "Hello ya ma3llem\n";
    while (choose != 'n')
    {
        cout << "enter your name\n";
        Player* obj = new Player(1, 'O');
        cout << "lw enta wa7eed e5tar 1\n";
        char c; cin >> c;
        if (c == '1')
        {
            cout << "e5tar any wa7da\n"
                    "1)Pyramid\n"
                    "2)Four-in-a-row\n"
                    "3)5 x 5 Tic Tac Toe"\n;
            int x; cin >> x;
            if (x == 1)
            {
                pyramid* bo=new pyramid();
                RandomPlayer* obj2 = new RandomPlayer('X', 1);
                GameManager* marawan = new GameManager(bo, obj, obj2,true);
                marawan->run();
            }
            if (x == 2)
            {
                Four_in_a_row* ob = new Four_in_a_row();
                RandomPlayer* obj2 = new RandomPlayer('X', 2);
                GameManager* osos = new GameManager(ob, obj, obj2, true);
                osos->run();
            }
            else if (x == 3)
            {
                FiveByFiveBoard* ob = new FiveByFiveBoard();
                RandomPlayer* obj2 = new RandomPlayer('X', 2);
                GameManager* wageh = new GameManager(ob, obj, obj2, true);
                wageh->run();
            }
        }
        else
        {
            cout << "enter your name\n";
            Player* obj2 = new Player(2, 'X');
            cout << "e5tar any wa7da\n"
                    "1)Pyramid\n"
                    "2)Four-in-a-row\n"
                    "3)5 x 5 Tic Tac Toe\n";
            int x; cin >> x;
            if (x == 1)
            {
                pyramid* bo = new pyramid();
                GameManager* marawan = new GameManager(bo, obj, obj2, false);
                marawan->run();
            }
            if (x == 2)
            {
                Four_in_a_row* ob = new Four_in_a_row();
                GameManager* osos = new GameManager(ob, obj, obj2, false);
                osos->run();
            }
            else if (x == 3)
            {
                FiveByFiveBoard* ob = new FiveByFiveBoard();
                GameManager* wageh = new GameManager(ob, obj, obj2, false);
                wageh->run();
            }

        }


    }

    return 0;
}
