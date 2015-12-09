int ledPin = 13;
int val;

void setup() {
pinMode(ledPin, OUTPUT);
Serial.begin(9600);
}

void loop() {
// send data to another XBee module
Serial.print('A');
delay(1000);

// receive data from another XBee module
val = Serial.read();
if (-1 != val) {
  if ('A' == val) {
    Serial.println("received")  
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
}
}
}
