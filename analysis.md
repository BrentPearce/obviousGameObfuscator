#Attack and Analysis

As a disclaimer this portion of the assignment was really difficult for me (Brent). In my attempts to have a working PE
(compiling using gcc's g++ compiler produced strange results with imports such as CYGWIN). Similarly eventually,
installing Visual Studio and compiling on a Machine with windows 10 produced more normal results, at least so it 
seemed. However in reality, this apparently made the resulting PE file depend on dlls not installed in the Windows 8
analysis machines created for the class. This meant I could only perform static analysis.As such I was unable to 
reverse engineer the key for the XOR encoding, or spoof our software. Additionally, IDA Pro was unable to display the 
assembly in a graph mode and displayed an error message that the graph had over 1000 nodes(message shown below).


![Too many nodes](https://github.com/BrentPearce/obviousGameObfuscator/blob/master/resources/IDA_Pro_graph_error.png)

Additionally, the analysis performed by IDA Pro didn't allow us to find the function main. As such, we must begin looking 
somewhere else. So, to begin the analysis we can look at the output of the program when it is run. We see that it prints 
several string such as "You have 10 gold coins.". As an educated guess someone hacking this could probably infer that 
in these strings the numbers are likely the game parameters. As such we can search for an initial substring such as 
"gold coins". Sure enough examining the strings window in IDA Pro we see that the string gold coins, and several 
others are present. 

![List of strings](https://github.com/BrentPearce/obviousGameObfuscator/blob/master/resources/strings.png)

Following the string "gold coins." we find it is eventually used in at offset sub 402914+5426. So this seem like a
natural place to examine. 

Looking around this location, specifically looking up from there, we see the following strings: "saveState", "saveHash"
and "hashString". These are all located at about offset 407BD4. Searching further we see other strings but nothing
especially helpful.

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

Looking more closely we can also see the value 3 is being moved into a register immediately before and integer division
operation is called. This corresponds to the modulo 3 operation at inside the for loop. Also, we can see two comparison
and jump statements inside the loop that each skip over the XOR operation which corresponds to the null preserving
portion of our encode/decode functions.

Unfortunately, because of the strange way IDA Pro analyzed the file it also becomes very difficult to determine which
functions call the encode to try and see in greater detail what is being passed to encode and decode. As another result
of this behavior it nearly impossible to look at the larger structure of main.

From here a more experienced reverse engineer might perform a dynamic analysis and try to pause the execution of the 
program so that the unencrypted game parameters could be viewed and copied for use in manual decoding. However given
the above listed complications I was unable to do that or perform any further analysis. 
