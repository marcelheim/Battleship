//
//  main.cpp
//  Battleship
//
//  Created by Marcel Heim on 13.03.20.
//  Copyright © 2020 Marcel Heim. All rights reserved.
//

#include <iostream>
#include "Game.hpp"

using namespace std;

int main() {
    
    Game game = Game();
    game.gameLoop();
    
    return 0;
}
