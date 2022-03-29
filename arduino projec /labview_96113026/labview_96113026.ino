

#include "DHT.h"
const unsigned int TRIG_PIN=13;
const unsigned int ECHO_PIN=12;
//const unsigned int BAUD_RATE=9600;


#define DHTPIN 2     // Digital pin connected to the DHT sensor
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(DHTPIN, DHTTYPE);
int photocellPin = 0; 
int photocellReading;
int incomingByte =0;
void setup() {
   pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(4,OUTPUT);pinMode(8,OUTPUT);
  digitalWrite(4,LOW);
  digitalWrite(8, LOW);
  Serial.begin(9600);
//  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
    int d;
  int a =d;if(a>350) a=330;
 // delay(100);
 digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  photocellReading = analogRead(photocellPin);   if(photocellReading<350) digitalWrite(8,HIGH); else digitalWrite(8,LOW);
  

 const unsigned long duration= pulseIn(ECHO_PIN, HIGH);
 int distance= duration;
  d=duration/29/2;
  if(d>350 || d-a>200 || a-d<-200) { d=a;}
 // if(d>350) {d=330;}
  

    
 
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  if(Serial.available() > 0){ 
incomingByte=Serial.read(); //Serial.print(incomingByte);}

  if(incomingByte==49){ digitalWrite(4,HIGH); } if(incomingByte==48) digitalWrite(4,LOW);
  if(incomingByte==65){
  Serial.print("d");Serial.print(d);Serial.print(",");
  Serial.print("p");Serial.print(photocellReading); Serial.print(",");

//  Serial.print(F("Humidity: "));
  Serial.print("s");Serial.print(h); Serial.print(",");
 // Serial.print(F("%  Temperature: "));
  Serial.print("t");Serial.print(t);Serial.print(","); Serial.println();}}
 // Serial.print(F("°C "));
//  Serial.print(f);
//  Serial.print(F("°F  Heat index: "));
//  Serial.print(hic);
//  Serial.print(F("°C "));
//  Serial.print(hif);
//  Serial.println(F("°F"));
}
