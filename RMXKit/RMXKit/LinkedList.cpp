//
//  LinkedList.cpp
//  JustForFun
//
//  Created by Max Bilbow on 09/07/2015.
//  Copyright © 2015 Rattle Media. All rights reserved.
//
//#include "Interfaces.hpp"

#include <iostream>
#include "LinkedList.hpp"

using namespace std;

//void printList(LinkedList<int> * list);



//template <typename Value> void LinkedList<Value>::print(void) {
//    try {
//        if (this->isEmpty()) {
//            std::cout << "Empty" << std::endl;
//        } else {
//            try {
//                std::cout << this->_count << " items: " << this->_head;
//            } catch (std::exception e) {
//                std::cout << ", " << e.what();
//            }
//            LinkedList<Value>::Node * current = this->firstNode();
//            while (current->next != NULL) {
//                try {
//                    std::cout << ", " << current->next->value;
//                    current = current->next;
//                } catch (std::exception e) {
//                    std::cout << ", " << e.what();
//                }
//            }
//            std::cout << std::endl;
//        }
//    } catch (std::exception e) {
//        
//        std::cout << e.what() << std::endl;;
//    }
//    
//};



int TestVals[] = {0,1,2,3,4,5,6};//,5,6,7};

template <typename Value> LinkedList<Value> * MakeList() {
    LinkedList<int> * list = new LinkedList<int>();
    int length = sizeof(TestVals) / sizeof(Value);

    for (int i = 0; i < length; ++i) {
        list->append(&TestVals[i]);
    }
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
        std::cout << "Value at " << i << " is " << *list->getValue(i) << std::endl;
    }
    std::cout << "First Vaule is " << *list->first() << std::endl;
    std::cout << " Last Vaule is " << *list->last() << std::endl;
    
    int * vals = list->asArray();
    
    for (int i = 0; i < list->count(); ++i) {
        std::cout << "Array at " << i << " is " << vals[i] << std::endl;
    }
    
    list->asNodeArray()[1].value = new int(123);
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
   TestArray(list);
    list->reverse();
    list->print();
    
    LinkedList<string> * sList = new LinkedList<string>();
    sList->append(new string("Hello"));
    sList->append("World");
    sList->append("Please");
    sList->append("Thanks");
    sList->print();
//    printList(list);
    sList->reverse();
    sList->print();
    cout << "Removing: " << sList->removeValue("Thanks") << endl;
    sList->print();
    delete list;
    delete sList;
    
   //   list->remove_by_value(3);
//   list->print();
	
	
};

