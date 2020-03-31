//
//  Game.cpp
//  Battleship
//
//  Created by Marcel Heim on 13.03.20.
//  Copyright © 2020 Marcel Heim. All rights reserved.
//

#include "Game.hpp"

//Konstruktor mit Initialisierung
Game::Game(){
    _boardArray[0] = Board();
    _boardArray[1] = Board();
    _end = false;
    srand((uint32_t)time(NULL));
}

//Spielablauf
void Game::gameLoop(){
    placement(0);
    placement(1);
    //Auswählen eines zufälligen Spielers
    _player = rand() % 2;
    while (!_end) {
        _end = _boardArray[flipFlop(_player)].isGameOver();
        if(!_end){
            drawGame();
            handleInputGame();
        }
    }
}

//Platzieren der Schiffe
void Game::placement(int id){
    int x, y, length;
    Point position;
    char alignment, ready;
    bool done = false;
    
    while (!done) {
        system("clear");
        done = true;
        for(auto element : _maxShipTypeCount){
            if(_boardArray[id].getShipTypeCount()[element.first] < element.second) done = false;
        }
        cout << "Player: " << id + 1 << endl << endl;
        cout << "  A B C D E F G H I J" << endl;
        for (y = 0; y < 10; y++) {
            cout << y;
            for (x = 0; x < 10; x++) {
                cout << " ";
                if(_boardArray[id].shipMatrix[x][y] > 0) cout << _symbols[2];
                else cout << _symbols[0];
            }
            cout << endl;
        }
        
        if(!done){
            cout << "X: ";
            cin >> position.x;
            
            cout << "Y: ";
            cin >> position.y;
            
            cout << "Alignment (H/V): ";
            cin >> alignment;
            
            cout << "Length: ";
            cin >> length;
            
            if(_boardArray[id].addShip(length, position, alignment)) done = false;
        }
        else{
            cout << endl << "Ready?(y/n): ";
            cin >> ready;
            if(ready != 'y'){
                _boardArray[id].init();
                done = false;
            }
        }
    }
    
    
}

void Game::drawGame(){
    system("clear");
    int symbolId, x, y, i;
    cout << "Player: " << _player + 1<< endl << endl;
    cout << "Board 1:\t\tBoard 2:" << endl;
    cout << "  A B C D E F G H I J\t  A B C D E F G H I J" << endl;
    for (y = 0; y < 10; y++) {
        for(i = 0; i <= 1; i++){
            cout << y << " ";
            for (x = 0; x < 10; x++) {
                symbolId = _boardArray[i].boardMatrix[x][y];
                cout << _symbols[symbolId] << " ";
            }
            cout << "\t";
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
    
    if(!_boardArray[flipFlop(_player)].handleAttack(position)){
        _player = flipFlop(_player);
    }
}

int Game::flipFlop(int i){
    if(i == 0) return 1;
    else return 0;
}
