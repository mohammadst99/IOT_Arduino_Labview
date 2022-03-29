# IOT_Arduino_Labview
in this video we program and design an IOT system that can measure ( light , temperature , humidity , distance ) and also can turn ON/OFF the light system in the home and we display the data on the monitor and server using LABVIEW

# Application

 you have to install Arduino Ide
 > then you have to import DHT.h (Dht11) libraries)
 
 you have to install LABVIEW 2019 
 > you have to use visa port 
 
# Sensores modules

1. DHT 11 
> we can measure temperature and humidity with this module 

2. SRF 05
> it is an ultrasonic module that you can use to get the distance 

3. relay 5v
> with this part you can use a voltage higher than 12 v and control them with micro to turn ON/OFF

4.photocell
> with this part we are able to measure the light and micro can decide to turn lightening system ON or OFF

5.Arduino Uno

6.Led


# Conection Explain

1. DHT 11
> connect TRIG_PIN to pin 13 Arduino Uno
> connect ECHO_PIN to pin 12 Arduino Uno
> Connect pin 1 (on the left) of the sensor to +5V
> NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1 to 3.3V instead of 5V!
> Connect pin 2 of the sensor to whatever your DHTPIN is
> Connect pin 4 (on the right) of the sensor to GROUND
> Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

2. PHOTOCELL
> connect one pin to the pin 0 Arduino Uno
> and the other pin with 10K resistance to VCC and Gnd

3. Realy 5V
> connect int relay to pin 4 Arduino
> connect vcc to 5V on arduino
> connect GND to Gnd arduino



# Test Video
![](https://github.com/mohammadst99/IOT_Arduino_Labview/blob/main/test.gif)

# Labview OutPut

# Explain Labview 
