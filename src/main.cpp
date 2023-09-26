#include <Arduino.h>
#include <SSD1306.h>

SSD1306 display(0x3c,4,5,GEOMETRY_128_32);
int val = 0;
float alpha = 0.2;
float ewma = 0.0;

void setup(){
  Serial.begin(115200);
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_16);
  display.display();

}
void loop()
{
  val = analogRead(0);
  ewma = alpha*val + (1-alpha)*ewma;

  char val_str[20];
  sprintf(val_str,"VAL : %d",val);
  char ewma_str[20];
  sprintf(ewma_str,"EWMA : %.2f",ewma);
  display.clear();
  display.drawString(16,0,val_str);
  display.drawString(0,16,ewma_str);
  display.display();

  delay(500);
}
