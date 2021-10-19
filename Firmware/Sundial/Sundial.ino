#include <Adafruit_NeoPixel.h>

const int Signal_Pin = 6;
const int N_Pixels = 24;
const int Delay = 10;

Adafruit_NeoPixel pixels(N_Pixels, Signal_Pin, NEO_GRB + NEO_KHZ800);

int hour = 600; // 0 to 2400

int step_num = 0;
int delta = 1;
int color[] = {255, 255, 0};

int hourToHue(int h, int i) {
  // 0 <= h < 2400
  // 0 <= i < N_Pixels
  int index = h * N_Pixels / 2400;
  int hue;
  if (i == index) {
    hue = 0;
  }
  else {
    hue = 65536L / 2;
  }
  return hue;
}

void setup() {
  pixels.begin();
}

void loop() {
  for (int i = 0; i < pixels.numPixels(); ++i) {
    int pixelHue = hourToHue(hour, i);
    pixels.setPixelColor(i, pixels.gamma32(pixels.ColorHSV(pixelHue)));
  }
  pixels.show();
  delay(Delay);
}
