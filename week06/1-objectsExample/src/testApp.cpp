#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    // instantiate 1 instance of ball, at this x,y,w,h
    myball = new Ball(20, 20, 50, 50);
}

//--------------------------------------------------------------
void testApp::update(){
    
    // how we can update a single ball
    myball -> update(); // this is a pointer, so methods use " -> "
    
    // go through the entire vector and update all existing balls
    for(int i=0; i<myBalls.size(); i++){
        myBalls[i].update();    // this is a vector of balls, use dot notation
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    //draw a single ball
    myball -> draw();
    
    // go through vector and draw all exisiting balls
    for(int i=0; i<myBalls.size(); i++){
        myBalls[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    // each time the mouse is clicked, create a new ball locally
    Ball newBall = *new Ball(x, y, 30, 30);
    
    // then push this ball into our vector of myBalls
    myBalls.push_back(newBall);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
