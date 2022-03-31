#include <Adafruit_GFX.h>    // Core graphics library by Adafruit
#include <Arduino_ST7789.h> // Hardware-specific library for ST7789 (with or without CS pin)
#include <SPI.h>
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_SHT31.h>

#define TFT_DC    9
#define TFT_RST   8 

#define BACK_COLOR 0x0000
#define TEXT_COLOR 0xFFFF
#define NUM_COLOR 0x07FF


Arduino_ST7789 tft = Arduino_ST7789(TFT_DC, TFT_RST);
Adafruit_SHT31 sht35 = Adafruit_SHT31();

bool enableHeater = false;

void setup() {
  Serial.begin(9600);
  Serial.println("Start");
  tft.init(240, 240);
  tft.fillScreen(BACK_COLOR); Serial.print("Heater Enabled State: ");
}

void loop() {
  sht35.begin(0x44);
  float temp = sht35.readTemperature();
  float rh = sht35.readHumidity();
 
  showClimate(temp,rh);
  delay(500);
}


void showClimate(float temperature, float humidity){
  
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
  int t = (int) temperature;
  tft.setTextSize(8);

  tft.setCursor(0,152);
  tft.setTextColor(TEXT_COLOR,BACK_COLOR);
  tft.print("T");
  tft.setTextColor(NUM_COLOR,BACK_COLOR);
  tft.print(t);
  drawComma(144,202,8,NUM_COLOR);
  tft.setCursor(160,152);
  tft.print((int)((temperature - t)*10+0.5)%10);

  tft.setCursor(210,130);
  tft.setTextSize(5);
  tft.print("o");
   
}

void drawComma(byte x, byte y,byte size,int16_t color){
      tft.fillRect(x,y,size,size,color);
      tft.fillRect((int)(x+size/2),y+size,(int) (size/2),(int) (size/2),color);
}
