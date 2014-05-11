//
//  Ball.cpp
//  objectsExample
//
//  Created by Joseph Saavedra on 11/21/13.
//
//

#include "Ball.h"

Ball::Ball(int x, int y, int w, int h) {

    // this is the *constructor*
    
    thisSpeedX = 5;
    thisX = x;
    thisY = y;
    thisW = w;
    thisH = h;
}

//-------------------------------------
void Ball::update(){
    // called on every update loop of testApp
    
    thisX += thisSpeedX;
    
    if(thisX >= ofGetWidth() || thisX <= 0){
        thisSpeedX *= -1;
    }
    
    if(thisY >= ofGetWidth() || thisY <= 0){
        thisSpeedY *= -1;
    }
    
}

//-------------------------------------
void Ball::draw(){
    // called on every draw loop of testApp
    
    ofSetColor(100, 255, 200);
    ofCircle(thisX, thisY, thisW);
}

//-------------------------------------