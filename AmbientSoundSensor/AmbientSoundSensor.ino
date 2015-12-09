/*
This is the code to make a LED blink with the music.
You have to set the threshold so it' sensible enough to make the led blink.
You connect an LED to PIN13 and the Sound Sensor to Analog Pin 0
 */
 

int threshold = 308; //Change This
int volume;

void setup() {                
  Serial.begin(9600); // For debugging
    
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
  }  
  else{
    Serial.println("LOW");
  }

}

