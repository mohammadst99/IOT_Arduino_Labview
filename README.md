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
in the first tab we have come port , data buffer online and all data that sent to the PC with the port that was choosen and a key for START and Stop also in this tab we can see the baud rate of the serial port

![](https://github.com/mohammadst99/IOT_Arduino_Labview/blob/main/Labview%20Images/tab1.png)

in the second tab we have indicator for each part (the first one is humidity then we have distance and at the bottom of distance we have the light parameter and then we have tempreture
![](https://github.com/mohammadst99/IOT_Arduino_Labview/blob/main/Labview%20Images/tab2.png)

# Explain Labview 
 in this part i explain the back of LABVIEW 
 
 in the first part i adjusted the visa port (come , boudrate , I/O ,...) and the Output of Visa Terminal is Error and DATA 
 
 then we have a part section and in this part we have and True/False section that we are able to control with a boolean key 
 
 when it is true we have some delay ( because of our Module Time Responce )  
 
 and we will send a "A" to the micro ( this command is determined for getting data from micro and also we have the other Visa Write to   control our relay with LABVIEW we can send 0,1 to the micro to turn ON/OFF our relay and also we have decimal indicator to show relay parameter as decimal integer 
 
 ![](https://github.com/mohammadst99/IOT_Arduino_Labview/blob/main/Labview%20Images/3.png)
 
 
 then you can see the other True/False section that you can adjust this part with START key in the tab 1
 ![](https://github.com/mohammadst99/IOT_Arduino_Labview/blob/main/Labview%20Images/6.png)
 
 
in this part we have to separate our data since we get our data from micro like this ( d25,t20,s40,p300 ) and 'd' is for distance 't' for temp 's' for humadity , 'p' for light so we have to split our data every where there is (',') and put them to the array se we use spreadsheet string to Array 

![](https://github.com/mohammadst99/IOT_Arduino_Labview/blob/main/Labview%20Images/7.png)

in the indicator part we have to get each data for each part separately for example we have to get (t20) for temp , (s30) for humadity ,(d20) for distance and  (p300) for the light and then we get the integer part to show with some Graphicy indicator
 
 ![](https://github.com/mohammadst99/IOT_Arduino_Labview/blob/main/Labview%20Images/8.png)
 
 
 
 
