//
//  Game.hpp
//  Battleship
//
//  Created by Marcel Heim on 13.03.20.
//  Copyright © 2020 Marcel Heim. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include "Board.hpp"

using namespace std;

class Game{
private:
    Board _boardArray[2];
    int _player;
    bool _end;
    char _symbols[4] = {' ', '*', 'x', '+'};
public:
    Game();
    void gameLoop();
    void drawGame();
    void handleInputGame();
};

#endif /* Game_hpp */
