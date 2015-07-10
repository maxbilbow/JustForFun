//
//  Fibb.hpp
//  JustForFun
//
//  Created by Max Bilbow on 10/07/2015.
//  Copyright © 2015 Rattle Media. All rights reserved.
//

#ifndef Fibb_cpp
#define Fibb_cpp

#include <stdio.h>

#endif /* Fibb_cpp */



class Fibb {
public:
    typedef struct _Node {
    public:
        __uint64_t value;// = 1;
        int position;// = 1;
        _Node * prev = NULL;
        
        _Node(_Node * prev) {
            if (prev == NULL || prev->prev == NULL) {
                value = 1;
                position = prev == NULL ? 1 : 2;
            } else {
                value = prev->value + prev->prev->value;
                position = prev->position + 1;
            }
            this->prev = prev;
        }
    } Node;
    
private:
    Node * _top;
    
public:
//    Fibb(int position);
    Fibb();
    
    Node * current();
    
    Node * next();
    
    Node * previous();
    
    __uint64_t valueAtPosition(int position);
    
    
    
    int positionOfValue(int position);
    
    static __uint64_t ValueAtPosition(int position) {
        Node * result = new Node(NULL);
        while (result->position != position) {
            result = new Node(result);
            printf("position: %3i, Value: %18lli\n",result->position,result->value);//); std::cout << result->value << std::endl;
            delete (result->prev);
        }
        return result->value;
    };
};
//static long FibbValueAtPosition(int position);

void FibbTest();