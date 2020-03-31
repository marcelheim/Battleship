//
//  Ship.cpp
//  Battleship
//
//  Created by Marcel Heim on 13.03.20.
//  Copyright © 2020 Marcel Heim. All rights reserved.
//

#include "Ship.hpp"

Ship::Ship(int length, Point position, char alignment, int id){
    _position[0].x = position.x;
    _position[0].y = position.y;
    _alignment = alignment;
    _length = length;
    _sunk = false;
    _id = id;
    
    if(alignment == 'V'){
        _position[1].x = position.x;
        _position[1].y = position.y + length - 1;
        
    }
    else {
        _position[1].x = position.x + length - 1;
        _position[1].y = position.y;
    }
    
    for(int i = 0; i < length; i++){
        _shipDamageVector.push_back(false);
    }
    _blockedArea[0].x = _position[0].x - 1;
    _blockedArea[0].y = _position[0].y - 1;
    _blockedArea[1].x = _position[1].x + 1;
    _blockedArea[1].y = _position[1].y + 1;
    
    if(_blockedArea[0].x < 0) _blockedArea[0].x = 0;
    if(_blockedArea[0].y < 0) _blockedArea[0].y = 0;
    if(_blockedArea[1].x > 9) _blockedArea[1].x = 9;
    if(_blockedArea[1].y > 9) _blockedArea[1].y = 9;

}

Point* Ship::getPosition(){
    return _position;
}

Point* Ship::getBlockedArea(){
    return _blockedArea;
}

bool Ship::handleAttack(Point position){
    bool sunkTmp = true;
    bool hit = false;
    int areaId;
    
    if(position.x >= _position[0].x && position.x <= _position[1].x && position.y >= _position[0].y && position.y <= _position[1].y) hit = true;
    
    if(hit){
        if(_alignment == 'V') areaId = position.y - _position[0].y;
        else areaId = position.x - _position[0].x;
        _shipDamageVector[areaId] = true;
    }
    
    for (auto areaDamage : _shipDamageVector){
        if(!areaDamage) sunkTmp = false;
    }
    
    _sunk = sunkTmp;
    
    return hit;
}

char Ship::getAlignment(){
    return _alignment;
}

int Ship::getId(){
    return _id;
}

bool Ship::isSunk(){
    return _sunk;
}

int Ship::getLength(){
    return _length;
}

vector<bool> Ship::getShipDamageVector(){
    return _shipDamageVector;
}
