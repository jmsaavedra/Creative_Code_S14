#pragma once

#include "ofMain.h"

#define NUM_MSG_BYTES 3

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed  (int key);
	
	ofSerial mySerial;
	
	bool bSendSerialMessage;			// a flag for sending serial
	bool isInitialized;
	
	unsigned char bytesToSend[NUM_MSG_BYTES];
	
	long numMsgSent;
		
};
