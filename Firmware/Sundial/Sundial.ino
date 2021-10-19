#include <Adafruit_NeoPixel.h>

const int Signal_Pin = 6;
const int N_Pixels = 24;
const int Delay = 10;

Adafruit_NeoPixel pixels(N_Pixels, Signal_Pin, NEO_GRB + NEO_KHZ800);

int hour = 600; // 0 to 2400

int step_num = 0;
int delta = 1;
int color[] = {255, 255, 0};

uint32_t hourToRGB(int h, int i) {
  // 0 <= h < 2400
  // 0 <= i < N_Pixels
  int index = h * N_Pixels / 2400;
  int sunness;  // 0 to 255
  int rgb;
  if (i == index) {
    sunness = 255;
  }
  else {
    sunness = 0;
  }
  int r = sunness;
  int g = sunness / 2;
  int b = 255 - sunness;
  return pixels.Color(r, g, b);
}

void setup() {
  pixels.begin();
  pixels.show();
}

void loop() {
  for (int i = 0; i < pixels.numPixels(); ++i) {
    uint32_t pixelColor = hourToRGB(hour, i);
    pixels.setPixelColor(i, pixels.gamma32(pixelColor));
  }
  pixels.show();
  delay(Delay);
}
