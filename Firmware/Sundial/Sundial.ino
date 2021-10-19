#include <Adafruit_NeoPixel.h>
#define PIN        6 // 信号用のピンを指定
#define NUMPIXELS 24 // LEDの数を指定

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 10

int step_num = 0;
int delta = 1;
int color[] = {255, 255, 0};

void setup() {
  pixels.begin();
}

void loop() {
  for(int i=0; i<pixels.numPixels(); i++) {
    // ストリップの長さに沿って色相環（65536の範囲）を1回転させる量だけピクセルの色相をオフセットします。
    int pixelHue = step_num + (i * 65536L / pixels.numPixels());
    // ColorHSV関数に色相(0 to 65535)を渡し、その結果をgamma32()でガンマ補正します。
    pixels.setPixelColor(i, pixels.gamma32(pixels.ColorHSV(pixelHue)));
  }
  pixels.show();
  step_num += 256;
  if (step_num == 65536) {
    step_num = 0;
  }
  delay(DELAYVAL);
}
