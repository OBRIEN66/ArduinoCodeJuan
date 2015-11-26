// Pin assignments
// Inputs
const int xAxisPin = 0; //Analog 
const int yAxisPin = 1; //Analog
// Outputs
const int MotorPin = 12; // Digital
const int LEDpins = 6; //Digital
// Boolean Variables
boolean MotorState = LOW;
boolean LEDstate = LOW;


void setup() {
  // INPUTS
  digitalWrite(yAxisPin, INPUT);
  // OUTPUTS
  digitalWrite(MotorPin, OUTPUT);
  digitalWrite(MotorPin, OUTPUT);
}

void loop() {
  //
  if digitalRead(yAxisPin) > 0 {
    digitalWrite(MotorPin, HIGH)
  
  }

}
