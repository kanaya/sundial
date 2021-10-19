#include <Adafruit_NeoPixel.h>

const int Signal_Pin = 6;
const int N_Pixels = 24;
const int Delay = 10;

Adafruit_NeoPixel pixels(N_Pixels, Signal_Pin, NEO_GRB + NEO_KHZ800);

int hour = 0; // 0 to 2400

int step_num = 0;
int delta = 1;
int color[] = {255, 255, 0};

uint32_t hourToRGB(int h, int i) {
  // 0 <= h < 2400

  Serial.print("h = ");
  Serial.print(h);
  Serial.print(", i = ");
  Serial.println(i);

  float j = float(i) / float(N_Pixels);
  float k = float(h) / 2400.0;
  float l = k - j;
  
  float sunness = exp(-l * l * 24.0 * 24.0);
  
  int r = int(255.0 * sunness);
  int g = int(255.0 * sunness);
  int b = int(255.0 * sunness);
  return pixels.Color(r, g, b);
}

void setup() {
  Serial.begin(9600);
  pixels.begin();
  pixels.show();
}

void loop() {
  for (hour = 0; hour < 2400; ++hour) {
    for (int i = 0; i < pixels.numPixels(); ++i) {
      uint32_t pixelColor = hourToRGB(hour, i);
      pixels.setPixelColor(i, pixels.gamma32(pixelColor));
    }
    pixels.show();
    delay(Delay);
  }
}
