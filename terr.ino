#include <Adafruit_GFX.h>    // Core graphics library by Adafruit
#include <Arduino_ST7789.h> // Hardware-specific library for ST7789 (with or without CS pin)
#include <SPI.h>
//#include <Fonts/FreeSans9pt7b.h>

#define TFT_DC    9
#define TFT_RST   8 

#define BACK_COLOR 0x0000
#define TEXT_COLOR 0xFFFF
#define NUM_COLOR 0x07FF
#define BLACK    0x0000
#define BLUE     0x001F
#define RED      0xF800
#define GREEN    0x07E0
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define YELLOW   0xFFE0 
#define WHITE    0xFFFF

Arduino_ST7789 tft = Arduino_ST7789(TFT_DC, TFT_RST);

void setup() {
  Serial.begin(9600);
  Serial.println("Start");
  tft.init(240, 240);
  tft.fillScreen(BACK_COLOR); 
}

void loop() {
  float temp = 40.57535;
  float rh = 45.532;
  showClimate(rh,temp);
  
  delay(1500);
}


void showClimate(float humidity, float temperature){
  
  tft.drawLine(5,120,235,120, TEXT_COLOR);
  tft.drawLine(5,121,235,121, TEXT_COLOR);
  
  // show humidity in upper half of the screen
  tft.setCursor(0,20);
  tft.setTextColor(TEXT_COLOR,BACK_COLOR);
  tft.setTextSize(10);
  tft.print("RH");
  tft.setTextColor(NUM_COLOR,BACK_COLOR);
  tft.print((int) (humidity+0.5));

  // show  temperatire in the lower half of the screen
  int16_t xt,yt,wt,ht;
  int t = (int) temperature;
  tft.setTextSize(8);
  /*tft.getTextBounds("T00", 0, 152, &xt, &yt, &wt, &ht);
  
  Serial.println(xt);
  Serial.println(yt);
  Serial.println(wt);
  Serial.println(ht);
  */
  tft.setCursor(0,152);
  tft.setTextColor(TEXT_COLOR,BACK_COLOR);
  tft.print("T");
  tft.setTextColor(NUM_COLOR,BACK_COLOR);
  tft.print(t);
  drawComma(144,202,8,NUM_COLOR);
  tft.setCursor(160,152);
  tft.print((int)((temperature - t)*10+0.5));
  //tft.fillCircle(218,144,8,NUM_COLOR);
  //tft.fillCircle(218,144,4,BACK_COLOR);
  tft.setCursor(210,130);
  tft.setTextSize(4);
  tft.print("o");
   
}

void drawComma(byte x, byte y,byte size,int16_t color){
      tft.fillRect(x,y,size,size,color);
      tft.fillRect((int)(x+size/2),y+size,(int) (size/2),(int) (size/2),color);
}
