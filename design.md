# Pre-Compilation Game Obfuscator

## Design Choices

**Encoding**

This project uses a simple xor encoding to disguise the varriables used in the game.  We chose to uses xor because it is simple to impliment and it is a two way function.
The encoding and decoding is handled by two separate functions as well as a parser and a function to re-assemble the values for each varriable.  We decided that storing
the variables as one large string would further obfuscate the game varriables from attackers.

**Saving to a file**

We also decided to store all of the varriables as an encoded string to a file.  This could be used as a backup or validation for the varriables at any time.  A separate file
is also created containing the hash of the file to be used as a validation before trusting the contents of the file.  Our program uses the c++ std::hash function with the file input as a key.  This provides a mildly secure file validation.  An existing file can also be loaded into the game as long as the hash is valid.  If the hash is not valid it is assumed that the file has been tampered with or corrupted and the game is reset to the it's default values.  These values
are then encoded and saved to the file and the file is once again hashed.  This method seemed to provide a simple yet semi-secure file and value authentication.

**General Design**

The program is broken into several different functions to maintain code readability.  The game is a monolithic program mainly due to poor communication and the relatively small nature of this project.  Some functions such as the encoding and decoding function are essentially identical due to the nature of the xor encoding providing a two way function.  It was decided to name them as separate functions to help the writer's trace what the program was doing at any given time.  It is likely that this will not provide much help or hindrance once the program is compiled into binary.  Most of the obfuscation was planned to be in the form of data encoding.
