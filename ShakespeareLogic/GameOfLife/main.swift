//
//  main.swift
//  GameOfLife
//
//  Created by Max Bilbow on 02/07/2015.
//  Copyright © 2015 Rattle Media. All rights reserved.
//

import Foundation

// An implementation of Conway's Game of Life.
//package main

//import (
//"bytes"
//"fmt"
//"math/rand"
//"time"
//)

func GameOfLife() {
    let life = Life.new(width: 40, height: 15)
    for var i = 0; i < 300; i++ {
        life.step()
        print(life)//"\x0c", l) // Clear screen and print field.
        //time.Sleep(time.Second / 30)
    }
}

SDLLinkRun()





