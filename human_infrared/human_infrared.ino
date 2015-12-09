const int IRPin = 40;    
const int ledPin =  13;      

void setup() {
   Serial.begin(9600);
   pinMode(ledPin, OUTPUT);      
   pinMode(IRPin, INPUT);     
 }
 void loop()
 {
    if (digitalRead(IRPin) == HIGH) {     
      digitalWrite(IRPin, HIGH);  
      Serial.println("Detected");
    } 
    else {
      digitalWrite(ledPin, LOW); 
      Serial.println("Undetected");
      delay(1000);
    }
    
 }
