/*
 
 ofxOAuth example posting to twitter.
 
 - check the keyPressed() functions to see searching and posting methods
  
 */

#include "ofApp.h"


//------------------------------------------------------------------------------
void ofApp::setup() {
    
    ofSetFrameRate(30);
    ofSetLogLevel(OF_LOG_VERBOSE); //this will print out lots of extra debug info if you want it
    
    // A simplified interface when using the ofxExampleTwitterClient class.
    // Twitter-specific configuration details can be taken care of the 
    // ofxOAuth base class.
    client.setup("fn5JTboGlAl2Y5uxJiJA","9Qzj9kdXyumbgXVC36XJ7PaPMxBXfiwhyxWmlMgwsxM");
    
    // Once authenticated, check keyPressed for test calls.
}

//------------------------------------------------------------------------------
void ofApp::draw() {
    
    if(client.isAuthorized()) {
        
        ofBackground(0,255,0);
    }
    
    else {
        
        ofBackground(255,0,0);
    }
}

//------------------------------------------------------------------------------
void ofApp::keyPressed(int key) {
    
    if(client.isAuthorized()) {

        if(key == 's') {  // Get tweets.
            string s = client.exampleSearch("openFrameworks"); //put the search term in here
            cout << "search results:  "<< s <<endl;
        }
        else if(key == 'p'){
            
            string p = client.exampleUpdateStatusMethod("openFrameworks to Twitter !!"); //put the post content in here
            cout << "post result:  "<< p <<endl;
        }
        else if (key == 'i'){
            
            string i = client.exampleUpdateStatusWithPhotoMethod("Hi from OF!", "buses.jpg"); //put the post content in here
            cout << "post image result: "<< i <<endl;
        }
        
    }
    
    else {
        ofLogWarning("testApp::keyPressed") << "Not authorized yet.";
    }
}
