#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	//serial start
	ofSetVerticalSync(true);
	
	ofBackground(255);	
	//ofSetLogLevel(OF_LOG_VERBOSE);
	
	mySerial.listDevices();
	vector <ofSerialDeviceInfo> deviceList = mySerial.getDeviceList();
	
	// this should be set to whatever com port your serial device is connected to.
	// (ie, COM4 on a pc, /dev/tty.... on linux, /dev/tty... on a mac)
	// arduino users check in arduino app....
	int baud = 9600;
	mySerial.setup(0, baud); //open the first device

    bytesToSend[0] = 12;
	bytesToSend[1] = 1;
	bytesToSend[2] = 155;

	mySerial.flush();
    isInitialized = false;
}

//--------------------------------------------------------------
void testApp::update(){
	
    if(mySerial.available() >0){ //something came in over serial port
        
        if(!isInitialized) isInitialized = true; //we heard from Arduino, we're initialized.
        
        char incoming = mySerial.readByte();
        cout << "message received: "<< incoming << endl;
        
        mySerial.flush(); //flush whatever messages were received, clean slate next frame
        
		mySerial.writeBytes(bytesToSend, NUM_MSG_BYTES); //send out current bytes to send
        numMsgSent++; //for our own count
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(0);
    ofSetColor(255);
	
    if(!isInitialized)
        ofDrawBitmapString("PRESS 'S' TO SEND KICKOFF BYTE", 50, 200);
    else {
        //draw out current bytesToSend values:
        for(int i=0; i<NUM_MSG_BYTES; i++){
            string whichByte = "bytesToSend["+ofToString(i)+"] = ";
            ofDrawBitmapString(whichByte + ofToString((int)bytesToSend[i]), 50, 30+30*i);
            if     (i == 0) ofDrawBitmapString("(LED pin)", 225, 30+30*i);
            else if(i == 1) ofDrawBitmapString("(number of blinks)", 225, 30+30*i);
            else if(i == 2) ofDrawBitmapString("(blink speed)", 225, 30+30*i);
        }
        
        //just for debug
        ofDrawBitmapString("num messages sent total: "+ ofToString(numMsgSent), 50, 150);
        ofDrawBitmapString("press 'a','b','c','A','B','C', LEFT, or RIGHT arrows to update values", 50, 200);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    switch(key){
        case 's':
            cout << "SENDING KICK-OFF MESSAGE" << endl;
            mySerial.writeBytes(bytesToSend, NUM_MSG_BYTES);
            break;
        case 'a':
            bytesToSend[0] = 13; //LED 13
            bytesToSend[1] = 3;  //blink 3 times
            break;
        case 'b':
            bytesToSend[0] = 13;
            bytesToSend[1] = 5;
            break;
        case 'c':
            bytesToSend[0] = 13;
            bytesToSend[1] = 7;
            break;
        case 'A':
            bytesToSend[0] = 12;
            bytesToSend[1] = 3;
            break;
        case 'B':
            bytesToSend[0] = 12;
            bytesToSend[1] = 5;
            break;
        case 'C':
            bytesToSend[0] = 12;
            bytesToSend[1] = 7;
            break;
        case OF_KEY_LEFT:
            bytesToSend[2] -= 10;
            if (bytesToSend[2] < 15) bytesToSend[2] = 15;
            break;
        case OF_KEY_RIGHT:
            bytesToSend[2] += 10;
            if (bytesToSend[2] > 240) bytesToSend[2] = 240;
            break;
        default:
            cout << "UNRECOGNIZED BUTTON PRESS"<<endl;
    }
    cout << "UPDATED bytesToSend values:  ";
    cout << "LED: "<< ofToString((int)bytesToSend[0]) << " - BLINK TIMES: " << ofToString((int)bytesToSend[1]) << endl;
}

