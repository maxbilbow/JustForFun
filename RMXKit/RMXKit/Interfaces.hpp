//
//  Interfaces.h
//  RMXKit
//
//  Created by Max Bilbow on 28/07/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#ifndef Interfaces_h
#define Interfaces_h


#endif /* Interfaces_h */
//#import <iostream>

typedef void * Object;
typedef std::string AnEvent;


class EventListener {
public:
    EventListener();
//    virtual void OnEvent(String theEvent, Object args){}
    virtual void OnEventDidStart(AnEvent theEvent, Object args) {
        std::cout << "   Event Started: " << theEvent << ", with args: " << args << std::endl;
    }
    
    virtual void OnEventDidEnd(AnEvent theEvent, Object args) {
        std::cout << "   Event Started: " << theEvent << ", with args: " << args << std::endl;
    }
    virtual void SendMessage(AnEvent message){
        std::cout << "Message Received: " << message << std::endl;
    }
} ;

//typedef _EventListener * EventListener;




