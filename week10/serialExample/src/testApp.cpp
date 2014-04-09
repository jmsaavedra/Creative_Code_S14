#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	ofBackground(255);	
	
    ofSetLogLevel(OF_LOG_VERBOSE);
	
	font.loadFont("DIN.otf", 18);
	
	mySerial.listDevices();
	vector <ofSerialDeviceInfo> deviceList = mySerial.getDeviceList();
	
	// this should be set to whatever com port your serial device is connected to.
	// (ie, COM4 on a pc, /dev/tty.... on linux, /dev/tty... on a mac)
	// arduino users check in arduino app....
	int baud = 115200;
	mySerial.setup(0, baud); //open the first device
    
    numMsgRecvd = 0;

}

//--------------------------------------------------------------
void testApp::update(){
	
    if(mySerial.available() >= NUM_MSG_BYTES){
        
        //go through all received bytes
        for(int i=0; i<NUM_MSG_BYTES; i++){
            
            //read this byte
            int val = mySerial.readByte();
            
            //store it in the array at index i
            bytesReceived[i] = val;
        }
        
        numMsgRecvd++;
        
        cout << "bytesReceived[0] = " << bytesReceived[0] << endl;
        cout << "bytesReceived[1] = " << bytesReceived[1] << endl;
        cout << "bytesReceived[2] = " << bytesReceived[2] << endl;
        cout << "------------------------"<<endl;
        
        mySerial.flush(); //give a little flush before we start anything
        
        mySerial.writeByte('A'); //request another message!
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(0);
    ofSetColor(255);
    
    //draw out our received data
    for(int i=0; i<NUM_MSG_BYTES; i++){
        string whichByte = "bytesReceived["+ofToString(i)+"] = ";
        font.drawString(whichByte+ofToString(bytesReceived[i]), 20, 30+30*i);
    }
    
    //just for debug
    font.drawString("num messages received total: "+ ofToString(numMsgRecvd), 20, 150);
    
    //if we haven't received anything yet
    if(numMsgRecvd<1)
        font.drawString("PRESS ANY KEY TO SEND KICK OFF BYTE", 20, 180);
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    mySerial.writeByte('A');
    cout << "sent kickoff byte!" << endl;
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

