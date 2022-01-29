#include "BluetoothSerial.h"

#include <FastLED.h>

#define NUM_LEDS  109
#define LED_PIN   12

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
int s=0;
int r=152;
int g=0;
int b=10;


char BT_input;
 
CRGB leds[NUM_LEDS];
CRGBPalette16 firePalette = HeatColors_p;
uint8_t hue = 0;

int8_t colorIndex[NUM_LEDS];
uint8_t whichPalette = 0;
uint8_t paletteIndex = 0;

DEFINE_GRADIENT_PALETTE( Sunset_Real_gp ) {
    0, 120,  0,  0,
   22, 179, 22,  0,
   51, 255,104,  0,
   85, 167, 22, 18,
  135, 100,  0,103,
  198,  16,  0,130,
  255,   0,  0,160};


CRGBPalette16 myPal = Sunset_Real_gp;

DEFINE_GRADIENT_PALETTE( greenblue_gp ) { 
    0,    0,  194,  255,     //light blue
   46,    3,    0,  246,     //dark blue
  176,   55,  222,   70,     //bright green
  255,    0,  194,  255      //light blue
};

DEFINE_GRADIENT_PALETTE( orangepink_gp ) { 
    0,  255,  100,    0,     //orange
   90,  255,    0,  255,     //magenta
  150,  255,  100,    0,     //orange
  255,  255,  100,    0      //orange
};

DEFINE_GRADIENT_PALETTE( browngreen_gp ) { 
    0,    6,  255,    0,     //green
   71,    0,  255,  153,     //bluegreen
  122,  200,  200,  200,     //gray
  181,  110,   61,    6,     //brown
  255,    6,  255,    0      //green
};

CRGBPalette16 currentPalette(greenblue_gp);
CRGBPalette16 targetPalette(orangepink_gp);

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
  Serial.begin(115200);
  SerialBT.begin("Desk_Vision"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  pinMode(27,INPUT);
  for (int i = 0; i < NUM_LEDS; i++){
          leds[i]=CRGB::Red;
          FastLED.show();
  }
  for (int i = 0; i < NUM_LEDS; i++){
          leds[i]=CRGB::Green;
          FastLED.show();
  }
  for (int i = 0; i < NUM_LEDS; i++){
          leds[i]=CRGB::Blue;
          FastLED.show();
  }
 for (int i = 0; i < NUM_LEDS; i++) {
    colorIndex[i] = random8();
  }
  for (int i = 0; i < NUM_LEDS; i++){
          leds[i]=CRGB::Black;
          FastLED.show();
  }
  delay(2000);
}

void rgb_rainbow() {                                    //1
  for (int i = 0; i < NUM_LEDS; i++) {
    //leds[i] = CHSV(hue, 255, 255);
    leds[i] = CHSV(hue + (i * 10), 255, 255);
  }

  EVERY_N_MILLISECONDS(15){
    hue++;
  }

  FastLED.show();
}

void red(){
          for (int i = 0; i < NUM_LEDS; i++){
          leds[i]=CRGB::Red;
          }
          FastLED.show();
}

void green(){
          for (int i = 0; i < NUM_LEDS; i++){
          leds[i]=CRGB::Green;
          }
          FastLED.show();
}

void blue(){
          for (int i = 0; i < NUM_LEDS; i++){
          leds[i]=CRGB::Blue;
          }
          FastLED.show();
}

void white(){
         for (int i = 0; i < NUM_LEDS; i++){
          leds[i]=CRGB::White;
          }
          FastLED.show();
}

void yellow(){
          for (int i = 0; i < NUM_LEDS; i++){
          leds[i]=CRGB(255,255,0);
          }
          FastLED.show();
}

void cyan(){
          for (int i = 0; i < NUM_LEDS; i++){
          leds[i]=CRGB(0, 179, 179);
          }
          FastLED.show();
}

void orange(){
          for (int i = 0; i < NUM_LEDS; i++){
          leds[i]=CRGB(230, 92, 0);
          }
          FastLED.show();
}

void lime(){
          for (int i = 0; i < NUM_LEDS; i++){
          leds[i]=CRGB(50,205,50);
          }
          FastLED.show();
}

void pink(){
          for (int i = 0; i < NUM_LEDS; i++){
          leds[i]=CRGB(230, 0, 92);
          }
          FastLED.show();
}

void purple(){
          for (int i = 0; i < NUM_LEDS; i++){
          leds[i]=CRGB(153, 0, 153);
          }
          FastLED.show();
}



void off(){
          for (int i = 0; i < NUM_LEDS; i++){
          leds[i]=CRGB::Black;
          }
          FastLED.show();
}

