/**************************************************************************
 This is an example for our Monochrome OLEDs based on SSD1306 drivers

 Pick one up today in the adafruit shop!
 ------> http://www.adafruit.com/category/63_98

 This example is for a 128x32 pixel display using I2C to communicate
 3 pins are required to interface (two I2C and one reset).

 Adafruit invests time and resources providing this open
 source code, please support Adafruit and open-source
 hardware by purchasing products from Adafruit!

 Written by Limor Fried/Ladyada for Adafruit Industries,
 with contributions from the open source community.
 BSD license, check license.txt for more information
 All text above, and the splash screen below must be
 included in any redistribution.
 **************************************************************************/

#include <lcd_hello_world.h>
#include <SPI.h>
#include <Wire.h>


void setup() {
    Serial.begin(9600);

    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;); // Don't proceed, loop forever
    }

    // Show initial display buffer contents on the screen --
    // the library initializes this with an Adafruit splash screen.
    display.display();
    delay(2000); // Pause for 2 seconds

    // Clear the buffer
    display.clearDisplay();

    // Draw a single pixel in white
    display.drawPixel(10, 10, SSD1306_WHITE);

    // Show the display buffer on the screen. You MUST call display() after
    // drawing commands to make them visible on screen!
    display.display();
    delay(2000);
    // display.display() is NOT necessary after every single drawing command,
    // unless that's what you want...rather, you can batch up a bunch of
    // drawing operations and then update the screen all at once by calling
    // display.display(). These examples demonstrate both approaches...

    drawText();

    // testDrawLine(); // Draw many lines
    //
    // testDrawRect(); // Draw rectangles (outlines)
    //
    // testFillRect(); // Draw rectangles (filled)
    //
    // testDrawCircle(); // Draw circles (outlines)
    //
    // testFillCircle(); // Draw circles (filled)
    //
    // testDrawRoundRect(); // Draw rounded rectangles (outlines)
    //
    // testFillRoundRect(); // Draw rounded rectangles (filled)
    //
    // testDrawTriangle(); // Draw triangles (outlines)
    //
    // testFillTriangle(); // Draw triangles (filled)
    //
    // testDrawChar(); // Draw characters of the default font
    //
    // testDrawStyles(); // Draw 'stylized' characters
    //
    // testScrolltext(); // Draw scrolling text
    //
    // testDrawBitmap(); // Draw a small bitmap image

    // Invert and restore display, pausing in-between
    // display.invertDisplay(true);
    // delay(1000);
    // display.invertDisplay(false);
    // delay(1000);

    // testAnimate(logo_bmp, LOGO_WIDTH, LOGO_HEIGHT); // Animate bitmaps
}

void loop() {
}
