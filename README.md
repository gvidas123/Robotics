This is a coursework i have done for the robotics modulle in Vilnius University

It it in the image of a game called hole in the wall.
a wall drops down and your pixel has to dodge them.
It has been done using arduino UNO R3, a few push buttons, some wires, a led for debugging purposes, resistors, and finaly an 8x8 led screen 
A few libraries Have been used:
EEPROM , Adafruit_GFX, Max72xxPanel, SPI.
EEprom is used for saving information between games. 
adafruit_GFX, SPI and MAX72xxPanel is used to control the led sccreen.

The buttons control the dirrection the pixel at the bottom moves(player).

![image](https://github.com/gvidas123/Robotics/assets/93709395/df28a815-d782-4cf2-94f8-216182aecba8)

the led is for debuggging purposes to know that the buttoons work as intended.
everything else is just wiring so the screen works as intended.
The code is in Robootics.ino file

In the image: button_and_debug_led_wiring is shows how to wire the buttons and the led.
the buttons are connected to the third and fifth pin of the arduino board. they are also connected to power and ground through a resistor.
the buttons allow the player to move left and right with the code of line 56 to 63.

The led is connected to the ninth pin and is toggled on and off by both buttons wich allowws me to see if the buttons are wired properly.
This is done using code from the 61 line to light up the pin and code 64 to 69 to change its states.

and finally the led board 8x8 its also connected to the ground with a resistor and has power just like the buttons,
but it also has 3 diffrent wires going to arduino its connected to 10 11 and 13 pin.

Now how the game works: lines 81 to 95 make the set pixels drop down at the speed of the delay witch at the end of the void loop.
lines 100 to 106 reset the raindrops and make them random from wave 2 onwards.
96 to 110 checks if the game has ended and draws a W or L depeending if won or not on the screen if it has The L is shown in the image of: lose screen.
112 checks if the pixel alighn with the player pixel and if the wave has ended or not.
123 to 133 checks if the wave has ended and sets random wall. it also lowers the delay so it would be harder to react in time.
and finally the 134 line is the speed at witch the game is played.


