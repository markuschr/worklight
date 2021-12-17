# LED worklight

Making of a 10 W LED worklight which is connectable to a 12 V Biltema cordless drill battery. Dimmer, low battery LED indicator, and overdischarge protection were implemented.
This project was done as a part of Principles of repurposing of electronics course at University of Oulu.

# Parts used

-10 W COB LED

-12 V 1.3 Ah cordless drill battery (Biltema)

-5A DC-DC Step Down Buck Converter Module with current limiter

-old USB car charger

-old computer processor cooling element

-Wemos D1 mini microcontroller

-IRLI530NPbF logic level MOSFET

-3mm red LED

-connection board

-on/off switch

-fuse

-10 kohm potentiometer 

-resistors: 11 kohm, 10 kohm, 3.32 kohm, 100 ohm 

-two Abiko push-on connectors

-wires, screws, glue

# Design procedure

First thing is to attach the LED to the heatsink. Holes can be drilled to the heatsink and then the LED can be secured in place with screws. Some thermal conducting paste can be apllied to the bottom of the LED. Then wires can be soldered to the positive and negative terminals, and connect the wires through multimeter to the buck converter module's output. The buck converter module works as the LED driver. The maximum current and voltage can be selected by rotating the screws in the trimmer potentiometers. The one closer to the output terminals is for the maximum current and the one closer to the input is for the voltage. Before connecting input terminals to 12 V the potentiometers screws should be rotated counter clockwise direction. After connecting the input to 12 V the output should be measured for current and voltage. That way both voltage and current can be set by rotating the potentiometer screws clockwise to max 240 mA and max 12 V.

For making the dimming option the potentiometer that controls the voltage must be removed from the module. By adding a bit of solder to the pins and pulling the potentiometer it comes off pretty easily. Then the trimmer potentiometer can be hot glued to the back of the 10 kohm potentiometer and two wires soldered to the pads on the module, leaving the middle one unconnected. The wires are soldered to the potentiometers along with 11 kohm resistor according to the wiring diagram which can be seen below. After making the connections the trimmer potentiometer screw can still be tuned so that we get the maximum brightness when the bigger potentiometer is rotated to the max.

Next the microcontroller and the regulator for powering it can be added. Any pcb from a car charger that takes 12 V input and outputs 5 V is fine for the regulator. The microcontroller is Wemos D1 mini and one analog input and two digital outputs are used. The analog input is used to measure the voltage of the battery. Analog input takes maximum voltage of 3.3 V so the voltage of 12 V need to be dropped down using two resistors. One digital output is connected to the MOSFET gate pin which controls the LED driver input. The other digital output pin is for the low battery indication LED. 

# Wiring diagram

![wiring of the worklight](https://user-images.githubusercontent.com/96006405/146410564-97dff615-c898-4bcc-9aad-548d0920435c.JPG)

# Arduino program
The arduino program can be found (HERE). 
The operation is pretty simple: 
First it measures the value from analog input A0 pin and counts an average from last 4 values. 
Then the averaged value is compared to two thresholds, the upper threshold is when the indication LED turns on and the lower threshold is when the pin controlling the MOSFET is put on low which switches off the LED driver input.  

# 3D printed case



