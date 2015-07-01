//
//  99GreenBottles.swift
//  ShakespeareLogic
//
//  Created by Max Bilbow on 01/07/2015.
//  Copyright © 2015 Rattle Media. All rights reserved.
//

enum BottleColor: String {
    case Green = "#00FF00"
    case Blue = "#0000FF"
    case Red = "#FF0000"
}

class Bottle {
    private var color: BottleColor
    private var didAccidentallyFall: Bool = false
    
    init(color: BottleColor) {
        self.color = color
    }
    
    ///if accidentally is true, didAccidentallyFall will be set as true.
    func fall(accidentally fall: Bool){
        didAccidentallyFall = fall
    }
}

class Wall : CustomStringConvertible {
    
    ///Returns an array of all green bottles that have not accidentally fallen.
    var greenBottlesSittingOnTheWall: Array<Bottle> {
        return self.bottles.filter ({ bottle in
            return !bottle.didAccidentallyFall && bottle.color == .Green
        })
    }
    
    private var bottles = Array<Bottle>()
    
    ///Initialize wall with number of bottles. Default is 99
    init(numberOfGreenBottles: Int = 99) {
        for var i = 0; i < numberOfGreenBottles; ++i {
            self.bottles.append(Bottle(color: .Green))
        }
    }
    
    ///Should one green bottle accidentally fall?
    ///Returns false if there are no green bottles remaining on the wall
    func shouldOneGreenBottleAccidentallyFall() -> Bool {
        let bottles = self.greenBottlesSittingOnTheWall
        if bottles.count > 0 {
            let noun: String = bottles.count == 2 ? "bottle" : "bottles"
            let numberOfBottles: String = bottles.count == 1 ? "no" : (bottles.count - 1).description
            
            print("And if one green bottle should accidentally fall")
            bottles.first?.fall(accidentally: true)
            
            print("There'll be \(numberOfBottles) green \(noun) sitting on the wall")
            
            return bottles.count > 1
        } else {
            return false
        }
    }
    
    ///How many green bottles are currently on the wall
    var description: String {
        let count = self.greenBottlesSittingOnTheWall.count
        var result: String = ""
        if count == 1 {
            result = "\(count) green bottle"
        } else {
            result = "\(count) green bottles"
        }
        result = "\n\(result) sitting on the wall"
        return result + result
    }
}

