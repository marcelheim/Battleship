//
//  Board.hpp
//  Battleship
//
//  Created by Marcel Heim on 13.03.20.
//  Copyright © 2020 Marcel Heim. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <map>
#include <vector>
#include "Ship.hpp"

using namespace std;

//TODO: Variable Boardsize
class Board{
private:
    //Enthält alle Schiffe auf dem Feld
    vector<Ship> _shipVector;
    //Ob das Spielfeld verloren hat
    bool _gameOver;
    //Schiffe werden je nach Typ (Länge) gezählt
    map<int,int> _shipTypeCount;
public:
    //Matrix für sichtbares Spielfeld für Gegner während der Spielphase
    int boardMatrix[10][10];
    //Matrix für Platzierung der Schiffe
    int shipMatrix[10][10];
    Board();
    void init();
    bool addShip(int length, Point position, char alignment);
    bool handleAttack(Point position);
    bool isGameOver();
    map<int,int> getShipTypeCount();
};

#endif /* Board_hpp */
