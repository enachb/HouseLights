
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

