//
//  Board.hpp
//  Battleship
//
//  Created by Marcel Heim on 13.03.20.
//  Copyright © 2020 Marcel Heim. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <iostream>
#include <map>
#include <vector>
#include "Ship.hpp"

using namespace std;

class Board{
private:
    vector<Ship> _shipVector;
    bool _gameOver;
    map<int,int> _shipTypeCount;
    int _sunkenShipsCount;
public:
    //TODO: Replace array with class
    int boardMatrix[10][10];
    int shipMatrix[10][10];
    bool doOverlap(Point A1, Point A2, Point B1, Point B2);
    Board();
    ~Board();
    void init();
    bool addShip(int length, Point position, char alignment);
    bool handleAttack(Point position);
    bool isGameOver();
    int getSunkenShipsCount();
    map<int,int> getShipTypeCount();
};

#endif /* Board_hpp */
