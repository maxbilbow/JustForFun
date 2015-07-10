//
//  LinkedList.cpp
//  JustForFun
//
//  Created by Max Bilbow on 09/07/2015.
//  Copyright © 2015 Rattle Media. All rights reserved.
//

#include "LinkedList.hpp"
#include <iostream>

//typedef LinkedList<Value> LinkedList;
//using namespace LinkedList<Value> LinkedList;
//template <class Value>
//typedef struct LinkedList<Value>::_node {
////    Value value;
////    _node * next;
//}Node;

template <class Value> LinkedList<Value>::LinkedList() {
//    this->node = new Node<Value>();
//    this->node.value = NULL;
    this->first = ^(void) {
        return this->_head->value;
    };
};


template <class Value> Node<Value> * _last(Node<Value> * head) {
    Node<Value> * last = head;//->value;
    while (last->next != NULL) {
        last = last->next;
    }
    return last;
};

template <class Value> Value LinkedList<Value>::append(Value value) {
    Node<Value> * last = _head;//this is -1 (holds no value)
    
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new Node<Value>();
    last->next->value = value;
    ++_count;
    return value;
};

template <class Value> Value LinkedList<Value>::pop(Node<Value> ** head) {
    int retval = -1;
    Node<Value> * next_node = NULL;
    
    if (*head == NULL) {
        return -1;
    }
    
    next_node = (*head)->next;
    retval = (*head)->value;
//    free(*head);
    *head = next_node;
    
    return retval;
};

template <class Value> Value LinkedList<Value>::remove_by_value(int val) {
    /* TODO: fill in your code here */
    
    return -1;
};

template <class Value> void LinkedList<Value>::print(void) {
    Node<Value> * current = this->_head;
    
    while (current != NULL) {
        std::cout << current->value << std::endl;
        current = current->next;
    }
};


void LinkedListTest(void) {
    
    LinkedList<int> * list = new LinkedList<int>();
    list->append(1);
    list->append(2);
    list->append(3);
    list->append(4);

    
    list->remove_by_value( 3);
    
    list->print();
};
