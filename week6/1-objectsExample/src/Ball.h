//
//  Ball.h
//  objectsExample
//
//  Created by Joseph Saavedra on 11/21/13.
//
//

#pragma once
#include "ofMain.h"

class Ball {
public:
    
    Ball(int x, int y, int w, int h);
    //void setup(int x, int y, int w, int h);
    void update();
    void draw();
    
private:
    int thisX;
    int thisY;
    int thisW;
    int thisH;
    
    int thisSpeedX;
    
    int thisSpeedY;
    
};
