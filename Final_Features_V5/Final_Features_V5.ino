#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//LED Pin definitions
#define GREEN_LED 23
#define RED_LED 19
#define YELLOW_LED 15

//Button pin definitions
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

//LED Functions
void greenLight()
{
  digitalWrite(GREEN_LED, HIGH);
  delay(150);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
}

void redLight()
{
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, HIGH);
  delay(150);
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
}

void yellowLight()
{
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, HIGH);
  delay(150);
  digitalWrite(YELLOW_LED, LOW);
}

//Button functions------------------------------------------
void increment()
{
  greenLight();
  counter++;
  updateDisplay();
  delay(30);
}

void decrement()
{
  redLight();
  counter--;

  updateDisplay();
  delay(30);
}

void reset()
{
  yellowLight();
  counter=0;

  updateDisplay();
  delay(30);
}
//------------------------------------------------------------
void splashScreen()
{
    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(20,10);
    display.println("DIGITAL");

    display.setCursor(20,35);
    display.println("COUNTER");

    display.setTextSize(1);
    display.setCursor(1,56);
    display.println("By Aditya Srivastava");

    display.display();

    delay(2000);
}
void showResetScreen()
{
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, HIGH);

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(20,25);
  display.println("RESET");
  display.display();
  delay(1000);
  digitalWrite(YELLOW_LED, LOW);
}


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

//--------------------------------Setup---------------------------------------
void setup()
{
  //OLED Initialisation
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    while(true);
  }

  splashScreen();

  updateDisplay();

  pinMode(incButtonPin, INPUT_PULLUP);
  pinMode(decButtonPin, INPUT_PULLUP);
  pinMode(resetButtonPin, INPUT_PULLUP);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
}
//-------------------------------------Loop------------------------------
void loop()
{
  incCurrent=digitalRead(incButtonPin);
  decCurrent=digitalRead(decButtonPin);
  resetCurrent=digitalRead(resetButtonPin);

  if(incPrevious==HIGH && incCurrent==LOW)
  {
    increment();
  }

  if(decPrevious==HIGH && decCurrent==LOW)
  {
    decrement();
  }

  if(resetPrevious==HIGH && resetCurrent==LOW)
  {
    showResetScreen();
    reset();
  }
  incPrevious=incCurrent;
  decPrevious=decCurrent;
  resetPrevious=resetCurrent;
}

