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

In the image: button_and_debug_led_wiring is shows how to wire the buttons and the led.
the buttons are connected to the third and fifth pin of the arduino board. they are also connected to power and ground through a resistor.
the buttons allow the player to move left and right with the code of line 56 to 63.

The led is connected to the ninth pin and is toggled on and of by both buttons wich allowws me to see if the buttons are wired properly.
This is done using code from the 47 line to light up the pin and code 50 to 55 to change its states.

and finally the led board 8x8 
