#include"Board.h"
#include"players.h"
#include <iostream>
class GameManager {
private:
    Board* boardPtr;
    Player* player1 ,*player2;
    bool  flag;
public:
    GameManager(Board*, Player*player1,Player* player2,bool flag);
    void run();
};

