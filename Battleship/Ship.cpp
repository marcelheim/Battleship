//
//  Ship.cpp
//  Battleship
//
//  Created by Marcel Heim on 13.03.20.
//  Copyright © 2020 Marcel Heim. All rights reserved.
//

#include "Ship.hpp"

//Konstruktor eines Schiffs
Ship::Ship(int length, Point position, char alignment, int id){
    _position[0].x = position.x;
    _position[0].y = position.y;
    _alignment = alignment;
    _length = length;
    _id = id;
    
    //Punkt B der Fläche des Schiffs wird mit Hilfe der Länge berechnet
    if(alignment == 'V'){
        _position[1].x = position.x;
        _position[1].y = position.y + length - 1;
        
    }
    else {
        _position[1].x = position.x + length - 1;
        _position[1].y = position.y;
    }
}

//Wird das Schiff angegriffen so bestätigt es den Treffer + später zusätzliche Funktionalität
bool Ship::handleAttack(Point position){
    bool hit = false;
    
    if(position.x >= _position[0].x && position.x <= _position[1].x && position.y >= _position[0].y && position.y <= _position[1].y) hit = true;
    
    return hit;
}

Point* Ship::getPosition(){
    return _position;
}

char Ship::getAlignment(){
    return _alignment;
}

int Ship::getId(){
    return _id;
}

int Ship::getLength(){
    return _length;
}
