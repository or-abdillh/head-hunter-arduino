#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>

#define BLACK   0x0000
#define RED     0xF800
#define WHITE   0xFFFF
#define BLUE    0x001F
#define NAVY    0x000F

#define Sensor1 22
#define Sensor2 24
#define Sensor3 26
#define Sensor4 28
#define Sensor5 30

#define TRIG 23
#define ECHO 25

#define Buzzer 32
#define temp A11

// Voltage sensor
#define voltage_pin A10
float vOUT = 0.0;
float vIN = 0.0;
float R1 = 30000.0;
float R2 = 7500.0;
int value = 0;

int val;
String message;

MCUFRIEND_kbv tft;

void setup() {

  // zSetup sensor
  pinMode(Sensor1, INPUT);
  pinMode(Sensor2, INPUT);
  pinMode(Sensor3, INPUT);
  pinMode(Sensor4, INPUT);
  pinMode(Sensor5, INPUT);

  pinMode(Buzzer, INPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  
  // put your setup code here, to run once:
  uint16_t ID = tft.readID();
  tft.begin(ID);
  tft.fillScreen(NAVY);
  Serial.begin(9600);  
}

void loop() {
  int values[] = {
    digitalRead(Sensor1),
    digitalRead(Sensor2),
    digitalRead(Sensor3),
    digitalRead(Sensor4),
    digitalRead(Sensor5)
   };

    // Fire calculate
    for(int x=0; x<4; x++){
      // remove before character      
      tft.fillScreen(NAVY);
      if (values[x] > 0) {
        digitalWrite(Buzzer, HIGH);
        message = "**FIRE**";
        Serial.println("**FIRE**");
      } else {
        digitalWrite(Buzzer, LOW);
        message = "**NO FIRE**";
        Serial.println("**NO FIRE**");  
    }
  }

  // Distance calculate
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  const unsigned long duration= pulseIn(ECHO, HIGH);
  int distance= duration/29/2;

  tft.setCursor(25,100);
  tft.setTextSize(3);
  tft.setTextColor(WHITE);
  tft.println("DISTANCE ");

  tft.setCursor(25,130);
  tft.setTextSize(3);
  tft.setTextColor(RED);
  tft.println(distance);

  Serial.println(distance);
   
  // Temperature
  val = analogRead(temp);
  float mv = ( val/1024.0)*5000;
  float cel = mv/10;
  float farh = (cel*9)/5 + 32;
  Serial.print("TEMPRATURE = ");
  Serial.print(val);
  Serial.print("*C");
  Serial.println(cel);

  // Showing temperature
  tft.setCursor(25,200);
  tft.setTextSize(3);
  tft.setTextColor(WHITE);
  tft.println("TEMPRATURE ");
  
  tft.setCursor(45,250);
  tft.setTextSize(3);
  tft.setTextColor(RED);
  tft.println(cel);
  
  // Showing Fire alert
  tft.setCursor(25,300);
  tft.setTextSize(3);
  tft.setTextColor(WHITE);
  tft.println(message);

  // Showing voltage 
  value = analogRead(voltage_pin);
  vOUT = (value * 5.0) / 1024.0;
  vIN = vOUT / (R2/(R1+R2));
  
  tft.setCursor(25,400);
  tft.setTextSize(3);
  tft.setTextColor(WHITE);
  tft.println("VOLTAGE IN");

  
  tft.setCursor(25,450);
  tft.setTextSize(3);
  tft.setTextColor(RED);
  tft.println(vIN);
  delay(500);
}
