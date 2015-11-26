// assigning pins
unsigned int ledPin1 = 13;
unsigned int motorPin1 = 12;
unsigned int ledPin2 = 11;
unsigned int motorPin2 = 10;
unsigned int buttonPin = 9;
/// Other variables
unsigned int turn = 0;

void setup() {
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(motorPin1,OUTPUT);
  pinMode(motorPin2,OUTPUT);
  pinMode(buttonPin,INPUT);
}

void loop() {

  if (buttonPin == HIGH){
    turn = turn + 1;
  }

  
  if (turn == 0){
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, HIGH);
  }
  
  if (turn == 1){
    digitalWrite(ledPin2, LOW);
    digitalWrite(motorPin2, LOW);
  }

  if (turn == 2){
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
  }
  if (turn == 3){
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
  }
}
