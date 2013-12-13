
void allOn(){

  char *arg;  

  uint8_t r= 0;
  uint8_t g= 0;
  uint8_t b= 0;

  arg = SCmd.next();    // Get the next argument from the SerialCommand object buffer
  if (arg != NULL){      // We have args!
    r = atoi(arg);   
    arg = SCmd.next();    // Get the next argument from the SerialCommand object buffer
    if (arg != NULL){      // We have args!
      g = atoi(arg);   
    } 
    arg = SCmd.next();    // Get the next argument from the SerialCommand object buffer
    if (arg != NULL){      // We have args!
      b = atoi(arg);   
    }
    LEDS.showColor(CRGB(r,b,g));
  } 

  else {
    // we have no arg. assume white.
    Serial.println("Assuming white color"); 
    LEDS.showColor(CRGB(255,255,255));    
  }

  Serial.println("all LEDs on "); 

}

void allOff(){
  LEDS.showColor(CRGB(0,0,0));
  Serial.println("all LEDs off "); 
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

