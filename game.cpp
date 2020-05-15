#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <typeinfo>
#include <regex>

using namespace std;


void encode(string &toEncode);
void decode(string &toEncode);
void saveToFile(string &save);
string readFromFile();
int validateFile();
void parser(string str);
int* arrayHandler(string str);
vector<string> extractValues(const string& input);

size_t fileHash;

int main(){
  bool isStatFileThere = false;
  string *character = new string[2];
  character[0] = "Jordan";
  character[1] = "Knight";
  int gold,  intell, attack, defense, agility, swordAttack, swordDefense; 
  float health, stamina;
  string dataFromFIle;
  

  if(true)// change to !isStatFileThere eventually once check is in place
  {
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
    stamina = 99.9; 
    cout << "Your stamina is " << stamina << ".\n";
    

    vector<int> acquiredItemsStrength;
   acquiredItemsStrength.push_back(1);
   acquiredItemsStrength.push_back(2);
   acquiredItemsStrength.push_back(9);
   acquiredItemsStrength.push_back(52);
   acquiredItemsStrength.push_back(47);
   acquiredItemsStrength.push_back(777);

  cout<<"Made it here";
    //encode the values and then write them to a file using saveToFile()

      //Store the values in a string

 

    //Store the values

    string savedData;
    savedData = "g" + to_string(gold) + "i" + to_string(intell);
    savedData = savedData + "a" + to_string(attack) + "d" + to_string(defense);
    savedData = savedData + "y" + to_string(agility) + "s" + to_string(swordAttack);
    savedData = savedData + "e" + to_string(swordDefense) + "h" + to_string(health);
    savedData = savedData + "t" + to_string(stamina);

    savedData = savedData + "VV";
    for (int i = 0; i < acquiredItemsStrength.size(); i++)
    {
      savedData = savedData +  to_string(acquiredItemsStrength[i]) + ", ";
    }
        
    encode(savedData);
    cout << "Here is the encoded data: " << savedData;
    saveToFile(savedData);

    /*
    cout << "The game is now saved\n";
    
    //TODO: Add code to pause for modification.
    cout << "The game is now paused press a key to continue\n";
    */
    //TODO: Get string from file

     vector<string> extractedVariables;
    //TODO: change to string pulled from file.

     extractedVariables = extractValues(savedData);

    // for (int i = 0; i < extractedVariables.size(); i++)
    // {
    //   cout << "Here is the string:" << extractedVariables[i]<<endl;
    // }
    
    



    int goldDecoded,  intellDecoded, attackDecoded, defenseDecoded, agilityDecoded, swordAttackDecoded, swordDefenseDecoded; 
    float healthDecoded, staminaDecoded;
    vector<int> aquiredItemsStrengthDecoded;




    gold= stoi(extractedVariables[1]);
    intell= stoi(extractedVariables[2]); 
    attack= stoi(extractedVariables[3]);
    defense= stoi(extractedVariables[4]); 
    agility= stoi(extractedVariables[5]);
    swordAttack= stoi(extractedVariables[6]); 
    swordDefense= stoi(extractedVariables[7]); 
    health= stof(extractedVariables[8]);
    stamina= stof(extractedVariables[9]);
    extractedVariables[10]; //HERE IS THE VECTOR READY TO BE PARSED
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
  //cin >> s; 
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

vector<string> extractValues(const string& input){
  smatch values;
  regex rgx("g[-+]?([0-9]*[.][0-9]+|[0-9]+)i[-+]?([0-9]*[.][0-9]+|[0-9]+)a[-+]?([0-9]*[.][0-9]+|[0-9]+)d[-+]?([0-9]*[.][0-9]+|[0-9]+)y[-+]?([0-9]*[.][0-9]+|[0-9]+)s[-+]?([0-9]*[.][0-9]+|[0-9]+)e[-+]?([0-9]*[.][0-9]+|[0-9]+)h[-+]?([0-9]*[.][0-9]+|[0-9]+)t[-+]?([0-9]*[.][0-9]+|[0-9]+)VV(.*)");

  regex_search(input.begin(), input.end(), values, rgx);
  vector<string> parameters;
  for(int i =0; i< values.size(); i++){
    parameters.push_back(values.str(i));
  }
  return parameters;
}

//thinking this could maybe be called inside a function backupToFIle 
// or something...
void encode(string &toEncode){
  // key for xor 
  const char XOR_KEY[4] = "~42";

  // start by xor with the key
  for (int i = 0; i <toEncode.length(); i++)
  {
    //alternate between the first two chars 
    char k = XOR_KEY[i%3];
    
    if(k != toEncode[i] && toEncode[i] != 0){
      //use the current key to conditionally xor the current char in the string
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

  //TODO: rearange the function to hash earlier and then save the hash in the file
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

//TODO: Change so that it returns a string array so we can get the hash too.
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



void parser(string str) {
    int len = str.length() - 1;
    int ident = stoi(str.substr(0, 1));
    string newstring = str.substr(1, len);
    int newInt = 0;
    float newFloat = 0.0;
    int* newArr;
    switch (ident) {
        case 1: newInt = stoi(newstring);
        case 2: newFloat = stof(newstring);
        case 3: newArr = arrayHandler(newstring);
        case 4: NULL;
    }
}

int* arrayHandler(string str) {
    int len = str.length();
    static int* arr = new int[len];
    for (int k = 0; k < len; ++k) {
        arr[k] = 0;
    }
    int i, j = 0;
    for (i = 0; str[i] != '\0'; ++i) {
        if (str[i] == ',')
            continue;
        if (str[i] == ' ') {
            j++;
        }
        else {
            arr[j] = arr[j] * 10 + (str[i] - 48);
        }
    }
    cout << "arr[] = ";
    for (i = 0; i <= j; i++) {
        cout << arr[i] << " ";
    }
    return arr;
}

