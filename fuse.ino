
void fuse(){
  for(int i = 0 ; i < NUM_LEDS - 7;i++ ) { //- (X) x=number of leds in chase
    memset(leds, 0, NUM_LEDS * 3);
    int l = i;
    leds[l].r = 13; 
    leds[l].g =2; 
    leds[l].b = 0; 
    l++;
    leds[l].r = 20; 
    leds[l].g =3; 
    leds[l].b = 0; 
    l++;

    leds[l].r = 35; 
    leds[l].g =5; 
    leds[l].b = 0; 
    l++;//gb combo, l++ = push next

    leds[l].r = 75; 
    leds[l].g =10; 
    leds[l].b = 0; 
    l++;//gb combo, l++ = push next

    leds[l].r = 125; 
    leds[l].g = 24;  
    leds[l].b = 0; 
    l++;  // rgb combo, l++ = push next
    leds[l].r = 175; 
    leds[l].g = 50;  
    leds[l].b = 0; 
    l++;  
    leds[l].r = 255;  
    leds[l].g = 120;  
    leds[l].b = 17; 
    l++; 
    leds[l].r = random(250,50); 
    leds[l].g = 120;  
    leds[l].b = 17; 
    l++;  



    // l+2; 2 space before next led, but NUM_LEDS - 5


    FastSPI_LED.show();  //push current data
    delay(10);        //speed of chase
  }
  //       digitalWrite (PIN, LOW);
  delay(250);    // 3 min. delay (180000 mil sec. - 5leds x 25 mil sec = 59975
}

