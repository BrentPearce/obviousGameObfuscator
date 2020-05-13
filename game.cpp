#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


using namespace std;


void encode(string &toEncode);
void decode(string &toEncode);
void saveToFile(string &save);
string readFromFile();
int validateFile();

size_t fileHash;

int main(){
  bool isStatFileThere = false;
  string *character = new string[2];
  character[0] = "Jordan";
  character[1] = "Knight";
  int gold,  intell, attack, defense, agility, swordAttack, swordDefense; 
  float health, staminia;
 

  if(true)// change to !isStatFileThere eventually once check is in place
  {
    cout << "****************************************";
    cout << "****************************************\n";
    cout << "Your name is Jordan and you are a Knight.\n";
    gold = 10;
    cout << "You have " << gold <<  " gold coins. \n";
    intell = 75;
    cout << "Your intelligence is " << intell << ".\n";
    attack = defense = agility = 50;
    cout << "Your attack is " << attack << ".\n";
    cout << "Your defense is " << defense << ".\n";
    cout << "Your agility is " << agility << ".\n";
    swordAttack = 10; 
    cout << "Your sword has an attack boost of " << swordAttack << ".\n";
    swordDefense = 5;
    cout << "Your sword has an defense boost of " << swordDefense << ".\n";
    health = 100.0;
    std::cout << std::fixed << std::setprecision(1);
    cout << "Your health is " << health << ".\n";
    staminia = 99.9; 
    cout << "Your stamina is " << staminia << ".\n";

    //encode the values and then write them to a file using saveToFile()
    cout << "Saving the game. \n";

     cout << "****************************************";
    cout << "****************************************\n";   
  }
  else
  {

    // see if the file has been tampered with

    // if yes 
      //tell the person they cheated and the that the values are being reset 
      //then reset and display the values.

    // if no 
      //read the values from the file and display them 

  }


    //Testing for the validate and file read/write functions
/*    //-----------------------------------------------------
    string test = "test"; 
    saveToFile(test);
    cout << fileHash << endl;
    int validation = validateFile();
    int c = getchar();  //This will pause the program, at least on linux.  During this time you may modify the data file to test the validate function
    validation =  validateFile();
    string lastTest = readFromFile();
    cout << lastTest << endl;
*/    //End Testing ----------------------------------------

  /* Uncomment for debuging/testing
  string s;
  cout << "Enter a string\n";
  cin >> s; 
  cout << s << endl;
  */

  /* Uncomment to test encoding and decoding
  encode(s);
  cout << s << endl;
  decode(s);
  cout << s << endl;
  */

  
  return 0;
}

//thinking this could maybe be called inside a funtion backupToFIle 
// or something...
void encode(string &toEncode){
  // key for xor 
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

void saveToFile(string &save){
//This function will take a string and save it to a file
//The file output will be hardcoded as gameData and will only write to the first line
//The global variable fileHash will also be set   
    hash<string> thisFileHash;
    ofstream saveState;
    saveState.open ("gameData");
    //cout << "Saving to file: " << save << endl;  //Uncomment for debugging
    saveState << save;
    saveState.close();
    fileHash = thisFileHash(save);
}

string readFromFile() {
//This function will read the contents of a file and return the string
//The file name is hardcoded as gameData and should only have anything written to the first line
    string data;
    ifstream saveState ("gameData");
    if (saveState.is_open()) {
        getline (saveState, data) ;
       // cout << "The file contains: "<< data  << endl;  //Uncomment for debugging
        saveState.close();
        return data;
    }
    else {
        cout << "Unable to open file"; 
        return "ERROR";
    }
}


int validateFile() {
//Returns 0 if the file is valid
//Returns 1 if the file is not valid an will reset the file to the default values
    string data;
    hash<string> thisFileHash;
    ifstream saveState ("gameData");

    if (saveState.is_open()) {
        getline (saveState, data);
        if (fileHash != thisFileHash(data)) {
            //Restore defaults
            cout << "File is invalid.  Restoring Defaults." << endl;
            return 1;
        }
        else {
            cout << "File is valid" << endl;  //Uncomment for debugging
            return 0;
        }
    }
    else {
        cout << "Unable to verify file because the file could not be opened." << endl;
        return 1;
    }    
    return 2; //This should not be reached
}
