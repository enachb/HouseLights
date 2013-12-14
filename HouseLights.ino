// Uncomment this line if you have any interrupts that are changing pins - this causes the library to be a little bit more cautious
// #define FAST_SPI_INTERRUPTS_WRITE_PINS 1

// Uncomment this line to force always using software, instead of hardware, SPI (why?)
// #define FORCE_SOFTWARE_SPI 1

// Uncomment this line if you want to talk to DMX controllers
// #define FASTSPI_USE_DMX_SIMPLE 1

#include "FastSPI_LED2.h"
#include "SerialCommand.h"
#include <NilRTOS.h>

//#include "xmas.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// test code
//
//////////////////////////////////////////////////

#define NUM_LEDS 150
#define LED_PIN 13

CRGB leds[NUM_LEDS];
SerialCommand SCmd;  
boolean stop = false;

void setup() {
  nilSysBegin();

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
  SCmd.addCommand("PING",ping);       // Turns all lights on to given color

    Serial.println("Init done!");

}

NIL_WORKING_AREA(waThread1, 512);
NIL_WORKING_AREA(waThread2, 16);
NIL_WORKING_AREA(waThread3, 16);

void loop() { 

  //  LEDS.showColor(CRGB::Purple);
  //  LEDS.showColor(CRGB(255,255,255));

    SCmd.readSerial(); 

}


// Declare thread function for thread 1.
NIL_THREAD(Thread1, arg) {
  sineEffect(200,50);

// while(true){
//    knightRider(1, 100, 2, 0x440000); // Cycles, Speed, Width, RGB Color (purple);
//    knightRider(1, 100, 2, 0x004400); // Cycles, Speed, Width, RGB Color (purple);
//    knightRider(1, 100, 2, 0x000044); // Cycles, Speed, Width, RGB Color (purple);
//    knightRider(1, 100, 2, 0x444444); // Cycles, Speed, Width, RGB Color (purple);
//  }

}


// Declare thread function for thread 1.
NIL_THREAD(Thread2, arg) {

  pinMode(LED_PIN, OUTPUT);

  // Flash led every 200 ms.
  while (TRUE) {

    // Turn LED on.
    digitalWrite(LED_PIN, HIGH);

    // Sleep for 50 milliseconds.
    nilThdSleepMilliseconds(50);

    // Turn LED off.
    digitalWrite(LED_PIN, LOW);

    // Sleep for 150 milliseconds.
    nilThdSleepMilliseconds(150);
  }
}

// Declare thread function for thread 1.
NIL_THREAD(Thread3, arg) {

  while(true){
    nilThdSleepMilliseconds(500);
  }  

}

NIL_THREADS_TABLE_BEGIN()
NIL_THREADS_TABLE_ENTRY("thread1", Thread1, NULL, waThread1, sizeof(waThread1))
//NIL_THREADS_TABLE_ENTRY("thread2", Thread2, NULL, waThread2, sizeof(waThread2))
NIL_THREADS_TABLE_ENTRY("thread3", Thread3, NULL, waThread2, sizeof(waThread3))
NIL_THREADS_TABLE_END()


void ping(){
    Serial.println("Pong!");  
}























