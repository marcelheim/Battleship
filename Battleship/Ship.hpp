//
//  Ship.hpp
//  Battleship
//
//  Created by Marcel Heim on 13.03.20.
//  Copyright © 2020 Marcel Heim. All rights reserved.
//

#ifndef Ship_hpp
#define Ship_hpp

#include <vector>

using namespace std;

struct Point
{
    int x, y;
    Point(){}
    Point(int x, int y): x(x), y(y){}
};

//TODO: Variable Boardsize
class Ship{
private:
    vector<bool> _shipDamageVector;
    Point _position[2];
    Point _blockedArea[2];
    char _alignment;
    int _id;
    bool _sunk;
    int _length;
public:
    Ship();
    Ship(int length, Point position, char alignment, int id);
    bool handleAttack(Point position);
    Point* getPosition();
    Point* getBlockedArea();
    char getAlignment();
    int getId();
    bool isSunk();
    int getLength();
    vector<bool> getShipDamageVector();
};

#endif /* Ship_hpp */
