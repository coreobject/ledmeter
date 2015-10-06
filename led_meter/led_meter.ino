int ledPin1 = 11;
int ledPin2 = 12;
int ledPin3 = 13;

int pins[] = {13,12,11,10,9,8};
void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
   // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // The analog pin reads from 0 to 1023.
  // This commands maps those numbers from 4 to 0
  // So 0 becomes 4 and 1023 becomes 0
  int mappedSensorValue = map( sensorValue, 0, 1023, 6, 0);
  //Here we test the mappedsensorvalue. If it is greater then 1 we turn
  // on the LED on Pin 2 and then see if it is greater then 2.
  for (int i = 0; i < 6; i++) {
    if (i < mappedSensorValue) {
      digitalWrite(pins[i], HIGH);
    } else {
      digitalWrite(pins[i], LOW);
    }
  }
}
