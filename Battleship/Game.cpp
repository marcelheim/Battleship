//
//  Game.cpp
//  Battleship
//
//  Created by Marcel Heim on 13.03.20.
//  Copyright © 2020 Marcel Heim. All rights reserved.
//

#include "Game.hpp"

Game::Game(){
    _boardArray[0] = Board();
    _boardArray[1] = Board();
    _player = 0;
    _end = false;
        
    _boardArray[0].addShip(4, Point(0,6), 'V');
    _boardArray[0].addShip(3, Point(2,6), 'V');
//    _boardArray[0].handleAttack(Point(2,7));
//    _boardArray[0].handleAttack(Point(2,8));
//    _boardArray[0].handleAttack(Point(2,6));
}

void Game::gameLoop(){
    while (!_end) {
        drawGame();
        handleInputGame();
    }
}

void Game::drawGame(){
    system("clear");
    int symbolId, x, y;
    cout << " A B C D E F G H I J" << endl;
    for (y = 0; y < 10; y++) {
        cout << y;
        for (x = 0; x < 10; x++) {
            symbolId = _boardArray[0].boardMatrix[x][y];
            cout << _symbols[symbolId] << " ";
        }
        cout << endl;
    }
}

void Game::handleInputGame(){
    Point position;
    
    cout << "X: ";
    cin >> position.x;
    
    cout << "Y: ";
    cin >> position.y;
    
    _boardArray[0].handleAttack(position);
    
    _end = _boardArray[0].isGameOver();
}
