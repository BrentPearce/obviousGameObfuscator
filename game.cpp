#include <iostream>
#include <string>

using namespace std;

void setUpGeme(string &name, string &characterClass);

void encode(string &toEncode);

int main(){

  string name, characterClass;

  int startingGold = 10, intell = 75, attack = 50, defense = 50, agility = 50;   

  float health = 100.0, staminia = 99.9;


  setUpGeme(name, characterClass);  

  //encode somehow and save to a file..
   



  return 0;
}

void setUpGeme(string &name, string &characterClass){

  string name;
  cout << "Enter name (string)" << endl;
  cin >> name;

  string characterClass;
  cout << "Enter character class" << endl;
  cin >> characterClass;

  cout << "Starting gold is: 100 " << endl;

  cout << "Intelligence is: 75" << endl;

  cout << "Attack is 50" << endl;

  cout << "Defense is 50" << endl;

  cout << "Agility is 50 " << endl;  

  cout << "Heatlth is 100.0" <<endl;

  cout << "Stamina is 99.9" << endl;
}

//thinking this could maybe be called inside a funtion backupToFIle 
// or something...
void encode(string &toEncode){
  // key for xor and array for number of bits to rotate
  const char key[3] = "42";
  const int rotate[4] = {1, 3, 5, 2};
  const int char_bits = 8; //asuming using an ascii encoding.
      //do we want to add some indirection using pointers?

  // start by xor with the key
  for (int i = 0; i <toEncode.length(); i++)
  {
    //alternate between the first two chars 
    char k = key[i%2];
    if(k != toEncode[i]){
      //use the current key to conditionally xor the string
      toEncode[i] = toEncode[i] ^ k; 
    }
    //and then use the rotate and char_bits to bit rotate the char
    //(n << d)|(n >> (CHAR_BITS - d)); 
    //see https://www.geeksforgeeks.org/rotate-bits-of-an-integer/
   
  }
  
  




}
