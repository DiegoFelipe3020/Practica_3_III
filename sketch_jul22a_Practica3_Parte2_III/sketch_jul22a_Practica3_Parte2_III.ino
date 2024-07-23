#include <Wire.h>            
#include <Adafruit_GFX.h>    
#include <Adafruit_SSD1306.h> 
#define widht_oled    128 
#define height_oled   64 

Adafruit_SSD1306 oled_display(widht_oled,height_oled,&Wire, -1);

int pot = A2;
int valpot;

void setup() {
 Serial.begin(9600);      
 if(!oled_display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
  Serial.println("ERROR");
  while(1);
 }
 oled_display.clearDisplay();
 oled_display.setTextSize(1);
 oled_display.setTextColor(SSD1306_WHITE);
 oled_display.display();
}
void loop() {
  valpot = analogRead(pot);
  ADC = map(valpot, 0, 1023, 0, 1023);
  oled_display.clearDisplay();
  oled_display.setCursor(0, 0);
  oled_display.println("Valor del ADC:");
  oled_display.setCursor(0, 10);
  oled_display.println(ADC);
  oled_display.display();
  delay(100);
}