#Attack and Analysis

For some reason the analysis performed by IDA Pro didn't allow us to find the function main. As we must begin looking 
somewhere else. So, to begin the analysis we can look the output of the program when it is run. We see that it prints 
several string such as "You have 10 gold coins.". As an educated guess someone hacking this could probably infer that 
in these strings the numbers are likely the game parameters. As such we can search for an initial substring such as 
"gold coins". Sure enough examining the strings window in IDA Pro we see that the string gold coins, and several 
others are present. 

![List of strings](https://github.com/BrentPearce/obviousGameObfuscator/blob/master/resources/strings.png)

Following the string "gold coins." we find it is eventually used in at offset sub 402914+5426. So this seem like a
natural place to examine. 

Looking around this location, specifically looking up from there, we see the following strings: "saveState", "saveHash"
and "hashString". These are all located at about offset 407BD4. Searching further we see other things but nothing
isolated in a subroutine for easier analysis.

Stepping back we can consider that the program creates two files one called gameState and the other called
gameState.hash. These are likely where the game parameters are stored durring and after runtime. Examining the contents
of these files(shown below) we see that there must some sort of encoding and hashing.

![gameData contents](https://github.com/BrentPearce/obviousGameObfuscator/blob/master/resources/gameDataContents.png)

![gameData hash](https://github.com/BrentPearce/obviousGameObfuscator/blob/master/resources/gameData.hashCat.png)

With this in mind we can starting think about the encoding scheme, and that the contents of gameData must be hashed 
somehow. Looking at the strings window we don't see any telltale 64(or 32) length string that could be used for a 64
(or 32 bit) encoding. So some other encoding scheme must be used. Additionally, looking at the imports we don't see any
large cryptographic hashing functions being imported. While this doesn't preclude dynamic or runtime linking the fact,
there is still a fairly large list of imports suggests that dynamic linking isn't used.

It's not unlikely, that either by sheer luck or trial and error, or with an educated guess, a hacker might look for an
XOR encoding. Searching for an XOR opcode across the entire disassembly we see two offsets IDA Pro has kindly named
"XOR_KEY" (perhaps from clues from the symbol table) located close to each other.

![XOR KEY offsets](https://github.com/BrentPearce/obviousGameObfuscator/blob/master/resources/XOR_KEY_offsets.png)

Examining the first of these two offsets located at offset 405FC0 we see that just after it there are several 
statements moving data around. However at offset 40606B we see a XOR inside loop, likely a for loop. As such if an XOR,
encoding were being used(which seems highly likely) this would act to further confirm our suspicion, especially as the 
authors of PMA describe an XOR in a loop as being a red flag for XOR encoding(see PMA page 274-276).

![Loop with XOR](https://github.com/BrentPearce/obviousGameObfuscator/blob/master/resources/loopXOR.png)

