/* Motor spin test
25/11/15
author: Nick O'Brien

This program is for the sweeping motions of the top portion of the robot. 
This will be used to find things using distance and infared. 
I will soon add the Tank portion of the program but I dont have the resouces yet.
I am going to compile and edit a bunch of programs into this one 
   
 */
// Servo library and variables
#include <Servo.h>
// creates spinning rotation object
Servo rotateServo;
// Servo rotate var
const int posR = 0;

//switch variable
const int switch1 = 1; 


// Ultrasonic pins
const int trigPin1 = 50;
const int echoPin1 = 51;
//const int trigPin2 =  ;
//const int echoPin2 =  ;
//const int trigPin3 =  ;
//const int echoPin3 =  ;
//const int trigPin4 =  ;
//const int echoPin4 =  ;


void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  //rotateservo.attach( );
}

void loop()
{
  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
  long duration, inches, cm;

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  // Ultrasonic sensor1
  pinMode(trigPin1, OUTPUT);
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  // ultrasonic 2
  //pinMode(trigPin2, OUTPUT);
  //digitalWrite(trigPin2, LOW);
  //delayMicroseconds(2);
  //digitalWrite(trigPin2, HIGH);
  //delayMicroseconds(10);

  //ultrasonic 3
  //digitalWrite(trigPin3, LOW);
  //pinMode(trigPin2, OUTPUT);
  //digitalWrite(trigPin3, LOW);
  //delayMicroseconds(2);
  //digitalWrite(trigPin3, HIGH);
  //delayMicroseconds(10);
  //digitalWrite(trigPin2, LOW);

  // ultrasonic 4
  //pinMode(trigPin4, OUTPUT);
  //digitalWrite(trigPin4, LOW);
  //delayMicroseconds(2);
  //digitalWrite(trigPin4, HIGH);
  //delayMicroseconds(10);
  //digitalWrite(trigPin4, LOW);



  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
  pinMode(echoPin4, INPUT);
  duration = pulseIn(echoPin1, HIGH);
  duration = pulseIn(echoPin2, HIGH);
  duration = pulseIn(echoPin3, HIGH);
  duration = pulseIn(echoPin4, HIGH);
  
  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(100);
  

  long microsecondsToInches(long microseconds)
  {
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
  }

  long microsecondsToCentimeters(long microseconds)
   {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;



   }

  for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 90 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

}






 




