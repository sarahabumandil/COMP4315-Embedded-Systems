const int switchOnPin = 2;  
const int switchOffPin = 3; 
const int ledPin = 13;    
void setup() {
  pinMode(switchOnPin, INPUT_PULLUP);
  pinMode(switchOffPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);     
}
void loop() {
  if (digitalRead(switchOnPin) == LOW) {
    digitalWrite(ledPin, HIGH); 
  }
  if (digitalRead(switchOffPin) == LOW) {
    digitalWrite(ledPin, LOW);  
  }
}

