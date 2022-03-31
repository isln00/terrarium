#include <Adafruit_GFX.h>    // Core graphics library by Adafruit
#include <Arduino_ST7789.h> // Hardware-specific library for ST7789 (with or without CS pin)
#include <SPI.h>
//#include <Fonts/FreeSans9pt7b.h>

#define TFT_DC    9
#define TFT_RST   8 

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
  tft.init(240, 240);
  tft.fillScreen(BLACK); 
  tft.drawLine(5,120,235,120, WHITE);
  tft.drawLine(5,121,235,121, WHITE);
}

void loop() {
  tft.setCursor(0,20);
  tft.setTextColor(WHITE,BLACK);
  tft.setTextSize(10);
  tft.print("RH");
  tft.setTextColor(CYAN,BLACK);
  tft.print(millis()%100);

  tft.setTextSize(8);
  tft.setCursor(0,140);
  tft.print("T");
  tft.setTextColor(RED,BLACK);
  int t = 22;
  int s = millis()%10;
  tft.print(t);
  tft.print(s);
  
  delay(500);
}


void showAll(int rh, float temp){
  
}
