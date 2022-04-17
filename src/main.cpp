#include <Arduino.h>
#include <M5EPD.h>
#include <WiFi.h>

M5EPD_Canvas canvas(&M5.EPD);

void setup()
{
    M5.begin();
    M5.EPD.SetRotation(90);
    M5.EPD.Clear(true);
    M5.RTC.begin();
    WiFi.begin("Redmi_3602", "36023602");

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    canvas.createCanvas(540, 960);
    canvas.setTextSize(3);
}


void loop()
{
  canvas.drawJpgUrl("https://us.vlan.tinyws.com/test.jpg");
  canvas.pushCanvas(0,0,UPDATE_MODE_GC16);
  sleep(20);
}