

float ct=0, t=0, rate;
int k,j, r;

void sineEffect(uint8_t brightness, uint8_t sleep){


  while(true){
    rate = 30+27*sin(t/10);
    for (int i=0; i < NUM_LEDS; i++) {

      r = 127+127*sin(t+ i / rate * 3.14159);

      leds[i].g=r;
      leds[i].b=0;
      leds[i].r=255-r;

    } 

    t += 0.05;
    //  j+=0.1;
    FastSPI_LED.setBrightness(brightness);
    FastSPI_LED.show();
    nilThdSleepMilliseconds(sleep);
  }
}


void xmas(){

  char *arg;
  arg = SCmd.next();    // Get the next argument from the SerialCommand object buffer

  stop = false;

  while(!stop){
    for(int i=0;i<NUM_LEDS && !stop;i++){
      leds[i] = CRGB(random(128),random(128),random(128));
      SCmd.readSerial();
    }
    LEDS.show();
  }
  Serial.println("XMas done!"); 

}


