const int incButtonPin=4;
const int decButtonPin=5;
const int resetButtonPin=18;

int counter=0;

//States for increment button
bool incCurrent=HIGH;
bool incPrevious=HIGH;

//States for decrement button
bool decCurrent=HIGH;
bool decPrevious=HIGH;

//States for reset button
bool resetCurrent=HIGH;
bool resetPrevious=HIGH;

void setup()
{
  Serial.begin(115200);

  pinMode(incButtonPin, INPUT_PULLUP);
  pinMode(decButtonPin, INPUT_PULLUP);
  pinMode(resetButtonPin, INPUT_PULLUP);
}

void loop()
{
  incCurrent=digitalRead(incButtonPin);
  decCurrent=digitalRead(decButtonPin);
  resetCurrent=digitalRead(resetButtonPin);

  if(incPrevious==HIGH && incCurrent==LOW)
  {
    counter++;

    Serial.print("Counter= ");
    Serial.println(counter);
    delay(30);
  }

  if(decPrevious==HIGH && decCurrent==LOW)
  {
    counter--;

    Serial.print("Counter= ");
    Serial.println(counter);
    delay(30);
  }

  if(resetPrevious==HIGH && resetCurrent==LOW)
  {
    counter=0;

    Serial.print("Counter= ");
    Serial.println(counter);
    delay(30);
  }
  incPrevious=incCurrent;
  decPrevious=decCurrent;
  resetPrevious=resetCurrent;
}