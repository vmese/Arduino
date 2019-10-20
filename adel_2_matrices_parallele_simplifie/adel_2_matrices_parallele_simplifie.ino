#include<Adafruit_NeoPixel.h>

#define PIN 6
#define maxBrightness 128
Adafruit_NeoPixel strip = Adafruit_NeoPixel(64, PIN, NEO_GRB + NEO_KHZ800);
int i, j, k, l;
int but;
int r,v,b;
int brightness, currentBrightness ;
String inputString = "";
boolean stringComplete = false;  // whether the string is complete
boolean expressionEnabled = false;
int expressionNb = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  inputString.reserve(200);
  
  strip.begin();
  for (i = 0; i < 64; i++) {
    strip.setPixelColor(i, 255, 255 , 255  );
  }
  
  currentBrightness = 0;
  strip.setBrightness(10);
        
  strip.show(); // Initialize all pixels to 'off'
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    } 
  }
}

void setLedsBrightness(int brightness)
{
        if (brightness!=currentBrightness)
        {
          //for (i = 0; i < 64; i++) 
          //{
          //  strip.setPixelColor(i,random(1,255),random(1,255),random(1,255));
          //}
          strip.setBrightness(brightness);
          currentBrightness=brightness;
        }
}

void loop() 
{
  if (stringComplete) 
  {
    char command = inputString[0];
    switch (command)
    {
        case 'L' :
        {
          r = inputString[1];
          v = inputString[2];
          b = inputString[3];
          break;
       }
       
       case 'B' :
       {
        brightness = (unsigned int)(unsigned char)inputString[1]; 
        if (brightness>=maxBrightness)
        {
          brightness = maxBrightness;
        }
        setLedsBrightness(brightness);
        strip.show();
        break;
       }


       case 'E':
       {
            expressionNb = (int) inputString[1];
            switch (expressionNb)
            {
              case 1 :
              {
                // effet spot 
                int indLeds[26] = {6,7,13,14,15,20,21,22,23,28,29,30,31,36,37,38,39,44,45,46,47,53,54,55,62,63};
                for (i = 0; i < 64; i++) 
                {
                  strip.setPixelColor(i, 0, 0, 0);
                }
                for (i =0 ; i<26 ; i++)
                {
                  strip.setPixelColor(indLeds[i], r,  v, b );
                }
                break;
              }
              case 2 :
              {
    
                int indBlueLeds[12] = {11,12,18,21,26,29,34,37,42,45,51,52};
                int indGreenLeds[8] = {19,20,27,28,35,36,43,44};
                for (i = 0; i < 64; i++) 
                {
                  strip.setPixelColor(i, 0, 0, 0);
                }
                for (i =0 ; i<12 ; i++)
                {
                strip.setPixelColor(indBlueLeds[i], 0,  0, 255 );
                }
                for (i =0 ; i<8 ; i++)
                {
                strip.setPixelColor(indGreenLeds[i], 0,  255, 0 );
                }
              }            
            } // end switch expression Nb
        expressionEnabled=true;
        strip.show();
        break;
      }
       
      case 'N' :
      {
        for (i = 0; i < 64; i++) 
        {
          strip.setPixelColor(i, r, v, b);
        }
        expressionEnabled=false;
        expressionNb = 0;
        //strip.setBrightness(brightness);
        strip.show();
        break;
       }
   
       default :
          break;
    }
 
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}
