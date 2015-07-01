//
//  99GreenBottles.cpp
//  ShakespeareLogic
//
//  Created by Max Bilbow on 01/07/2015.
//  Copyright © 2015 Rattle Media. All rights reserved.
//

#include "99GreenBottles.hpp"
using namespace std;
//string * hello = new string[90];

enum BottleColor {
    Green, Blue, Red
};

class Bottle {
    
    
public:
    BottleColor color;
    bool didAccidentallyFall = false;
    
    Bottle(){};
    
    Bottle(BottleColor color) {
        this->color = color;
    }
    
    ///if accidentally is true, didAccidentallyFall will be set as true.
    void fall(bool accidentally){
        didAccidentallyFall = accidentally;
    }
};


Wall::Wall() {
    this->init();
}

void Wall::init(){
    this->bottles = new Bottle[this->totalBottles];
    for (int i = 0; i < this->totalBottles; ++i) {
        this->bottles[i] = *new Bottle(Green);
    }
}

///Initialize wall with number of bottles. Default is 99
Wall::Wall(int numberOfGreenBottles) {
    this->totalBottles = numberOfGreenBottles;
    this->init();
}

int Wall::numberOfGreenBottles() {
    int total = 0;
    for (int i=0; i < this->totalBottles; ++i) {
        if (this->bottles[i].color == Green && this->bottles[i].didAccidentallyFall == false ) {
            ++total;
        }
    }
    return total;
}

///Returns an array of all green bottles that have not accidentally fallen.
Bottle * Wall::greenBottlesSittingOnTheWall() {
    int total = this->numberOfGreenBottles();
    Bottle * result[total];
    for (int i=0; i < total; ++i) {
        if (this->bottles[i].color == Green && this->bottles[i].didAccidentallyFall == false ) {
            result[i] = &this->bottles[i];
        }
    }
    
    return *result;
}

///Should one green bottle accidentally fall?
///Returns false if there are no green bottles remaining on the wall
bool Wall::shouldOneGreenBottleAccidentallyFall() {
//    Bottle * bottles = this->greenBottlesSittingOnTheWall();
    int total = this->numberOfGreenBottles();
    if (total > 0) {
        string noun = total == 2 ? "bottle" : "bottles";
        string numberOfBottles = total == 1 ? "no" : to_string(total - 1);
        
        cout << "And if one green bottle should accidentally fall" << endl;
        this->greenBottlesSittingOnTheWall()[total-1].fall(true);
        
        cout << "There'll be " << numberOfBottles << " green " << noun << " sitting on the wall" << endl;
        
        return total > 1;
    } else {
        return false;
    }
    
}


///How many green bottles are currently on the wall
string Wall::toString() {
    int count = this->numberOfGreenBottles();// sizeof(this->greenBottlesSittingOnTheWall());
    string result = "";
    if (count == 1) {
        result = to_string(count) + " green bottle";
    } else {
        result = to_string(count) + " green bottles";
    }
    result = "\n" + result + " sitting on the wall";
    return result + result;
    
}



