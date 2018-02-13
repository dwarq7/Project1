#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   2000

const uint8_t SEG_DONE[] = {
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
  SEG_C | SEG_E | SEG_G,                           // n
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
  };

TM1637Display display(CLK, DIO);

void setup() {
  // put your setup code here, to run once:

}
int i = 0;
void loop() {
  // put your main code here, to run repeatedly:
  int k;
  uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
  display.setBrightness(0x0f);

//  // All segments on
//  display.setSegments(data);
//  delay(TEST_DELAY);
//
//  // Selectively set different digits
//  data[0] = 0b01001001;
//  data[1] = display.encodeDigit(1);
//  data[2] = display.encodeDigit(2);
//  data[3] = display.encodeDigit(3);

  display.showNumberDec(i++);
  if(i > 9999) i=0;
  delay(100);

  }

