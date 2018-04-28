/*
 * Date: 28-04-2018
 * Author: Saurav Shandilya
 * 
 * Aim: Use switch button SW1 and SW2 on MSP430FR5994 launchpad and display Counter on MSP430boost-sharp96 lcd. 
 * SW1 increment the counter and SW2 decrement the counter
 * 
 * LCD reference: Example -> LCD_SharpBoosterPack_SPI
 */
#include "SPI.h"
#include "OneMsTaskTimer.h"
#include "LCD_SharpBoosterPack_SPI.h"

// Variables
LCD_SharpBoosterPack_SPI myScreen;    // create LCD object
uint8_t myOrientation = 0;
uint16_t myCount = 0;

// switch declaration
const int sw1 = PUSH1;     // Pin P5_6 SW1
const int sw2 = PUSH2;     // Pin P5_5 SW2
bool last_switch_state = LOW;

// LED declaration
const int green_led =  GREEN_LED;      // LED2 - green led
const int red_led =  RED_LED;      // LED1 - red led


int count = 0;        // counter 

// variable for reading the pushbutton status
int read_sw1_state = 0;         
int read_sw2_state = 0;

// Test red LED by blinking at interval of 1s
void blink_red()
{
   digitalWrite(red_led,HIGH);
   delay(1000);     // 1s delay
   digitalWrite(red_led,LOW);
   delay(1000);     // 1s delay   
}

// Test green LED by blinking at interval of 1s
void blink_green()
{
   digitalWrite(green_led,HIGH);
   delay(1000);     // 1s delay
   digitalWrite(green_led,LOW);
   delay(1000);     // 1s delay   
}

// test both LED
void test_led()
{
  blink_red();
  delay(1000);
  blink_green();
  delay(1000);
}

/*
 * Debounce Switch to detect press state
 * If switch preseed - wait for 50ms(Ideal time for bouncing to settle down) --  update button state after switch is released
 */
int read_switch (int buttonPin)
{
  int buttonState;             // the current reading from the input pin
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);

//  Serial.print(reading); Serial.print('\t');Serial.println(buttonState);
  
  if (digitalRead(buttonPin) == 0)  // switched interfaced in Active low 
  {
    delay(50);    // wait for bounce to settle down              
    while (digitalRead(buttonPin) == 0);    // wait till switch released
    buttonState=HIGH;   
    return buttonState;
  }
  else 
  {
    buttonState=LOW;
  }
  return buttonState;
}

/*
 * 
 */
void lcd_setup() 
{
    myScreen.begin();
    myScreen.clearBuffer();
    
    myScreen.setFont(1);    // supports two font size - 0,1
    myScreen.text(5, 5, "Hello!");      // row, 
    myScreen.setFont(0);    // supports two font size - 0,1
    myScreen.text(5, 50, "Count: ");
    myScreen.text(50, 50, String(count));
    myScreen.flush();
    
//    for (uint8_t i=0; i<20; i++) 
//      delay(100);
}

void setup() 
{
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(green_led, OUTPUT);    // set LED1 pin as output
  pinMode(red_led, OUTPUT);    // set LED2 pin as output
  digitalWrite(green_led,LOW);   // LED off at startup
  digitalWrite(red_led,LOW);   // LED off at startup
  
  // initialize the pushbutton pin as an input:
  pinMode(sw1, INPUT_PULLUP);   //
  pinMode(sw2, INPUT_PULLUP);

  lcd_setup();
}

void print_number_on_lcd(int x, int y,int number)
{
  myScreen.clearBuffer();
//  myScreen.setCharXY(x, y);
//  myScreen.print(count, DEC);
//  myScreen.text(x, y, String(count));

  myScreen.setFont(1);    // supports two font size - 0,1
  myScreen.text(5, 5, "Hello!");      // row, 
  myScreen.setFont(0);    // supports two font size - 0,1
  myScreen.text(5, 50, "Count: ");
  myScreen.text(x, y, String(count));
  myScreen.flush();
}

void loop() 
{
  //test_led();
  
  int switch1_state = read_switch(sw1);
  int switch2_state = read_switch(sw2);
  
  
  if (switch1_state == HIGH)
  {
    count++;
    print_number_on_lcd(50,50,count);
    Serial.print("count");
    Serial.print('\t');
    Serial.println(count);
//    delay(1000);
  }

  else if (switch2_state == HIGH)
  {
    count--;
    print_number_on_lcd(50,50,count);
    Serial.print("count");
    Serial.print('\t');
    Serial.println(count);
  }
}
