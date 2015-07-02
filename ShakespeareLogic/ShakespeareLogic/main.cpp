//
//  main.cpp
//  ShakespeareLogic
//
//  Created by Max Bilbow on 01/07/2015.
//  Copyright © 2015 Rattle Media. All rights reserved.
//


#include <iostream>
#include "LiteraryLogic.hpp"

/**
 Shakespeare Logic
 Because Swift is such a readable programming language,
 I have begun an ambitious project to rewrite all of Shakespeare’s literature in it...
 And compare it with C++
 */
using namespace std;

void Shakespeare::toBe(bool toBe) {
    if (toBe || !toBe) {
        cout << "That is the Question" << endl;
    }
}

void Poetry::askAboutTheBell(string * question) {
    if (question != nullptr) {
        throw invalid_argument("Ask NOT for whom the bell tolls. It tolls for thee!");
    } else {
        cout << "Very good" << endl;
    }
}

int main(int argc, const char * argv[]) {
    Shakespeare::toBe(true);
    Shakespeare::toBe(false);
    
    try {
        Poetry::askAboutTheBell(new string("For whom does the bell toll?"));
    } catch (invalid_argument e) {
        cout << e.what() << endl;
        Poetry::askAboutTheBell(NULL);
    }
    return 0;
}