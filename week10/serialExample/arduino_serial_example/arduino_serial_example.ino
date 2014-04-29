
//an example that sends 3 bytes of data from Arduino
//to openFrameworks everytime it receives any message

char inByte;         // incoming serial byte
int count1;           //for some fake data
int count2;     //even more fake data
 
void setup() {
  // start serial port at 115200 bps:
  Serial.begin(115200);
//  while (!Serial) {
//    ; // wait for serial port to connect. Needed for Leonardo only
//  }
  count1 = 0;
  count2 = 255;
}
 
void loop()
{
  // if we get a valid byte, read analog ins:
  if (Serial.available() > 0) { //we have received a request for messages
  
    // get incoming byte, in the future can use this for different commands
    inByte = Serial.read();
    
    //write out our bytes, in order
    Serial.write(255);
    Serial.write(count1);
    Serial.write(count2);
    
    //modify our fake data
    count1 ++;
    count2 -= 5;
    
    //reset our counters if we hit our max or min
    if(count1 > 255) count1 = 0;
    if(count2 < 10)  count2 = 255;
  }
  
  delay(50); // 30fps
}


