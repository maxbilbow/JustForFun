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



//template <class Value> struct Node {
//public:
//    Value value;
//    Node * next;
//};

template <class Value> class LinkedList {
public:
typedef struct _Node {
public:
    Value value;
    _Node * next;
} Node;
private:
    int _count;
    Node * _head;// = new Node<Value>();
//    Value * _last;

public:
    LinkedList();
    
    int count();
    
    Node * lastNode();
    
    Value first();
    
    Node * firstNode();
    
    Value last();
    
    bool isEmpty();
    
//    ///Removes and returns the mathcing node
//    Node * removeNode(Node * node);
   
    ///removes and returns value at index
    Value removeValueAtIndex(int index);

    ///Removes and returns the node at index
    Node * removeNodeAtIndex(int index);

//     Node * insertValueAtIndex(int index);
    
    ///Necessary for reversing a list
    Node * asNodeArray();
    
    ///Copy of list as an array
    Value * asArray();
    
    ///Removes all elements, beginnig with the first.
    void removeAll();
    
    ///Appends and returns appended value
    Value append(Value value);
    
    ///appends an array of given size (sizeof(array))
    void append(Value array[], size_t size);
//    static void print_list(Node<Value> * head);
    void print(void);
//    static int pop(Node<Value> ** head);
    Value pop(Node ** head);
   
//    static int remove_by_value(Node<Value> ** head, int val);
    Value remove_by_value(int val);
    
   	Value getValue(int index);
    
    Node * getNode(int index);
   	
    bool contains(Value value);
    
   	///Returns previous value or throws error if out of range
   	Value setValue(int index);
  	
  	LinkedList<Value> * reverse();
    
//    template <class Value>
};


void LinkedListTest(void);

