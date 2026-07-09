const int buttonPin=4;

int counter=0;

bool currentState=HIGH;
bool previousState=HIGH;

void setup() {
  Serial.begin(115200);

  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  currentState=digitalRead(buttonPin);

  if(previousState==HIGH && currentState==LOW)
  {
    counter++;

    Serial.print("Counter = ");
    Serial.println(counter);

    delay(30);
  }

  previousState=currentState;

}

