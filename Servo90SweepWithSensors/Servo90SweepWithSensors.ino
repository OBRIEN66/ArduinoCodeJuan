/*
This program spins a servo back and forth until something is detected, then it waits 5
seconds until it continues spinning
  
 
 */



#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

int caseSwitch = 1; // I need a var for the case

// sensor variables
int IRpin = 49;
int trigPin = 52;
int echoPin = 53;

void setup() {
  myservo.attach(45);  // attaches the servo on pin 45 to the servo object
  Serial.begin(9600);     
  pinMode(IRPin, INPUT);   
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
  if (digitalRead(IRPin) == HIGH){     
      digitalWrite(IRPin, HIGH);  
      
    } 
  else if (digitalRead(IRPin) == LOW) {
    digitalWrite(IRPin, LOW); 
  }
      
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
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(100);
}

  long microsecondsToInches(long microseconds)
  {
    // According to Parallax's datasheet for the PING))), there are
    // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
    // second).  This gives the distance travelled by the ping, outbound
    // and return, so we divide by 2 to get the distance of the obstacle.
    // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
    MsReturnIn = microseconds / 74 / 2;
    return MsReturnIn
  }
  
  long microsecondsToCentimeters(long microseconds)
  {
    // The speed of sound is 340 m/s or 29 microseconds per centimeter.
    // The ping travels out and back, so to find the distance of the
    // object we take half of the distance travelled.
    MsReturnCm = microseconds / 29 / 2;
    return MsReturnCm
  }

  if (IRpin == HIGH){
    caseSwitch = 1;
  }

  if (MsReturnCm <= 7){
    caseSwitch = 2;
  else{
    caseSwitch =3;
  }

  switch(caseSwitch){
    case IrDetection:
      myServo.write(pos);
      delay(5000);
      break;

    case UltrasonicDetection:
      myServo.write(pos);
      delay(5000);
      break:
    default:
      break;
  }
  }
}




