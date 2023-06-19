#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <LiquidCrystal.h>
//#include <ledc.h>
LiquidCrystal lcd(19, 23, 18, 17, 16, 15);  // (rs, enable, 4, 5, 6, 7)
byte memory[65536];  // 64kb 64*1024=65536 8085 is an 8-bit microprocessor

#ifndef STASSID
#define STASSID "Vamsi"  // Replace with your network credentials
#define STAPSK  "vamsi04$"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

void OTAsetup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }
  
  ArduinoOTA.begin();
}

void OTAloop() {
  ArduinoOTA.handle();
}

void setup() {
  OTAsetup();
  ledcAttachPin(9,1);
  ledcSetup(1, 12000, 8);
  //pinMode(9, OUTPUT);  // PWM generation pin (vo)
  lcd.begin(16, 2);    // LCD with 16 columns and 2 rows

  memory[0x2001] = 0x98;  // Give Memory location 2001H a value of 98H
  memory[0x2002] = 0xB1;  // Give Memory location 2002H a value of B1H
  
  lcd.print("Calculating...");
}

void loop() {
  OTAloop();
  ledcWrite(1, 100);
//  analogWrite(9, 100);  // PWM control
  
  int HL = 0x2001;  // HL register pair points to memory location 2001H
  int A = 0x21;     // Accumulator with value 21H

  HL++;            // Increment HL; HL becomes 2002H = B1H
  A += memory[HL]; // A = A + dataHL pair; A = 21H + B1H
  HL++;            // Increment HL; HL becomes 2003H
  memory[HL] = A;  // Memory location 2003H is assigned the value of A (D2H)

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Result:");
  lcd.setCursor(0, 1);
  lcd.print(memory[0x2003]);

  while (1) {
    // Code will stay in this loop indefinitely
  }
}
