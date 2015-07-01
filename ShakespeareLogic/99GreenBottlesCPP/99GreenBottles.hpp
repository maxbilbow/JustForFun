//
//  99GreenBottles.hpp
//  ShakespeareLogic
//
//  Created by Max Bilbow on 01/07/2015.
//  Copyright © 2015 Rattle Media. All rights reserved.
//

#ifndef _9GreenBottles_cpp
#define _9GreenBottles_cpp

#include <stdio.h>

#endif /* _9GreenBottles_cpp */


//
//  99GreenBottles.swift
//  ShakespeareLogic
//
//  Created by Max Bilbow on 01/07/2015.
//  Copyright © 2015 Rattle Media. All rights reserved.
//

#include <iostream>
class Bottle;

class Wall {
    ///Private array of all bottles
    Bottle (* bottles);
    ///default total number of bottles
    int totalBottles = 99;
    ///the number of green non-fallen bottles
    int numberOfGreenBottles();
    ///private initializer call
    void init();
public:
    ///Returns an array of all green bottles that have not accidentally fallen.
    Bottle * greenBottlesSittingOnTheWall();
    
    ///Default initialiser starts with 99 bottles
    Wall();
    ///Initialize wall with number of bottles. Default is 99
    Wall(int numberOfGreenBottles);
    
    ///Should one green bottle accidentally fall?
    ///Returns false if there are no green bottles remaining on the wall
    bool shouldOneGreenBottleAccidentallyFall();
    
    ///How many green bottles are currently on the wall
    std::string toString();
};

