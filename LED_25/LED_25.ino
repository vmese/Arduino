#include<Adafruit_NeoPixel.h>

#define PIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(64, PIN, NEO_GRB + NEO_KHZ800);
int i, j, k, l;
int but;

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

}

void loop() {
  //but = Serial.read();

  //switch(but){


  
   
        for (i = 0; i < 64; i++) {
          strip.setPixelColor(i, 255, 255, 255 );
          strip.show();
          Serial.println("j,k,l");
        }
    
  
  
  // bouche droit
//  strip.setPixelColor(9, 50, 50, 50 );
//  strip.setPixelColor(10, 50, 50, 50);
//  strip.setPixelColor(13, 50, 50, 50);
//  strip.setPixelColor(14, 50, 50, 50);
//  strip.setPixelColor(17, 50, 50, 50);
//  strip.setPixelColor(18, 50, 50, 50);
//  strip.setPixelColor(21, 50, 50, 50);
//  strip.setPixelColor(22, 50, 50, 50);
//  strip.setPixelColor(32, 50, 50, 50);
//  strip.setPixelColor(33, 50, 50, 50);
//  strip.setPixelColor(34, 50, 50, 50);
//  strip.setPixelColor(35, 50, 50, 50);
//  strip.setPixelColor(36, 50, 50, 50);
//  strip.setPixelColor(37, 50, 50, 50);
//  strip.setPixelColor(38, 50, 50, 50);
//  strip.setPixelColor(39, 50, 50, 50);
//  strip.setPixelColor(40, 50, 50, 50);
//  strip.setPixelColor(41, 50, 50, 50);
//  strip.setPixelColor(42, 50, 50, 50);
//  strip.setPixelColor(43, 50, 50, 50  );
//  strip.setPixelColor(44, 50, 50, 50 );
//  strip.setPixelColor(45, 50, 50, 50 );
//  strip.setPixelColor(46, 50, 50, 50  );
//  strip.setPixelColor(47, 50, 50, 50  );
//  strip.show();

//clin 
  strip.setPixelColor(9, 50, 50, 50 );
  strip.setPixelColor(10, 50, 50, 50 );
  strip.setPixelColor(13, 50, 50, 50 );
  strip.setPixelColor(14, 50, 50, 50 );
  strip.setPixelColor(21, 50, 50, 50 );
  strip.setPixelColor(22, 50, 50, 50 );
  strip.setPixelColor(32, 50, 50, 50 );
  strip.setPixelColor(39, 50, 50, 50 );
  strip.setPixelColor(40, 50, 50, 50 );
  strip.setPixelColor(41, 50, 50, 50 );
  strip.setPixelColor(42, 50, 50, 50 );
  strip.setPixelColor(43, 50, 50, 50 );
  strip.setPixelColor(44, 50, 50, 50 );
strip.setPixelColor(45, 50, 50, 50 );
strip.setPixelColor(46, 50, 50, 50 );
strip.setPixelColor(47, 50, 50, 50 );
strip.setPixelColor(48, 50, 50, 50 );
strip.setPixelColor(50, 50, 50, 50 );
strip.setPixelColor(51, 50, 50, 50 );
strip.setPixelColor(52, 50, 50, 50 );
strip.setPixelColor(53, 50, 50, 50 );
strip.setPixelColor(54, 50, 50, 50 );
strip.setPixelColor(55, 50, 50, 50 );
strip.show();


}