void music()
{
  s=analogRead(27);
  s=s*2;
  if((s>=450)&&(s<=550))
  {
    leds[(NUM_LEDS/2)-1]=CRGB (0, 0, 255);
    leds[NUM_LEDS/2]=CRGB (0, 0, 255);
  }
  else if((s>=400)&&(s<=450))
  {
    leds[(NUM_LEDS/2)-1]=CRGB (153, 153, 0);
    leds[NUM_LEDS/2]=CRGB (153, 153, 0);
  }
  else if((s>=350)&&(s<=400))
   {
     leds[(NUM_LEDS/2)-1]=CRGB (255, 50, 255);
    leds[NUM_LEDS/2]=CRGB (255, 50, 255);
   }
   else if((s>=300)&&(s<=350))
  {
    leds[(NUM_LEDS/2)-1]=CRGB (10, 25, 217);
    leds[NUM_LEDS/2]=CRGB (10, 25, 217);
  }

    else if((s>=276)&&(s<=300))
   {
     leds[(NUM_LEDS/2)-1]=CRGB (50, 50, 150);
    leds[NUM_LEDS/2]=CRGB (50, 50, 150);
   }
   else if((s>=250)&&(s<=275))
   {
     leds[(NUM_LEDS/2)-1]=CRGB (230, 0, 10);
    leds[NUM_LEDS/2]=CRGB (230, 0, 10);
   }
  else if((s>=235)&&(s<=250))
   {
     leds[(NUM_LEDS/2)-1]=CRGB (0, 160, 0);
    leds[NUM_LEDS/2]=CRGB (0, 160, 0);
   }
   else if((s>=200)&&(s<=230))
   {
     leds[(NUM_LEDS/2)-1]=CRGB (1, 0, 1);
    leds[NUM_LEDS/2]=CRGB (1, 0, 1);
   }
  else
  {
     leds[(NUM_LEDS/2)-1] = CRGB ( r,s-100,b);
     leds[NUM_LEDS/2] = CRGB ( r,s-100,b);
  }
    for (int i = 0; i <= ((NUM_LEDS/2)-2); i++) 
  {
     leds[i] = leds[i+1];
     leds[NUM_LEDS-1-i] = leds[(NUM_LEDS)-i-2];
     
  }
 FastLED.show();
 delay(25);

}

void rgb_blend() {                                              //2
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = ColorFromPalette(currentPalette, colorIndex[i]);
  }

  nblendPaletteTowardPalette( currentPalette, targetPalette, 10 );

  switch (whichPalette) {
    case 0:
      targetPalette = orangepink_gp;
      break;
    case 1:
      targetPalette = browngreen_gp;
      break;
     case 2:
      targetPalette = greenblue_gp;
      break;
  }

  EVERY_N_SECONDS(5) {
    whichPalette++;
    if (whichPalette > 2) whichPalette = 0;
    Serial.println(currentPalette[0]);
  }
  
  EVERY_N_MILLISECONDS(5){
    for (int i = 0; i < NUM_LEDS; i++) {
      colorIndex[i]++;
    }
  }

  FastLED.show();
}

void rgb_aura() {                                                          //3
  fill_palette(leds, NUM_LEDS, paletteIndex, 255 / NUM_LEDS, myPal, 255, LINEARBLEND);
  
  EVERY_N_MILLISECONDS(10){
    paletteIndex++;
  }
  
  FastLED.show();
}
void rgb_fire() {                                             //4
  
  EVERY_N_MILLISECONDS(5) {
    runFire();
  }
                                                                
  FastLED.show();
}

void runFire() {
  int  a = millis();
  
  for (int i = 0; i <NUM_LEDS ; i++) {

    // 3D noise, x is constant, we move through time on y and z axis
    // The 60 here will change the scale of the effect, lower is smoother
    // higher is more flickery. The time value for z was in the original code
    // as that was a 2D matrix version. I've left it in here as it looks 
    // nice in 1D too!
    uint8_t noise = inoise8 (0 , i * 60 + a , a / 3);

    // Divides 255 by (NUM_LEDS - 1) and subtracts that amount away from 255 to return 
    // a decreasing number each time e.g. for NUM_LEDS = 18, difference between
    // each point is 15, so:
    // i = 0, math = 255
    // i = 1, math = 240
    // i = 2, math = 225
    // ...
    // i = NUM_LEDS, math =  0
    uint8_t math = abs8(i - (NUM_LEDS-1)) * 255 / (NUM_LEDS-1);

    // Take the noise function from earlier and subtract math from it,
    // so the further along the strip you are, the higher palette index you
    // are likely to get. This results in the base of the fire (white, yellow)
    // being at the far end of the strip
    uint8_t index = qsub8 (noise, math);

    // Set the LED color from the palette
    leds[i] = ColorFromPalette (firePalette, index, 255);    
  }  
}


void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    BT_input=SerialBT.read();
    Serial.println(BT_input);
  }   
  switch(BT_input){  
    case '0':
              red();
              break;
    case '1':
              green();
              break;
    case '2':
              blue();
              break;
    case '3':
              white();
              break;
    case '4':
              yellow();
              break;
    case '5':
              cyan();
              break;
    case '6':
              orange();
              break;
    case '7':
              lime();
              break;
    case '8':
              pink();
              break;
    case '9':
              purple();
              break;      
    case 'a':
      rgb_rainbow();
      break;
    case 'k':
      rgb_aura();
      break;
    case 'd':
      rgb_blend();
      break;
    case 'f':
      rgb_fire();
      break;
    case 'm':
      music();
      break;  
    case 'O':
      rgb_rainbow();
      break; 
    default :
      off();
  }
}
