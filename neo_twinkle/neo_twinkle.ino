#include <Adafruit_NeoPixel.h>

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(32, PIN, NEO_GRB + NEO_KHZ800); //first number controls the amount of pixels you have (add 4 so the drip falls off the edge)
int bright = 10;    //select 1 thru 10
int wait = 100;     //select speed of blinking

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}
void loop() {
  for(int i=0; i<strip.numPixels(); i++) {
      
    int randr = random(0,(25*bright));
    int randg = random(0,(25*bright)); 
    int randb = random(0,(25*bright));
    int randi = random(0,strip.numPixels());
    int randii = random(0,strip.numPixels());
      strip.setPixelColor(randi, randr, randr, randr);
     // strip.setPixelColor(i-1, strip.Color(r,g,(b-150)));
     // strip.setPixelColor(i-2, strip.Color(r,g,(b-200)));
    // strip.setPixelColor(i-3, strip.Color(r,g,(b-250))); // add more of these lines to make the trail longer
      strip.show();
      delay(1);
      strip.setPixelColor(i, strip.Color(0,0,0)); // make sure the i-number is the amount of the trail
      strip.show();
      delay(wait);   
  }
}


