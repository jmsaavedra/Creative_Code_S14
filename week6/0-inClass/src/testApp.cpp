#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
}

//--------------------------------------------------------------
void testApp::update(){

    for (int i=0; i<myBalls.size(); i++){
        myBalls[i].update(); //update all balls
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);
    
    for (int i=0; i<myBalls.size(); i++){
        myBalls[i].draw(); //update all balls
    }
    
    ofSetColor(255);
    ofDrawBitmapString("number of Balls: "+ ofToString(myBalls.size()), 30, 30);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

    for (int i=0; i<5000; i++){
        //Ball tempBall = * new Ball( ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 5 );
        Ball tempBall = * new Ball( x, y, 2 );
        myBalls.push_back(tempBall);
    }
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