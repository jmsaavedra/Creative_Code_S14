//example to control LED pin, number of blinks, and blink speed
//from openFrameworks. call and response driven by Arduino.

int bytesReceived[3]; //incoming bytes

void setup() {
  pinMode(13, OUTPUT); //LED on 13
  pinMode(12, OUTPUT); //LED on 12
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() >= 3) { //we have received THREE BYTES (at least)

    for (int i=0; i< 3; i++){ //parse out all three bytes
      bytesReceived[i] = Serial.read();
    }

    int whichLED      = bytesReceived[0]; //use the first byte to determine which LED    
    int howManyBlinks = bytesReceived[1]; //use the second byte to determine numBlinks
    int delayTime     = bytesReceived[2]; //use the third to control blink speed (delay)
    
    blinkLED(whichLED, howManyBlinks, delayTime); //pass that in to the blink function
    
  }
}


void blinkLED(int LED, int numTimes, int delayTime){ //blinkLED function

  //LED should only be a 13 or a 12 for this example...
  for(int i=0; i < numTimes; i++){
    digitalWrite(LED, HIGH);
    delay(delayTime);
    digitalWrite(LED, LOW);
    delay(delayTime); 
  }
  
  delay(1000); //put 1000 in between so we can see when 1 message starts and ends
  
  //AT THE END OF THIS FUNCTION, I AM REQUESTING THE NEXT UPDATE FROM OF:
  Serial.write('N');
}


