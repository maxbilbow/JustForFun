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
protected:
typedef struct _Node {
    Value value;
    _Node * next;
} Node;
private:
    int _count;
    Node * _head;// = new Node<Value>();
    Value * _last;

public:
    int count() {
        return _count;
    };
    
    Node * lastNode() {
    	if (_head == NULL) {
    		return NULL;
    	}
    	Node * last = _head;
    	while (last->next != NULL) {
    		last = last->next;
    	}
    	return last;
	};
    
    LinkedList();
    
    Value first() {
        return this->_head->value;
    };
    
    Value last() {
        return *this->_last;
    };
    
    bool isEmpty() {
    	return this->_count == 0;
    };
    
    ///TODO
    Node * removeNode(Node * node);
   
    ///TODO 
    Node * removeNodeAtIndex(int index);
    
    ///TODO 
    Node * InsertValueAtIndex(int index);
    
    Value append(Value value);
     
//    static void print_list(Node<Value> * head);
    void print(void);
    
//    static int pop(Node<Value> ** head);
    Value pop(Node ** head);
   
//    static int remove_by_value(Node<Value> ** head, int val);
    Value remove_by_value(int val);
    
   	Value getValue(int index);
   	
   	///Returns previous value or throws error if out of range
   	Value setValue(int index);
  	
  	LinkedList<Value> * reverse();
    
//    template <class Value>
};


void LinkedListTest(void);

