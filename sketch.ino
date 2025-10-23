#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED display width and height, in pixels
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Create display object connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  // Initialize display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // 0x3C is the default I2C address
    Serial.begin(9600);
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }

  // Clear display buffer
  display.clearDisplay();

  // Set text properties
  display.setTextSize(2);        // Text size (1 = small, 2 = medium, etc.)
  display.setTextColor(SSD1306_WHITE); // White text
  display.setCursor(10, 25);     // X, Y position

  // Print text
  display.println("Hello, World!");

  // Display the text on screen
  display.display();
}

void loop() {
  // Nothing to do here
}
