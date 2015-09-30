int ledPin1 = 11;
int ledPin2 = 12;
int ledPin3 = 13;
void setup() {
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
}

void loop() {
   // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // The analog pin reads from 0 to 1023.
  // This commands maps those numbers from 4 to 0
  // So 0 becomes 4 and 1023 becomes 0
  int mappedSensorValue = map( sensorValue, 0, 1023, 4, 0);
  //Here we test the mappedsensorvalue. If it is greater then 1 we turn
  // on the LED on Pin 2 and then see if it is greater then 2.
    if (mappedSensorValue > 1) {
      digitalWrite ( ledPin3, HIGH);
      if (mappedSensorValue > 2) {
          digitalWrite ( ledPin2, HIGH);
          if (mappedSensorValue > 3) {
              digitalWrite ( ledPin1, HIGH);
          }else{//If it is not greater we start turning LEDs off.
              digitalWrite ( ledPin1, LOW);
          }
      }else{
          digitalWrite ( ledPin2, LOW);
      }
    }else{
      digitalWrite ( ledPin3, LOW);
    }
}
