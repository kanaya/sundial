#include <Adafruit_NeoPixel.h>

const int Signal_Pin = 6;
const int N_Pixels = 24;
const int Delay = 10;

Adafruit_NeoPixel pixels(N_Pixels, Signal_Pin, NEO_GRB + NEO_KHZ800);

int step_num = 0;
int delta = 1;
int color[] = {255, 255, 0};

void setup() {
  pixels.begin();
}

void loop() {
  for (int i = 0; i < pixels.numPixels(); ++i) {
    int pixelHue = step_num + (i * 65536L / pixels.numPixels());
    pixels.setPixelColor(i, pixels.gamma32(pixels.ColorHSV(pixelHue)));
  }
  pixels.show();
  step_num += 256;
  if (step_num >= 65536) {
    step_num = 0;
  }
  delay(Delay);
}
