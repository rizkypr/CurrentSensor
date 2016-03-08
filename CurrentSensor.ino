
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);


#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

float current = 0.0;
float current2 = 0.0;
float testcurrent1 = 0.0;
float testcurrent2 = 0.0;
int led = 13;



void setup()   {               
  
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000);

  }


void loop() {
  
      for(int i = 0; i < 1000; i++) {
      
      current = (0.0049 * analogRead(A1)) - 2.5;
      current = current / 0.066; //30A
      current2 = current2 + current;

      //testcurrent1 = (0.0049 * analogRead(A1)) - 2.5;
      //testcurrent1 = testcurrent1 / 0.185; //20A    
      //testcurrent2 = testcurrent2 + testcurrent1;
      delay(1); }
      
      current2 = current2/1000;
      //testcurrent2 = testcurrent2/1000;
 
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.print("Current: ");
      display.print(current2);
      display.println(" ma"); 
      display.print('\n');
      //display.print(analogRead(A1));
      //display.print('\n');
      //display.print("Current(20): ");
      //display.print(testcurrent2);



  display.display();
    
  digitalWrite(led, HIGH);   
  delay(200);
  digitalWrite(led, LOW);    
  
}
