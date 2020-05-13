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

No installation is explicitly needed as the repository already contains an game.exe for running the program. Simply copy
the executable into the directory of your choice, open a cmd window in that directory and run the file with the command
`start game.exe`. If you wish to run the program in operating system other than windows you will need to ensure you have
an appropriate compiler for C++.

## Use

![Image of program startup](www.github.com/brentpearce/obviousGameObfuscator/resources/gameSetup.png "Game at startup")
The program when run will initialize the characters stats and display them to the console window (as shown in the image
above). The game will then wait for a keyboard press and then attempt to check if the encoded parameters have been
changed. If the program detects the parameters have been changed while the program is running, then the program will
display a warning (as shown below) and overwrite them with default values.

[Insert image of warning message here]