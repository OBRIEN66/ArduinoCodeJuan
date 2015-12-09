// Ambient Light sensor



void setup() {
  Serial.begin(9600);

}

void loop() {
  int light = analogRead(A6);
  Serial.println(light);
  delay(100);
}
