//
//  Game.hpp
//  Battleship
//
//  Created by Marcel Heim on 13.03.20.
//  Copyright © 2020 Marcel Heim. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <string>
#include <iostream>
#include <time.h>
#include "Board.hpp"

using namespace std;

class Game{
private:
    Board _boardArray[2];
    int _player;
    bool _end;
    string _symbols[5] = {"\x1b[1;34m~\x1b[0m", "\x1b[1;91m●\x1b[0m", "\x1b[1;92m■\x1b[0m", "\x1b[1;97m†\x1b[0m", "\x1b[1;91m■\x1b[0m"};
    //string _symbols[5] = {"~", "*", "x", "+", "#"};
    map<int, int> _maxShipTypeCount = {
        {2,4},
        {3,3},
        {4,2},
        {5,1}
    };
public:
    Game();
    //TODO: Complete
    void gameLoop();
    //TODO: Parse input
    void placement(int id);
    bool addShip(int length, Point position, char alignment, int id);
    void drawGame();
    void handleInputGame();
    int flipFlop(int i);
};

#endif /* Game_hpp */
