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


# Wiring diagram

![wiring of the worklight](https://user-images.githubusercontent.com/96006405/146410564-97dff615-c898-4bcc-9aad-548d0920435c.JPG)

# 3D printed case



