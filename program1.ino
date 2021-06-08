//importing required header files
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

String para=""; //variable to store the input string
void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3D)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds
  display.clearDisplay(); // Clear the buffer
  
}
void loop() {
display.setTextSize(1);//setting text size 
display.setTextColor(SSD1306_WHITE);//setting text color
display.setCursor(0,0);//setting text position
while(Serial.available()==0)//checking if data is available in serial monitor
{
  //infinite loop waiting for the data
}
para=Serial.readString();//reading the data
display.print(para);//displaying it on the oled display
display.display();//to display the data available
if(para.charAt(176)!=" ")
{
display.clearDisplay();//clearing the screen 
display.setCursor(0,0);//setting text position
display.print(para);//displaying it on the oled display
display.display();//to display the data available
}
display.clearDisplay();//clearing the screen
}
