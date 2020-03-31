//
//  Board.cpp
//  Battleship
//
//  Created by Marcel Heim on 13.03.20.
//  Copyright © 2020 Marcel Heim. All rights reserved.
//

#include "Board.hpp"

//Konstruktor
Board::Board(){
    init();
}

//Initialisierung des Spielfeldes (für späteren Neustart)
void Board::init(){
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

//Hinzufügen neuer Schiffe (mit bestätigung)
bool Board::addShip(int length, Point position, char alignment){
    int id = (int) _shipVector.size() + 1;
    bool isValid = true;
    
    Ship newShip = Ship(length, position, alignment,id);
    
    //Wenn Schiff innerhalb des Spielfeldes
    if(newShip.getPosition()[0].x < 0 || newShip.getPosition()[0].y < 0) isValid = false;
    if(newShip.getPosition()[0].x > 9 || newShip.getPosition()[0].y > 9) isValid = false;
    if(newShip.getPosition()[1].x > 9 || newShip.getPosition()[1].y > 9) isValid = false;
    if(isValid){
        //Anzahl der Schiffe wird erhöht
        _shipTypeCount[length]++;
        
        //SchiffsId wird in der Schiffe Matrix eingetragen
        for (int i = 0; i < length; i++) {
            if(alignment == 'V')  shipMatrix[position.x][position.y+i] = id;
            else shipMatrix[position.x+i][position.y] = id;
        }
        //Schiff wird hinzugefügt
        _shipVector.push_back(newShip);
        return true;
    }
    else{
        return false;
    }
}

//Bestätigung + eintragung in die Spielmatrix des Schiffs
bool Board::handleAttack(Point position){
    int id = shipMatrix[position.x][position.y];
    bool hit = false;
    if(id != 0){
        hit = _shipVector[id-1].handleAttack(position);
        if(hit) boardMatrix[position.x][position.y] = 2;
    }
    else{
        boardMatrix[position.x][position.y] = 1;
    }
    return hit;
}

bool Board::isGameOver(){
    return _gameOver;
}

map<int,int> Board::getShipTypeCount(){
    return _shipTypeCount;
}
