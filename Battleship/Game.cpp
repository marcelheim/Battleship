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
    _end = false;
    srand((uint32_t)time(NULL));
}

void Game::gameLoop(){
    placement(0);
    placement(1);
    _player = rand() % 2;
    while (!_end) {
        _end = _boardArray[flipFlop(_player)].isGameOver();
        if(!_end){
            drawGame();
            handleInputGame();
        }
    }
    system("clear");
    cout << "Gewinner: Spieler " << _player + 1 << endl << endl;
    int symbolId, x, y, i;
    cout << "Spielfeld 1:\t\tSpielfeld 2:" << endl;
    cout << "  1 2 3 4 5 6 7 8 9 10\t  1 2 3 4 5 6 7 8 9 10" << endl;
    for (y = 0; y < 10; y++) {
        for(i = 0; i <= 1; i++){
            cout << (char) (y + 65) << " ";
            for (x = 0; x < 10; x++) {
                if(_boardArray[i].boardMatrix[x][y] != 2 && _boardArray[i].shipMatrix[x][y] != 0) symbolId = 4;
                else symbolId = _boardArray[i].boardMatrix[x][y];
                cout << _symbols[symbolId] << " ";
            }
            cout << "\t";
        }
        cout << endl;
    }
}

void Game::placement(int id){
    int x, y, length;
    Point position;
    char alignment, ready;
    bool done = false;
    string input;
    regex r("([A-Z])([0-9]+)([A-Z])([0-9]+)");
    smatch m;
    
    while (!done) {
        system("clear");
        
        done = true;
        for(auto element : _maxShipTypeCount){
            if(_boardArray[id].getShipTypeCount()[element.first] < element.second) done = false;
        }
        cout << "Spieler: " << id + 1 << " | Anzahl Schiffe der Länge";
        for(auto element : _maxShipTypeCount){
            cout << " " << element.first << ": " <<  _boardArray[id].getShipTypeCount()[element.first] << "/" << element.second << ",";
        }
        cout << endl << endl;
        cout << "   1 2 3 4 5 6 7 8 9 10" << endl;
        for (y = 0; y < 10; y++) {
            cout << (char) (y + 65) << " ";
            for (x = 0; x < 10; x++) {
                cout << " ";
                if(_boardArray[id].shipMatrix[x][y] > 0) cout << _symbols[2];
                else cout << _symbols[0];
            }
            cout << endl;
        }
        
        if(!done){
            cout << "\nSchiffsplatzierung: ";
            try{
                cin >> input;
            }
            catch(...){
                cout << "Error";
            }
            
            if(regex_match(input, r)){
                regex_search(input, m, r);
                                            
                position.y = (int) m[1].str()[0] - 65;
                position.x = stoi(m[2]) - 1;
                alignment = m[3].str()[0];
                length = stoi(m[4]);
                
                
                
                if(addShip(length, position, alignment, id)) done = false;
            }
        }
        else{
            //Check for n
            cout << endl << "Bereit?(y/n): ";
            try{
                cin >> ready;
            }
            catch(...){
                cout << "Error";
            }
            if(ready == 'n'){
                _boardArray[id].init();
                done = false;
            }
        }
    }
    
    
}

bool Game::addShip(int length, Point position, char alignment, int id){
    if(_boardArray[id].getShipTypeCount()[length] >= _maxShipTypeCount[length]) return false;
    else return _boardArray[id].addShip(length, position, alignment);
}

void Game::drawGame(){
    system("clear");
    int symbolId, x, y, i;
    cout << "Spieler: " << _player + 1<< endl << endl;
    cout << "Spielfeld 1:\t\tSpielfeld 2:" << endl;
    cout << "  1 2 3 4 5 6 7 8 9 10\t  1 2 3 4 5 6 7 8 9 10" << endl;
    for (y = 0; y < 10; y++) {
        for(i = 0; i <= 1; i++){
            cout << (char) (y + 65) << " ";
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
    string input;
    regex r("([A-Z])([0-9]+)");
    smatch m;
    bool done = false;
    
    while(!done){
        cout << "Angriff: ";
        try{
            cin >> input;
        }
        catch(...){
            cout << "Error";
        }
        if(regex_match(input, m, r)){
            regex_search(input, m, r);
            position.y = (int) m[1].str()[0] - 65;
            position.x = stoi(m[2]) - 1;
            if(position.y < 10 && position.x < 10) done = true;
        }
    }
    
    if(!_boardArray[flipFlop(_player)].handleAttack(position)){
        _player = flipFlop(_player);
    }
}

int Game::flipFlop(int i){
    if(i == 0) return 1;
    else return 0;
}
