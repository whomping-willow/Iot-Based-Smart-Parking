#define BLYNK_TEMPLATE_ID "TMPL6fhXAZLDz"
#define BLYNK_TEMPLATE_NAME "Car Parking"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Go to the Project Settings (nut icon).
char auth[] = "68OGJYJTHvxnTBCx5we9DUNYX-yH_7zi";

// Your WiFi credentials.
char ssid[] = "student";
char pass[] = "iotstudent";

Servo myservo;
Servo myservo1;
int open_g = D0;
int opendata;

int exit_g = D3;
int exitdata;

int One = D4;
int onedata;

int Two = D7;
int twodata;

int flag = 0;

void setup() {
  Serial.begin(9600);
  pinMode(open_g, INPUT);
  pinMode(exit_g, INPUT);
  pinMode(One, INPUT);
  pinMode(Two, INPUT);

  myservo.attach(D6);
  myservo1.attach(D5);
  myservo.write(180);
  myservo1.write(180);
  lcd.init();
  lcd.backlight();
  
  Blynk.config(auth);
  delay(10);
}

void loop() {
  opendata = digitalRead(open_g);
  exitdata = digitalRead(exit_g);
  onedata = digitalRead(One);
  twodata = digitalRead(Two);

  if (opendata == 0 && flag == 0) {
    myservo.write(30);
    delay(3000);
    myservo.write(180);
  }

  delay(500);
  lcd.clear();

  if (onedata == 0) {
    lcd.setCursor(0, 0);
    lcd.print("Sloat 1: Full");
    Blynk.virtualWrite(V0, "Full");
  }

  if (onedata == 1) {
    lcd.setCursor(0, 0);
    lcd.print("Sloat 1: Empty");
    Blynk.virtualWrite(V0, "Empty");
    flag = 0;
  }

  if (twodata == 0) {
    lcd.setCursor(0, 1);
    lcd.print("Sloat 2: Full");
    Blynk.virtualWrite(V1, "Full");
  }

  if (twodata == 1) {
    lcd.setCursor(0, 1);
    lcd.print("Sloat 2: Empty");
    Blynk.virtualWrite(V1, "Empty");
    flag = 0;
  }

  if (onedata == 0 && twodata == 0) {
    flag = 1;
  }

  if (exitdata == 0) {
    myservo1.write(30);
    delay(3000);
    myservo1.write(180);
  }
}
