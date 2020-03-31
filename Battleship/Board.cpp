//
//  Board.cpp
//  Battleship
//
//  Created by Marcel Heim on 13.03.20.
//  Copyright © 2020 Marcel Heim. All rights reserved.
//

#include "Board.hpp"

Board::Board(){
    init();
}

void Board::init(){
    _sunkenShipsCount = 0;
    _gameOver = false;
    for(int y = 0; y < 10; y++){
        for(int x = 0; x < 10; x++){
            boardMatrix[x][y] = 0;
            shipMatrix[x][y] = 0;
        }
    }
    _shipVector.clear();
    _shipTypeCount.clear();
}

Board::~Board(){}

bool Board::addShip(int length, Point position, char alignment){
    int id = (int) _shipVector.size() + 1;
    bool isValid = true;
    
    Ship newShip = Ship(length, position, alignment,id);
    
    if(newShip.getPosition()[0].x < 0 || newShip.getPosition()[0].y < 0) isValid = false;
    if(newShip.getPosition()[0].x > 9 || newShip.getPosition()[0].y > 9) isValid = false;
    if(newShip.getPosition()[1].x > 9 || newShip.getPosition()[1].y > 9) isValid = false;
    if(isValid){
        for(auto existingShip : _shipVector){
            if(doOverlap(newShip.getPosition()[0], newShip.getPosition()[1], existingShip.getBlockedArea()[0], existingShip.getBlockedArea()[1])) isValid = false;
        }
    }
    if(isValid){
        
        if(_shipTypeCount.find(length) == _shipTypeCount.end()){
            _shipTypeCount[length] = 0;
        }
        _shipTypeCount[length]++;
        
        for (int i = 0; i < length; i++) {
            if(alignment == 'V')  shipMatrix[position.x][position.y+i] = id;
            else shipMatrix[position.x+i][position.y] = id;
        }
        _shipVector.push_back(newShip);
        return true;
    }
    else{
        return false;
    }
}

bool Board::doOverlap(Point A1, Point A2, Point B1, Point B2){
    bool overlap = true;
    
    if(A1.x > B2.x || B1.x > A2.x) overlap = false;
    
    if(A1.y > B2.y || B1.y > A2.y) overlap = false;
    
    return overlap;
}

//TODO: Implement search for object with id
bool Board::handleAttack(Point position){
    int id = shipMatrix[position.x][position.y];
    bool hit = false;
    if(id != 0){
        hit = _shipVector[id-1].handleAttack(position);
        boardMatrix[position.x][position.y] = 2;
        if(_shipVector[id-1].isSunk()) {
            for (int y = _shipVector[id-1].getBlockedArea()[0].y; y <= _shipVector[id-1].getBlockedArea()[1].y; y++) {
                for (int x = _shipVector[id-1].getBlockedArea()[0].x; x <= _shipVector[id-1].getBlockedArea()[1].x; x++) {
                    if(boardMatrix[x][y] != 1) boardMatrix[x][y] = 3;
                }
            }
            for (int y = _shipVector[id-1].getPosition()[0].y; y <= _shipVector[id-1].getPosition()[1].y; y++) {
                for (int x = _shipVector[id-1].getPosition()[0].x; x <= _shipVector[id-1].getPosition()[1].x; x++) {
                    boardMatrix[x][y] = 2;
                }
            }
            _sunkenShipsCount++;
        }
    }
    else{
        boardMatrix[position.x][position.y] = 1;
    }
    if(_sunkenShipsCount >= _shipVector.size()) _gameOver = true;
    return hit;
}

bool Board::isGameOver(){
    return _gameOver;
}

int Board::getSunkenShipsCount(){
    return _sunkenShipsCount;
}

map<int,int> Board::getShipTypeCount(){
    return _shipTypeCount;
}
