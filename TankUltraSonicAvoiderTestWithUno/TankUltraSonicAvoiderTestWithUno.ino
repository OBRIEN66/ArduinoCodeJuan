


// Sound sensor variables
int threshold = 308; //Change This
int volume;

//Motor variables
int portMotorPin = 11;
int starboardMotorPin = 12;

// UltraSonic Variables
int trigPin = 9;
int echoPin = 8;

void setup() {                
  Serial.begin(9600); // For debugging
  pinMode(portMotorPin, OUTPUT);
  pinMode(starboardMotorPin, OUTPUT);  
}

void loop() {
  
  volume = analogRead(A10); // Reads the value from the Analog PIN A10
  /*
    //Debug mode
    Serial.println(volume);
    delay(100);
  */
  
  if(volume>=threshold){
    Serial.println("HIGH");
    // establish variables for duration of the ping, 
    // and the distance result in inches and centimeters:
    long duration, inches, cm;
  
    // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
    // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    pinMode(trigPin, OUTPUT);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
  
    // Read the signal from the sensor: a HIGH pulse whose
    // duration is the time (in microseconds) from the sending
    // of the ping to the reception of its echo off of an object.
    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH);
  
    // convert the time into a distance
    
    

    /*
    //Just in case I want to check
    Serial.print(inches);
    Serial.print("in, ");
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
    
    delay(100);
    */   
  /*
    long microsecondsToInches(long microseconds)
    {
      // According to Parallax's datasheet for the PING))), there are
      // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
      // second).  This gives the distance travelled by the ping, outbound
      // and return, so we divide by 2 to get the distance of the obstacle.
      // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
      int InDistance = microseconds / 74 / 2;
      return InDistance
    }
    */
    
    long microsecondsToCentimeters(long microseconds)
    {
      // The speed of sound is 340 m/s or 29 microseconds per centimeter.
      // The ping travels out and back, so to find the distance of the
      // object we take half of the distance travelled.
      int CmDistance = microseconds / 29 / 2;
      return CmDistance / 29 / 2;
    }
    
    digitalWrite(portMotorPin, HIGH);
    digitalWrite(starboardMotorPin, HIGH);
    
    if (CmDistance <= 7){
      digitalWrite(portMotorPin, LOW);
      digitalWrite(starboardMotorPin, HIGH);
      delay(1000); 
    }
    
  }  
  else{
    Serial.println("LOW");
  }
  
}

