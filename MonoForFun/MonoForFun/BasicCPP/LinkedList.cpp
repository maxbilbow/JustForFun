//
//  LinkedList.cpp
//  JustForFun
//
//  Created by Max Bilbow on 09/07/2015.
//  Copyright © 2015 Rattle Media. All rights reserved.
//

#include "LinkedList.hpp"
#include <iostream>

using namespace std;

template <class Value> bool LinkedList<Value>::isEmpty() {
    return this->_count == 0;
}

template <class Value> LinkedList<Value>::LinkedList() {
	this->_head = new Node();
}

template <class Value> int LinkedList<Value>::count() {
    return this->_count;
}

template <class Value> Value LinkedList<Value>::first() {
    return this->_head->value;
}

template <class Value> Value LinkedList<Value>::last() {
    return this->lastNode()->value;
};

template <class Value> typename LinkedList<Value>::Node * LinkedList<Value>::lastNode() {
    if (_head == NULL) {
        return NULL;
    }
    Node * last = _head;
    while (last->next != NULL) {
        last = last->next;
    }
    return last;
};


template <class Value> Value LinkedList<Value>::append(Value value) {
    if (_count == 0 && this->_head == NULL) {
        this->_head = new Node();
    }
    Node * last = _head; //!= NULL ? _head : new Node();//this is -1 (holds no value)
    
    if (this->isEmpty()) {
    	last->value = value;
    	
    } else {
	    while (last->next != NULL) {
	        last = last->next;
	    }
	    last->next = new Node();
	    last->next->value = value;
    }
    ++this->_count;
    
    return value;
};

template <class Value> Value LinkedList<Value>::pop(Node ** head) {
    int retval = -1;
    Node * next_node = NULL;
    
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

template <class Value> Value LinkedList<Value>::removeValueAtIndex(int index) {
    try {
        Node * node = (Node*) removeNodeAtIndex(index);
        return node->value;
    } catch (invalid_argument e) {
        cout << e.what() << endl;
    }
    return NULL;
}
template <class Value> typename LinkedList<Value>::Node * LinkedList<Value>::removeNodeAtIndex(int index) {
	if (index < 0 || index > this->_count - 1) {
		throw std::invalid_argument("index " + to_string(index) + " is out of range: " + to_string(_count));
	}
	int i = 0;
//	Node * spare = this->_head;
	Node * current = this->_head;
	Node * previous = NULL;
//	Node * next = this->head->next;
//	Node * result;
	while (i <= index) {
		if (i++ == index) {
//			result = current;
			if (previous == NULL) {
				this->_head = current->next;
			} else {
				previous->next = current->next;
			}
			this->_count--;
			return current;
		} else {
			previous = current;
			current = current->next;
		}
	}
	throw std::invalid_argument("Unknown index exception - index: " + to_string(index) + ", range: " + to_string(_count));
};


template <class Value> void LinkedList<Value>::removeAll() {
    while (_count > 0) {
        removeNodeAtIndex(0);
    }
}

template <class Value> void LinkedList<Value>::print(void) {
    if (this->isEmpty()) {
        cout << "Empty" << endl;
    } else {
        cout << _count << " items: " << _head->value;
        Node * current = _head;
        while (current->next != NULL) {
            std::cout << ", " << current->next->value;
            current = current->next;
        }
        std::cout << std::endl;
    }
};

template <class Value> typename LinkedList<Value>::Node * LinkedList<Value>::getNode(int index) {
	Node * result = _head;
	for (int i = 0; i < index; ++i) {
		result = result->next;
	}
	return result;
}


template <class Value> Value LinkedList<Value>::getValue(int index) {
    Node * result = _head;
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
    Node * array = this->asNodeArray();
    int i = _count - 1;
    
    
    _head = &array[i];
    Node * current = &array[i];// = _head;
    while ( i > 0) {
        --i;
        current->next = &array[i];
        current = current->next;
    }
    current->next = NULL;
//    cout << endl;
	return this;
}



template <class Value> typename LinkedList<Value>::Node * LinkedList<Value>::asNodeArray() {
    Node * nodes = new Node[_count];
    Node * current = _head;
    for (int i = 0; i < _count; ++i) {
        nodes[i] = *current;
        current = current->next;
    }
    
    return nodes;
}

template <class Value> Value * LinkedList<Value>::asArray() {
	int count = this->count();
	Value (* values) = new Value[count];
    Node * nodes = this->asNodeArray();
	for (int i = 0; i < count; ++i) {
        values[i] = nodes[i].value;//this->getValue(i);
	}
	
	return values;
}


template <class Value> void LinkedList<Value>::append(Value array[], size_t size) {
//    cout << size / sizeof(array[0]) << endl;
    for (int i = 0; i < size / sizeof(array[0]); ++i) {
        this->append(array[i]);
    }
};





int TestVals[] = {0,1,2,3,4,5,6};//,5,6,7};

template <class Value> LinkedList<Value> * MakeList() {
    LinkedList<int> * list = new LinkedList<int>();
    int length = sizeof(TestVals) / sizeof(Value);
    //    cout << "length = " << (int) sizeof(*vals) << " / " << (int) sizeof(Value) << " = " << length << endl;
    for (int i = 0; i < length; ++i) {
        list->append(TestVals[i]);
    }
    list->print();
    return list;
}


void TestRemoveAt(LinkedList<int> * list, int index) {
    try {
        LinkedList<int>::Node * node = (LinkedList<int>::Node*) list->removeNodeAtIndex(index);
        cout << "Removed value at " << index <<  " (value: " << node->value << ")" << endl;
        list->print();
    } catch (invalid_argument e) {
        cout << e.what() << endl;
    }

}

void TestArray(LinkedList<int> * list) {
    
    
    for (int i = 0; i < list->count(); ++i) {
        std::cout << "Value at " << i << " is " << list->getValue(i) << std::endl;
    }
    std::cout << "First Vaule is " << list->first() << std::endl;
    std::cout << " Last Vaule is " << list->last() << std::endl;
    
    int * vals = list->asArray();
    
    for (int i = 0; i < list->count(); ++i) {
        std::cout << "Array at " << i << " is " << vals[i] << std::endl;
    }
    
    list->asNodeArray()[1].value = 123;
    list->print();
    list->asArray()[1] = 123;
    list->print();
}

void TestRemove(LinkedList<int> * list) {
    TestRemoveAt(list,list->count() - 1); //last
    TestRemoveAt(list,3); //middle
    TestRemoveAt(list,0); //first
    TestRemoveAt(list,1); //last
    TestRemoveAt(list,1); //last
    TestRemoveAt(list,1); //last
    
    TestRemoveAt(list, -1);//error
    TestRemoveAt(list,3);
    
    list->removeAll();
    list->print();
    
    
    int vals[] = {0,1,2,3,4,5,6};//,5,6,7};
    list->append(vals, sizeof(TestVals));
    cout << "Removing first value: " << list->removeValueAtIndex(0) << endl;
    cout << "First: " << list->first() << ", Last: " << list->last() << endl;
    list->print();
    list->removeAll();
    list->print();

}


void LinkedListTest(void) {
   
   LinkedList<int> * list = new LinkedList<int>();
    list->append(TestVals, sizeof(TestVals));
    list->print();
//   TestArray(list);
    list->reverse();
    list->print();
    
    LinkedList<string> * sList = new LinkedList<string>();
    sList->append("Hello");
    sList->append("World");
    sList->append("Please");
    sList->append("Thanks");
    
    sList->print();
    sList->reverse();
    sList->print();
    
   
   //   list->remove_by_value(3);
//   list->print();
	
	
};


