// asigning pin numbers
const int switchPin = 7;
const int xAxisPin = 0;
const int yAxisPin = 1;


void setup() {
  // sets the switch to input
  pinMode(switchPin, INPUT);  
  // powers the switch
  digitalWrite(switchPin, HIGH);
  // The bit rate
  Serial.begin(9600);
}

void loop() {
  // Says switch and if its on/off
  Serial.print("Switch:     ");
  Serial.print(digitalRead(switchPin));
  Serial.print("\n");
  // Says X axis and shows the x coordinate
  Serial.print("X axis:     ");
  Serial.print(analogRead(xAxisPin));
  Serial.print("\n");
  // Says Y axis and shows the y coordinate
  Serial.print("Y axis:     ");
  Serial.print(analogRead(yAxisPin));
  // Makes white space
  Serial.print("\n\n");
  //Delays for 1/2 sec
  delay(500);
  
}
