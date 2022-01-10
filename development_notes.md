# LED worklight

Making of a 10 W LED worklight which is connectable to a 12 V Biltema cordless drill battery. Dimmer, low battery LED indicator, and overdischarge protection were implemented.
This project was done as a part of Principles of repurposing of electronics course at University of Oulu.
![20211219_162441-COLLAGE](https://user-images.githubusercontent.com/96006405/146678409-bee5d322-306a-45b3-b3f2-4c59b65f59d4.jpg)


# Parts used

-10 W COB LED

-12 V 1.3 Ah cordless drill battery (Biltema)

-5A DC-DC Step Down Buck Converter Module with current limiter

-old USB car charger

-old computer processor cooling element

-Wemos D1 mini microcontroller (https://www.ebay.de/itm/255283312826?_trkparms=amclksrc%3DITM%26aid%3D1110006%26algo%3DHOMESPLICE.SIM%26ao%3D1%26asc%3D20200818143132%26meid%3D4853776e228643338ebd92fc595ebb65%26pid%3D101198%26rk%3D3%26rkt%3D12%26sd%3D254535886946%26itm%3D255283312826%26pmt%3D1%26noa%3D0%26pg%3D2047675%26algv%3DSimplAMLCvipPairwiseWebWithBBEV2bDemotion&_trksid=p2047675.c101198.m1985&amdata=cksum%3A2552833128264853776e228643338ebd92fc595ebb65%7Cenc%3AAQAGAAACAHTZRVZxXf4Tb1xHMcbylES3PjGq2nBVndnQdV%252BMTptVVLbvJdLTpaGJlVpeqQIjcBqPzi9upLpAY7dV6PFLJzUW8RndcMKNPJpEU5zBVfBycvWYZHZ61nvPHIiipXhBXVPCAG0k8YsDpkWU%252B6TK3b7FeJuNbmmi6QVIe4gl73qXzAhb8H%252BMPmhmOsGCOagJXGRpTeDf9%252BeKsd1SZtNf%252FcfhP63xr%252BPhDVLzzXLjNdZH8mH6z4QLuh7dho5wX4nN1G15PiUYs0DiRnWR6tRTkO1cD2tU2kOCOMiYdveywKmwRG3s8MPPtftseH9kdJEcNyfZd9yclG6AqAGdEcByvjN%252FF8DuFJjJkKaKThuZsfgapmjpJ1XdJzfYbum8xLpTHdY8BV9HiEcw%252FYUwwFeJCrJxhPPJbi1HG6HlSQBhzM0%252BmN3zT4s8kidGqS%252B6k1Cy6RifyDNs%252FF9hlyx1TtdcLZoPDI1veU3tKOBGZJCy9zJUNCJeprOhF8lKYe7U3yHsO8EqEECCyYGm9B4H9zTXfd8PvcEtLQMDdugwL1dlOIPZZqZanbWICZUqLNWvq9HIGUmX23M%252BADwIgu3izBU5uJh%252Bs7hE%252F1aXhwQ%252Brg%252F9%252BQ3DL72vhgvi8gMt5pyD7mih%252BIdejWjA%252BJ9L74s%252BUkoC5RShjZKIwPqPzPkwyDMzdnK%252B%7Campid%3APL_CLK%7Cclp%3A2047675)

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
The arduino program can be found here: https://github.com/markuschr/worklight/blob/a1ebac3b1dbc1f40e40365d86252e261739fb898/worklight.ino.

The operation is pretty simple: 

First it measures the value from analog input A0 pin and counts an average from last 4 values. 

Then the averaged value is compared to two thresholds, the upper threshold is when the indication LED turns on and the lower threshold is when the pin controlling the MOSFET is put on low which switches off the LED driver input.  Otherwise the the pin controlling the MOSFET is high and the indication LED is low.

When using the cordless drill with the battery the power shuts off when the battery reaches 10.8 V. By using the WiFi connectivity of Wemos D1 mini, the corresponding value for 10.8 V could be measured. The arduino program has lines for connecting to Wifi and writing values to Thingspeak channel. This can be enabled by uncommenting the lines of code and inserting the credentials. The delay must be also increased to 15 seconds because Thingspeak does not accept faster rate for incoming data.

# Case

All the electronics were fitted to 3D printed body and screwed inside to the 3D printed case (roughly 70 mm x 70 mm x 70 mm) and the LED with the cooling element on top of it with a hinge. Connection to the battery was made with push-on Abiko connectors which go through the bottom of the case. Stl files can be found from this repository.

![koko design](https://user-images.githubusercontent.com/96006405/148766713-b4479599-b809-421e-beea-dee6de8ce838.JPG)
![sisus](https://user-images.githubusercontent.com/96006405/148767554-4f8eacb6-fba6-4b80-b81a-4166bcb1296d.JPG)
![holderi](https://user-images.githubusercontent.com/96006405/148767678-99968df3-516e-408f-9fb4-d628923e6144.JPG)
![holderi2](https://user-images.githubusercontent.com/96006405/148767717-caf4c77c-4de6-4272-b9e7-639cdf3e4235.JPG)



# Problems and possible improvements for future revisions
The overdischarge protection does not switch the microcontroller's power off and I did not found a workaround for this. One partial solution could have been to put the microcontroller to deepsleep, but I could not get this to work because when entering deepsleep the pin controlling the MOSFET switch did not stay low and the LED would light up again. Maybe using a different pin would have fixed the problem.

The device could also work as a powerbank when a car charger which has two usb outputs is used. The other one could provide 5 V to the microcontroller and the other port could be inserted to the case for charging a phone or etc.

Remote control of the LED could also be possible to implement with WiFi or even GSM if an old mobile phone is used.
Also a screen could be added to present brightness and batterylevel.



