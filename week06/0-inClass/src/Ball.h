//
//  Ball.h
//  emptyExample
//
//  Created by Joseph Saavedra on 3/4/14.
//
//

#pragma once

#include "ofMain.h"

class Ball {
    
public:
    
    //constructor
    Ball(int x, int y, int _size);

    //methods
    void update();
    void draw();
    void addForce(float x, float y);
    
    //variables
    int size;
    float forceX;
    float forceY;
    
    ofPoint pos;
    
    ofColor color;
    
private:
    
};


