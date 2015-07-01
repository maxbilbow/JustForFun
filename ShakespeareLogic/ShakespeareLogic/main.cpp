//
//  main.cpp
//  ShakespeareLogic
//
//  Created by Max Bilbow on 01/07/2015.
//  Copyright © 2015 Rattle Media. All rights reserved.
//


#include <iostream>
//#include "ShakespeareLogic.hpp"
/**
 Shakespeare Logic
 Because Swift is such a readable programming language,
 I have begun an ambitious project to rewrite all of Shakespeare’s literature in it...
 And compare it with C++
 */
class ShakespeareLogic {
public:
    
    ///To be or not to be...
    static void toBe(bool toBe);
    
    ///For whom the bell tolls
    static void askAboutTheBell(std::string * question);
    
};

//ShakespeareLogic.cpp
using namespace std;

void ShakespeareLogic::toBe(bool toBe) {
    if (toBe || !toBe) {
        cout << "That is the Question" << endl;
    }
}

void ShakespeareLogic::askAboutTheBell(string * question) {
    if (question != nullptr) {
        throw invalid_argument("Ask NOT for whom the bell tolls. It tolls for thee!");
    } else {
        cout << "Very good" << endl;
    }
}

int main(int argc, const char * argv[]) {
    ShakespeareLogic::toBe(true);
    ShakespeareLogic::toBe(false);
    
    try {
        ShakespeareLogic::askAboutTheBell(new string("For whom does the bell toll?"));
    } catch (invalid_argument e) {
        cout << e.what() << endl;
        ShakespeareLogic::askAboutTheBell(NULL);
    }
    return 0;
}
