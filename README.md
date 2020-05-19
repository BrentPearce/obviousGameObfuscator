# Pre-Compilation Game Obfuscator

## Introduction

This project is an assignment for UWYO COSC Cyber Security Topics: Binary Analysis. The group members for this project
are Ryan Evans, Miles Golding, Todd Muller and Brent Pearce.

The project contains:

1. A pre-compilation obfuscation of 10 game parameters using an XOR cipher for encoding (use of the program can be found
in this README),
2. an write up of our design considerations and choices (can be found in design.md),
3. an attempt to crack the encoding and a write up of said attempt (contained in analysis.md),
4. a write up of reflections after the attempt to crack the encoding including possible further changes to improve the
security of the obfuscation (found in nop.md).  

## Requirements and Installation

To install the game simply clone the repository and use your favorite compiler to compile the the file game.cpp. This
file contains all the needed functions etc.

## Use

![Game at Startup](https://github.com/BrentPearce/obviousGameObfuscator/blob/master/resources/initialAndSave.png)

The program when run will initialize the characters stats and display them to the console window (as shown in the image
above). The game will then wait for a keyboard press and then attempt to check if the encoded parameters have been
changed. If the program detects the parameters have been changed while the program is running, then the program will
display a warning (as shown below) and overwrite them with default values.


![Runtime Tamper warning](https://github.com/BrentPearce/obviousGameObfuscator/blob/master/resources/runtimeTamper.png)

Additionally, once the game parameters have been encoded and saved the program can be closed. When the program is
reopened the program will read the values from the file and decode them and display the player's stats (as shown below).

![Decoded from file](https://github.com/BrentPearce/obviousGameObfuscator/blob/master/resources/loadedFromFile.png)

If the program detects the encoded values have been altered between closing and opening then the program will display a
warning message and reset the values as shown below.

Insert image of warning message and resetting values
![Loaded tampered file](https://github.com/BrentPearce/obviousGameObfuscator/blob/master/resources/loadTampered.png)
