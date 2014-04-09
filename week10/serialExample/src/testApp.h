#pragma once

#include "ofMain.h"

#define NUM_MSG_BYTES 3 //how many bytes we are expecting to receive


class testApp : public ofBaseApp{
	
	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		ofTrueTypeFont		font;

        //set this array's length to the number of msg
        //bytes we are expecting to receive
        int bytesReceived[NUM_MSG_BYTES];
        
        //we'll use this to count how many msgs have been received so far
        //(for debugging)
        long numMsgRecvd;			// when did we last read?
		
		ofSerial	mySerial;
};

