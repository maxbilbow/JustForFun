//
//  Dictionary.hpp
//  RMXKit
//
//  Created by Max Bilbow on 29/07/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#ifndef Dictionary_cpp
#define Dictionary_cpp

//#include <stdio.h>
//#import <list>
//#import "LinkedList.hpp"

#endif /* Dictionary_cpp */

void DictionaryTest();

template <typename Key, typename Value>
class KeyValuePair {
public:
    Key key;
    Value * value;
};


//typedef struct _KeyValuePair KeValuePair;

template <typename Key, typename Value> class Dictionary : public LinkedList<KeyValuePair<Key,Value> > {
    
public:
    typedef KeyValuePair<Key, Value> Pair;
    typedef LinkedList<KeyValuePair<Key,Value> > Node;
    Dictionary() {
//        LinkedList<KeyValuePair<Key, Value> >::LinkedList();
        
    }
    ~Dictionary() {
        this->removeAll();//TODO: More here
    }
    
    Pair * getKeyValuePair(Value * value);
    Pair * getKeyValuePair(Key key);
    Value * getValueForKey(Key key);
//    Key getKeyForValue(Value * value);
    
    
    Value * setValueForKey(Key key, Value * value);
    Value setValueForKey(Key key, Value  value);
};


template <typename Key, typename Value>
inline typename Dictionary<Key, Value>::Pair  * Dictionary<Key, Value>::getKeyValuePair(Key key) {
    struct LinkedList<Pair>::_Node * node = this->firstNode();
    while (node != nullptr && node->value != nullptr) {
        if (node->value->key == key)
            return node->value;
        else {
            node = node->next;
        }
    }
    return nullptr;
}


//template <typename Key, typename Value>
//inline KeyValuePair<Key, Value> * Dictionary<Key, Value>::getKeyValuePair(Value * value) {
//    Node * node = this->firstNode();
//    while (node != nullptr) {
//        if (node->value->value == value) //matches the pointers
//            return node;
//        else {
//            node = node->next;
//        }
//    }
//    return nullptr;
//}

///Looks OK
template <typename Key, typename Value>
inline Value * Dictionary<Key, Value>::getValueForKey(Key key) {
    KeyValuePair<Key, Value> * node = this->getKeyValuePair(key);
    if (node != nullptr)
        return node->value;
    else
//        throw std::invalid_argument("Value does not exist for key");
    return nullptr;
}


///This looks OK.
template <typename Key, typename Value>
inline Value * Dictionary<Key, Value>::setValueForKey(Key key, Value * value) {
    KeyValuePair<Key, Value> * pair = this->getKeyValuePair(key);
    if (pair != nullptr) {
        Value * old = pair->value;
        pair->value = value;
        return old;
    } else {
        KeyValuePair<Key,Value> * newPair = new KeyValuePair<Key,Value>();
        newPair->key = key;
        newPair->value = value;
        this->append(newPair);
        return nullptr;
    }
    
}

template <typename Key, typename Value>
inline Value Dictionary<Key, Value>::setValueForKey(Key key, Value value) {
    return *this->setValueForKey(key, &value);
}



