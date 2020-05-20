#include <Arduino.h>
#include <FastLED.h>

static const int kNumLeds = 2;

CRGB leds[kNumLeds];

void setup() {
  WDT->CTRL.reg = 0;
  Serial.begin(115200);
  Serial.println("Hello");
  FastLED.addLeds<WS2812, WS2812_PIN>(leds, kNumLeds);
  FastLED.showColor(CRGB(0, 0, 0));
}

void loop() {
  FastLED.showColor(CHSV(millis() / 10, 255, 64));
  //FastLED.showColor(CRGB(millis() % 64, 0, 0));
  Serial.println(millis());
  delay(100);
}
