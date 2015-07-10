//
//  LinkedList.hpp
//  JustForFun
//
//  Created by Max Bilbow on 09/07/2015.
//  Copyright © 2015 Rattle Media. All rights reserved.
//

#ifndef LinkedList_cpp
#define LinkedList_cpp

#include <stdio.h>

#endif /* LinkedList_cpp */

//template <class Value>
//class Node {
//    
//    
//public:
//   
//};

typedef struct _Node {
    void * value;
    _Node * next;
} Node;

//template <class Value> struct Node {
//public:
//    Value value;
//    Node * next;
//};
/*
template <class Value> class LinkedList {
    int _count = 0;
    Node<Value> * _head = new Node<Value>();
    Node<Value> * _last(void);
public:
    const int (^count)(void) = ^(void) {
        return _count;
    };
    
    LinkedList();
    
    const Value(^first)(void) = ^(void) {
        return this->_head->next->value;
    };
    
    const Value(^last)(void) = ^(void) {
        return this->_last()->value;
    };
    
    Value append(Value value);
    
//    static void print_list(Node<Value> * head);
    void print(void);
    
//    static int pop(Node<Value> ** head);
    Value pop(Node<Value> ** head);
    
//    static int remove_by_value(Node<Value> ** head, int val);
    Value remove_by_value(int val);
    
   
    
//    template <class Value>
};


void LinkedListTest(void);

*/
