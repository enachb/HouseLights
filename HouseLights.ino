// Uncomment this line if you have any interrupts that are changing pins - this causes the library to be a little bit more cautious
// #define FAST_SPI_INTERRUPTS_WRITE_PINS 1

// Uncomment this line to force always using software, instead of hardware, SPI (why?)
// #define FORCE_SOFTWARE_SPI 1

// Uncomment this line if you want to talk to DMX controllers
// #define FASTSPI_USE_DMX_SIMPLE 1

#include "FastSPI_LED2.h"
#include "SerialCommand.h"
//#include "xmas.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// test code
//
//////////////////////////////////////////////////

#define NUM_LEDS 150

CRGB leds[NUM_LEDS];
SerialCommand SCmd;  
boolean stop = false;

void setup() {
  // sanity check delay - allows reprogramming if accidently blowing power w/leds
  //  delay(2000);
  FastLED.addLeds<TM1809, 7, BRG>(leds, NUM_LEDS);
  LEDS.setBrightness(255);

  Serial.begin(9600); 

  // Setup callbacks for SerialCommand commands 
  SCmd.addCommand("ALLON",allOn);       // Turns all lights on to given color
  SCmd.addCommand("ALLOFF",allOff);       // Turns all lights on to given color
  SCmd.addCommand("XMAS",xmas);       // Turns all lights on to given color
  SCmd.addCommand("STOP",stopIt);       // Turns all lights on to given color
  SCmd.addCommand("RIDER",rider);       // Turns all lights on to given color

    Serial.println("Init done!"); 

}

void loop() { 
  //  LEDS.showColor(CRGB::Purple);
  //  LEDS.showColor(CRGB(255,255,255));

  SCmd.readSerial(); 

  sineEffect(50,100);
//  fuse();

}

void stopIt(){
  stop = true;
  Serial.println("Stopping..."); 
}

void flicker(uint8_t number){

  CRGB ledsPrev[NUM_LEDS];
  memcpy(leds,ledsPrev,sizeof(leds) * sizeof(CRGB));

  const uint8_t MAX = 50;

  leds[1].fadeLightBy( 100 );
  LEDS.show();
  //  memcpy(ledsPrev,leds,sizeof(leds) * sizeof(CRGB));

}

uint32_t dimColor(uint32_t color, uint8_t width) {
  return (((color&0xFF0000)/width)&0xFF0000) + (((color&0x00FF00)/width)&0x00FF00) + (((color&0x0000FF)/width)&0x0000FF);
}




























