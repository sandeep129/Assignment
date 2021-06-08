//Importing required library files
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//Initializing the OLED display
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
String para="";

void setup() {
  Serial.begin(9600);//Setting the baud rate for communication with Serial Monitor

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3D)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));//Printing error message if display is not connected or allocated
    for(;;);//infinite loop waiting for display to be allocated
  }
  delay(2000);// delay of 2000
  display.clearDisplay();//clear the display

  display.setTextSize(5*7);//setting the text size
  display.setTextColor(WHITE);//setting the color
  display.setCursor(0, 0);//setting the cursor where to start printing
  while(Serial.available()==0)//checking if data is available in serial monitor
{
  //infinite loop waiting for the data
}
para=Serial.readString();//reading the data
display.print(para);//displaying it on the oled display
setTextWrap(true);//default function for wraping the text in gfx 
setTextScroll(true);// for scrolling the data
display.display();//to display the data available
}

void loop() {
  
}
void setTextWrap(boolean w)//function for text wraping
{
  w=true;
}
void setTextScroll(boolean z)//function for text scrolling
{
  delay(500);
  z=true;
  
}
