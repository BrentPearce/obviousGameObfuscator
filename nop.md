# Reflections and further actions

Some things that worked well were the obfuscation of the XOR key, and the hashing of the gameState file. By using
multiple XOR keys that were stored in a c string each individual key was essentially stored as a pointer and (as far as
I was aware) became transparent to static analysis. This could be used to store the number of keys(IE for the modulo
operation) as well as storing the game parameters themselves. Another advantage of using pointers to store the game
parameters (especially as a linked list) will be discussed later. Using the template hash from the standard library
also allowed us to keep our hashing function lightweight (leaning on built in functionality), without calling attention
to imported functions. 

Three ways our obfuscation could have been improved are the names of our variables, the way the game 
parameters were casted into a string and then concatenated into a single string and finally the loop used in the 
encoding and decoding functions. The first issue of our variable names could have been easily fixed before compiling. 
Additionally, with minor modifications, both of the later issues could have been solved using recursion. 

First, looking at the process of casting and concatenating the game parameters we see that each of these happen
sequentially and immediately before the savedData string is encoded, if someone reverse engineering the program was
able to successfully understand the bigger picture of main then the large block of code acting and every game parameter
would draw suspicion. Once analyzed the hacker would have a complete picture of how the game parameters are stored in
our savedData string, and would be immediately pointed to our encoded function. However, this could be remedied by
storing our game parameters in a linked list. This would allow our parameters to be recursively casted and 
concatenated. In essence that code block would have a much smaller footprint because of it's single entry point.

This same logic would apply to the encoding and decoding functions which rely on a loop to iterate through the string.
Meanwhile, a recursive function call is more easily overlooked. The encoding could be further obfuscated by breaking
the function into several smaller functions. For example, the first function could encode the first character in the 
string. This function would then call the next function which would find the length of the string(this could be further
hidden by casting the string to a c string and using a loop or recursion to find the length). After the length is
found, the rest could be encoded, possibly using indirect recursion. Additionally with a little more creativity the 
encode and decode could have different calling orders, such that they appear to be different but are actually
performing the same operation on each character in the string.
