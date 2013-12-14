
void rider(){

  char *arg;  

  stop = false;

  uint8_t r= 0;
  uint8_t g= 0;
  uint8_t b= 0;

  Serial.println("Init rider!"); 

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
  } 
  else {
    r=255;
    g=255;
    b=255;
  }

  while(!stop){
    knightRider(1, 32, 2, 0xFFFFFF); // Cycles, Speed, Width, RGB Color (purple);
  }

  Serial.println("Rider done!"); 

}

void knightRider(uint16_t cycles, uint16_t speed, uint8_t width, uint32_t color) {
  uint32_t old_val[NUM_LEDS]; // up to 256 lights!
  // Larson time baby!
  for(int i = 0; i < cycles; i++){
    for (int count = 1; count<NUM_LEDS; count++) {
      leds[count] = color; 
      nilThdSleepMilliseconds(speed);
      old_val[count] = color;
      for(int x = count; x>0; x--) {
        old_val[x-1] = dimColor(old_val[x-1], width);
        leds[x-1] = old_val[x-1]; 
      }
      LEDS.show();
    }
    for (int count = NUM_LEDS-1; count>=0; count--) {
      leds[count] = color; 
      nilThdSleepMilliseconds(speed);
      old_val[count] = color;
      for(int x = count; x<=NUM_LEDS ;x++) {
        old_val[x-1] = dimColor(old_val[x-1], width);
        leds[x+1]=old_val[x+1]; 
      }
      LEDS.show();
    }
  }
}




