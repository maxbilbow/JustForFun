//
//  main.cpp
//  99GreenBottlesCPP
//
//  Created by Max Bilbow on 01/07/2015.
//  Copyright © 2015 Rattle Media. All rights reserved.
//

#include <iostream>
#include "99GreenBottles.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    
    Wall wall = Wall();

    do {
        cout << wall.toString() << endl;
    } while (wall.shouldOneGreenBottleAccidentallyFall());
    
    return 0;
}
