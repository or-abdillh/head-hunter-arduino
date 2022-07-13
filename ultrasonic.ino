const unsigned int TRIG_PIN=13; 
const unsigned int ECHO_PIN=12; 
const unsigned int BAUD_RATE=9600;

void loop() {}

void setup() {
   Serial.begin(BAUD_RATE);  
   pinMode(TRIG_PIN, OUTPUT);  
   digitalWrite(TRIG_PIN, LOW);
   delayMicroseconds(2);
   digitalWrite(TRIG_PIN, HIGH);
   delayMicroseconds(10);
   digitalWrite(TRIG_PIN, LOW);
   delayMicroseconds(2);
   
   pinMode(ECHO_PIN, INPUT); 
   const unsigned long duration= pulseIn(ECHO_PIN, HIGH); 
    int distance= duration/29/2;
    if(duration==0) 
      { 
        Serial.println("Warning: no pulse from sensor"); 
      } else { 
        Serial.print("Distance: ");
        Serial.print(distance);
        Serial.print(" cm\n"); 
      } delay(100);
}
