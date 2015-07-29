//
//  RMXNotificationCenter.hpp
//  RMXKit
//
//  Created by Max Bilbow on 28/07/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#ifndef RMXNotificationCenter_cpp
#define RMXNotificationCenter_cpp

//#include <stdio.h>
//#import <list>
//#import <vector>



#endif /* RMXNotificationCenter_cpp */

#define EVENT_STATUS_IDLE       0ui
#define EVENT_STATUS_ACTIVE     1ui
#define EVENT_STATUS_COMPLETE   2ui
#define EVENT_STATUS_FAILURE    3ui

//const String E_IDLE = "Idle";


typedef std::string EventType;
typedef unsigned short EventStatus;
//#import "LinkedList.hpp"
//#import "LinkedDictionary.hpp"
class NotificationCenter {

private:
    LinkedList<EventListener> * listeners;
    
    Dictionary<EventType, EventStatus> * events;

    NotificationCenter();

public:
    
    static NotificationCenter * current();
    
    static bool hasListener(EventListener * listener);
    
    static void reset(EventType theEvent);
    
    static void addListener(EventListener * listener);
    
    static EventListener * removeListener(EventListener * listener);
    
    static EventStatus statusOf(EventType theEvent);
    
    static bool isIdle(EventType theEvent);
    
    static bool isActive(EventType theEvent) ;
    
    static void eventDidOccur(EventType e) {
        eventDidOccur (e, nullptr);
    }
    
    static void eventDidOccur(EventType theEvent, Object o);
    
    static bool isComplete(EventType theEvent);
    
    static bool didFail(EventType theEvent);
    
    static void eventWillStart(EventType theEvent) {
        eventWillStart (theEvent, nullptr);
    }
    
    static void eventWillStart(EventType theEvent, Object o);

    
    static void eventDidEnd(EventType theEvent) {
        eventDidEnd (theEvent, nullptr);
    }
    
    static void eventDidEnd(EventType theEvent, Object o);
    
    static void notifyListeners(std::string message);
    
    static void Test();
    
};