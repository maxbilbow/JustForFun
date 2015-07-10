//
//  Fibb.cpp
//  JustForFun
//
//  Created by Max Bilbow on 10/07/2015.
//  Copyright © 2015 Rattle Media. All rights reserved.
//
#include <iostream>
#include "Fibb.hpp"

using namespace std;

Fibb::Fibb() {
    _top = new Node(NULL);
}

typename Fibb::Node * Fibb::next() {
    _top = new Node(_top);
    return _top;
}

typename Fibb::Node * Fibb::current() {
    return _top;
}


typename Fibb::Node * Fibb::previous() {
    return _top->prev;
}

__uint64_t Fibb::valueAtPosition(int position) {
    if (position == _top->position) {
        return _top->value;
    } else if (position > _top->position) {
        do {
            _top = new Node(_top);
        } while (_top->position != position);
        return _top->value;
    } else {
        Node * result = _top;
        do {
            result = result->prev;
        } while (result->position != position);
        return result->value;
    }
}



//int Fibb::positionOfValue(long position);

void FibbTest() {
    Fibb fib = Fibb();
    printf("position: %i, Value: %lli\n", fib.current()->position, fib.current()->value);
    
    printf("position: %i, Value: %lli\n", fib.next()->position, fib.next()->value);
    printf("position: %i, Value: %lli\n", fib.next()->position, fib.next()->value);
    
    printf("Long Long:           %lli\n", __UINT64_MAX__);
    int pos = 93;
//    long long result = Fibb::ValueAtPosition(pos);
//    printf("position: %i, Value: %lli\n", pos, result);
    
    __uint64_t result = Fibb::ValueAtPosition(pos);
    printf("position: %3i, Value: ",pos); cout << result << endl;
    
    pos = 50;
    result = fib.valueAtPosition(pos);
    printf("position: %3i, Value: ",pos); cout << result << endl;
    
    pos = 80;
    result = fib.valueAtPosition(pos);
    printf("position: %3i, Value: ",pos); cout << result << endl;
    
    
}