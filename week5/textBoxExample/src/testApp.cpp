#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    boxX = 150;
    boxY = 150;
    
    boxWidth = 400;
    boxHeight= 100;
    
    typing = false;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    ofBackground(0);
    ofFill();
    
    if(!typing) ofSetColor(100);
    else ofSetColor(255);
    ofRect(boxX, boxY, boxWidth, boxHeight);
    
    ofSetColor(255, 0, 0);
    ofDrawBitmapString(input, boxX+50, boxY+50);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    
    if (key == OF_KEY_DEL || key == OF_KEY_BACKSPACE){
        
        input = input.substr(0, input.length()-1);
    }
    
    else if (key == OF_KEY_RETURN){
        
        doSomething(input);
    }
    
    else {
        if(typing) input += key;
    }
}


//--------------------------------------------------------------
void testApp::doSomething(string inputString){
    
    //here is a custom function that does something like search twitter,
    //trigger an oven to turn on to cook a pizza, etc
    
    cout << "DO SOMETHING WITH: "<<inputString<<endl;
    
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
    
    if(x > boxX && x < boxX+boxWidth &&
       y > boxY && y < boxY+boxHeight){
        
        typing = !typing;
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