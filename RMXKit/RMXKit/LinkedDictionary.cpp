//
//  Dictionary.cpp
//  RMXKit
//
//  Created by Max Bilbow on 29/07/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//


#import <iostream>
#import "LinkedList.hpp"
#import "LinkedDictionary.hpp"
using namespace std;

class Thing {
public:
    std::string name = "Hello!";
    std::string toString() {
        return this->name;
    }
};

//template <class T:Thing>
std::ostream& operator<<(std::ostream &strm,  Thing &a) {
    return strm << "A(" << a.toString() << ")";
}

void DictionaryTest() {
    // insert code here...
    std::cout << "START>>>>\n\n";
    LinkedListTest();
    LinkedList<string> * list = new LinkedList<string>();
    
    list->append("BALLS");
    list->print();
    delete list;
    
    LinkedList<Thing> * things = new LinkedList<Thing>();
    things->append(new Thing());
    
    Dictionary<string, Thing> * dict = new Dictionary<string, Thing>();
    
    dict->setValueForKey("THING", things->getValue(0));
    dict->setValueForKey("THING2", new Thing());
    things->getValue(0)->name = "World!";
    cout << "  Printing thing 2: " << dict->getValueForKey("THING2")->toString() << endl;
    cout << "  Printing thing 1: " << dict->getValueForKey("THING")->toString() << endl;
    
    Thing * aThing = new Thing();
    aThing->name = "Monty";
    Thing* oldThing = dict->setValueForKey("THING", aThing);
    cout << "  We Repleced (and removed) thing 1: " << oldThing->name << endl;
    
    cout << "                   Printing thing 2: " << dict->getValueForKey("THING2")->toString() << endl;
    cout << "               Printing new thing 1: " << dict->getValueForKey("THING")->toString() << endl;
    
    
}