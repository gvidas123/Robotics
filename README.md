This is a coursework i have done for the robotics modulle in Vilnius University

It it in the image of a game called hole in the wall.
a wall drops down and your pixel has to dodge them.
It has been done using arduino UNO R3, a few push buttons, some wires, a led for debugging purposes, resistors, and finaly an 8x8 led screen 
A few libraries Have been used:
EEPROM , Adafruit_GFX, Max72xxPanel, SPI.
EEprom is used for saving information between games. 
adafruit_GFX, SPI and MAX72xxPanel is used to control the led sccreen.

The buttons control the dirrection the pixel at the bottome moves(player).
the led is for debuggging purposes to know that the buttoons work as intended.
everything else is just wiring so the screen works as intended.
The code is in Robootics.ino file

in the image button_and_debug_led_wiring is shows how to wire the buttons and the led
