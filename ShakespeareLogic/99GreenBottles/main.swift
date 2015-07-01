//
//  main.swift
//  99GreenBottles
//
//  Created by Max Bilbow on 01/07/2015.
//  Copyright © 2015 Rattle Media. All rights reserved.
//

import Foundation

//Initiate wall with 10 bottles
let wall = Wall(numberOfGreenBottles: 10)

repeat {
    print(wall)
} while wall.shouldOneGreenBottleAccidentallyFall()

