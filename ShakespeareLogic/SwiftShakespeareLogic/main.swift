//
//  main.swift
//  SwiftShakespeareLogic
//
//  Created by Max Bilbow on 01/07/2015.
//  Copyright © 2015 Rattle Media. All rights reserved.
//


/**
    Shakespeare Logic in Swift 2.0
    Because Swift is such a readable programming language,
    I have begun an ambitious project to rewrite all of Shakespeare’s literature in it.
*/
class ShakespeareLogic {
    enum Error: ErrorType {
        case AskedAboutBell(String)// = "Ask NOT for whom the bell tolls. It tolls for thee!"
    }
    
    ///To be or not to be.
    class func toBe(toBe: Bool) {
        if toBe || !toBe {
            print("That is the Question\n")
        }
    }
    
    ///For whom the bell tolls
    class func askAboutTheBell(question: String?) throws {
        if question != nil  {
            throw Error.AskedAboutBell("Ask NOT for whom the bell tolls. It tolls for thee!")
        } else {
            print("Very good")
        }
    }
    
}

ShakespeareLogic.toBe(true)
ShakespeareLogic.toBe(false)

do {
    try ShakespeareLogic.askAboutTheBell("For whom does the bell toll?")
} catch {
    print(error)
    try ShakespeareLogic.askAboutTheBell(nil)
}
