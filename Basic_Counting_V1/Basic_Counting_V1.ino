const int buttonPin=4;

int counter=0;

void setup() {
  Serial.begin(115200);

  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(buttonPin)==LOW)
  {
    counter++;

    Serial.print("Counter = ");
    Serial.println(counter);

    delay(200);
  }

}
