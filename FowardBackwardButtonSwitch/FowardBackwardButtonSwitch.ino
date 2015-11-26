// Motor forward/backward switch with button
const int Motor1pin = 13;
const int Motor2pin = 12;
const int ButtonPin = 11;
boolean MotorState = LOW;

void setup() {
  pinMode(Motor1pin, OUTPUT);
  pinMode(Motor2pin, OUTPUT);
  pinMode(ButtonPin, INPUT);
}

void loop() {
  boolean MotorState = LOW;
  if (digitalRead(ButtonPin) == MotorState){
    digitalWrite(Motor1pin, LOW);
    digitalWrite(Motor2pin, LOW);
  }
    
  
  if (digitalRead(ButtonPin) == !MotorState){
    digitalWrite(Motor1pin,!LOW);
    digitalWrite(Motor2pin,!LOW);
  }
   
  
  
}
