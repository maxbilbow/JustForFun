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
	this->_head = new Node();
};



template <class Value> Value LinkedList<Value>::append(Value value) {
    struct _Node * last = _head;//this is -1 (holds no value)
    
    if (this->isEmpty()) {
    	last->value = value;
    	this->_last = &last->value;
    	
    } else {
	    while (last->next != NULL) {
	        last = last->next;
	    }
	    last->next = new struct _Node();
	    last->next->value = value;
	    this->_last = &last->next->value;
    }
    ++_count;
    
    return value;
};

template <class Value> Value LinkedList<Value>::pop(struct _Node ** head) {
    int retval = -1;
    struct _Node * next_node = NULL;
    
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
    struct _Node * current = this->_head;
    
    while (current != NULL) {
        std::cout << current->value << std::endl;
        current = current->next;
    }
};

template <class Value> Value LinkedList<Value>::getValue(int index) {
	struct _Node * result = _head;
	for (int i = 0; i < index; ++i) {
		result = result->next;
	}
	return result->value;
}
   	
   	///Returns previous value or throws error if out of range
template <class Value> Value LinkedList<Value>::setValue(int index) {
	return _head->value;
}



template <class Value> LinkedList<Value> * LinkedList<Value>::reverse() {
	struct _Node * first = this->lastNode();
	
}

void LinkedListTest(void) {
    
    LinkedList<int> * list = new LinkedList<int>();
    list->append(0);
    list->append(1);
    list->append(2);
    list->append(3);

    
    list->remove_by_value( 3);
    
    list->print();
    for (int i = 0; i < list->count(); ++i) {
	    std::cout << "Value at " << i << " is " << list->getValue(i) << std::endl;
	}
	std::cout << "First Vaule is " << list->first() << std::endl;	
	std::cout << " Last Vaule is " << list->last() << std::endl;
};
