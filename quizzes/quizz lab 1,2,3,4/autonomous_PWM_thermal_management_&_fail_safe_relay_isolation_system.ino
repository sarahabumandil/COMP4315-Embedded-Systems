#define TEMP_SENSOR A0
#define FLAME_SENSOR 2
#define FAN_PIN 9
#define ALARM_LED 13
#define RELAY_PIN 7

int rawTemp = 0;
int tempC = 0;
int fanSpeed = 0;
bool flameState = LOW;

void setup() {
  pinMode(FLAME_SENSOR, INPUT);
  pinMode(FAN_PIN, OUTPUT);
  pinMode(ALARM_LED, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  rawTemp = analogRead(TEMP_SENSOR);
  tempC = map(rawTemp, 0, 358, -40, 125);

  flameState = digitalRead(FLAME_SENSOR);

  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.print(" C | Flame Status: ");
  Serial.println(flameState);

  if (flameState == HIGH || tempC >= 60) {
    digitalWrite(ALARM_LED, HIGH);
    digitalWrite(RELAY_PIN, HIGH);
    analogWrite(FAN_PIN, 0);
    Serial.println("DANGER! Fire Detected - Power Cut Off!");
  } else {
    digitalWrite(ALARM_LED, LOW);
    digitalWrite(RELAY_PIN, LOW);

    if (tempC > 25) {
      fanSpeed = map(tempC, 25, 59, 80, 255);
      analogWrite(FAN_PIN, fanSpeed);
    } else {
      analogWrite(FAN_PIN, 0);
    }
  }

  delay(500);
}

