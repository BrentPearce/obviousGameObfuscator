#include <iostream>
#include <string>

using namespace std;

string* setUpGeme();

void encode(string &toEncode);
void decode(string &toEncode);

int main(){


  //int startingGold = 10, intell = 75, attack = 50, defense = 50, agility = 50;   

  //float health = 100.0, staminia = 99.9;



  //string *name = setUpGeme();  

  //encode somehow and save to a file..
  string s;
  cout << "Enter a string\n";
  cin >> s; 
  cout << s << endl;
  encode(s);
  cout << s << endl;
  cout << " " << endl;
  decode(s);
  cout << s << endl;

  return 0;
}

  string* setUpGeme(){

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

  string *character = new string[2];
  
  character[0] = name;
  character[1] = characterClass;

  return character;

}

//thinking this could maybe be called inside a funtion backupToFIle 
// or something...
void encode(string &toEncode){
  // key for xor and 
  const char XOR_KEY[4] = "~42";
      //do we want to add some indirection using pointers?

  // start by xor with the key
  for (int i = 0; i <toEncode.length(); i++)
  {
    //alternate between the first two chars 
    char k = XOR_KEY[i%3];
    if(k != toEncode[i] && toEncode[i] != 0){
      //use the current key to conditionally xor the string
      toEncode[i] = toEncode[i] ^ k;
    }
  }
}

void decode(string &toDecode){

  //Constants needed for decoding
  const char XOR_KEY[4] = "~42";

   for (int i = 0; i < toDecode.length(); i++) {
       //get current key
        char k = XOR_KEY[i%3];
        if (toDecode[i] != 0 && toDecode[i] != k)
        {
          toDecode[i] = toDecode[i] ^ k;
        }
    
  }
  
  
}
