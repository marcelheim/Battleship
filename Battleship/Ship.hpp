//
//  Ship.hpp
//  Battleship
//
//  Created by Marcel Heim on 13.03.20.
//  Copyright © 2020 Marcel Heim. All rights reserved.
//

#ifndef Ship_hpp
#define Ship_hpp

//Vereinfachung der Koordinatenübergabe
struct Point
{
    int x, y;
    Point(){
        x = 0;
        y = 0;
    }
    Point(int x, int y): x(x), y(y){}
};

class Ship{
private:
    //Schiff (Rechteck) lässt sich durch 2 Punkte definieren
    Point _position[2];
    //Das Schiff kann zwei Ausrichtungen haben: Horizontal und Vertikal
    char _alignment;
    //Jedes Schiff hat eine Id. Mit ihr kann auf dem Spielfeld bestimmt werden welches Schiff wo ist
    int _id;
    //Länge des Schiffs
    int _length;
public:
    Ship();
    Ship(int length, Point position, char alignment, int id);
    bool handleAttack(Point position);
    Point* getPosition();
    char getAlignment();
    int getId();
    int getLength();
};

#endif /* Ship_hpp */
