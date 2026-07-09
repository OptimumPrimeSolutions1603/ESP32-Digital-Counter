#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

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

void updateDisplay()
{
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(10, 10);
  display.println("Counter");

  display.setTextSize(3);
  display.setCursor(25, 35);
  display.println(counter);

  display.display();
}

void setup()
{
  //OLED Initialisation
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    while(true);
  }

  updateDisplay();

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
    updateDisplay();
    delay(30);
  }

  if(decPrevious==HIGH && decCurrent==LOW)
  {
    counter--;

    updateDisplay();
    delay(30);
  }

  if(resetPrevious==HIGH && resetCurrent==LOW)
  {
    counter=0;

    updateDisplay();
    delay(30);
  }
  incPrevious=incCurrent;
  decPrevious=decCurrent;
  resetPrevious=resetCurrent;
}
