#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <typeinfo>
#include <sstream>
#include <regex>

using namespace std;


void encode(string &toEncode);
void decode(string &toEncode);
void saveToFile(string &save);
string readFromFile();
int validateFile();
void parser(string str);
int* arrayHandler(string str);
vector<int> vectorHandler(string str);
vector<string> extractValues(const string& input);
bool checkFile();

size_t fileHash;

int main(){
  bool isStatFileThere = false;
  string *character = new string[2];
  character[0] = "Jordan";
  character[1] = "Knight";
  int gold,  intell, attack, defense, agility, swordAttack, swordDefense;
  float health, stamina;
  string dataFromFIle;

  //Begin initial file load and check if one exists, else initialize the game
  isStatFileThere = checkFile();


  if(!isStatFileThere)
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
    saveToFile(savedData);
    cout << "The game is now saved\n";

    //TODO: Add code to pause for modification.
    cout << "The game is now paused press a key to continue\n";
    int c = getchar();
    //TODO: Get string from file

     vector<string> extractedVariables;
    //TODO: change to string pulled from file.

     extractedVariables = extractValues(savedData);


    int goldDecoded,  intellDecoded, attackDecoded, defenseDecoded, agilityDecoded, swordAttackDecoded, swordDefenseDecoded;
    float healthDecoded, staminaDecoded;
    vector<int> aquiredItemsStrengthDecoded;




/*
    gold= stoi(extractedVariables[1]);
    intell= stoi(extractedVariables[2]);
    attack= stoi(extractedVariables[3]);
    defense= stoi(extractedVariables[4]);
    agility= stoi(extractedVariables[5]);
    swordAttack= stoi(extractedVariables[6]);
    swordDefense= stoi(extractedVariables[7]);
    health= stof(extractedVariables[8]);
    stamina= stof(extractedVariables[9]);
*/
    extractedVariables[10]; //HERE IS THE VECTOR READY TO BE PARSED
  }
  else
  {
      //File has already been validated successfuly
      //read the values from the file and display them
    vector<string> extractedVariables;
    dataFromFIle = readFromFile();
    encode(dataFromFIle);
    extractedVariables = extractValues(dataFromFIle);
    


    int goldDecoded,  intellDecoded, attackDecoded, defenseDecoded, agilityDecoded, swordAttackDecoded, swordDefenseDecoded;
    float healthDecoded, staminaDecoded;
    vector<int> aquiredItemsStrengthDecoded;

    gold= stoi(extractedVariables[1]);
    cout << "Gold is " << gold << ".\n";
    intell= stoi(extractedVariables[2]);
    cout << "Intelligence is " << intell << ".\n";
    attack= stoi(extractedVariables[3]);
    cout << "Attack is " << attack << ".\n";
    defense= stoi(extractedVariables[4]);
    cout << "Defense is " << defense << ".\n";
    agility= stoi(extractedVariables[5]);
    cout << "Agility is " << agility << ".\n";
    swordAttack= stoi(extractedVariables[6]);
    cout << "Sword attack is " << swordAttack << ".\n";
    swordDefense= stoi(extractedVariables[7]);
    cout << "Sword defense is " << swordDefense << ".\n";
    health= stof(extractedVariables[8]);
    std::cout << std::fixed << std::setprecision(1);
    
    cout << "Health is " << health << ".\n";
    stamina= stof(extractedVariables[9]);
    cout << "Stamina is " << stamina << ".\n";
    extractedVariables[10]; //HERE IS THE VECTOR READY TO BE PARSED
    return 0;
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

    cout << "Game over"<<endl;
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

    hash<string> thisFileHash;
    ofstream saveState;
    ofstream saveHash;
    saveState.open ("gameData");
    //cout << "Saving to file: " << save << endl;  //Uncomment for debugging
    saveState << save;
    saveState.close();
    fileHash = thisFileHash(save);

    saveHash.open("gameData.hash");
    saveHash << fileHash;
    saveHash.close();
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

            string *character = new string[2];
            character[0] = "Jordan";
            character[1] = "Knight";
            int gold,  intell, attack, defense, agility, swordAttack, swordDefense;
            float health, stamina;
            gold = 10;
            intell = 75;
            attack = defense = agility = 50;
            swordAttack = 10;
            swordDefense = 5;
            health = 100.0;
            std::cout << std::fixed << std::setprecision(1);
            stamina = 99.9;
            vector<int> acquiredItemsStrength;
            acquiredItemsStrength.push_back(1);
            acquiredItemsStrength.push_back(2);
            acquiredItemsStrength.push_back(9);
            acquiredItemsStrength.push_back(52);
            acquiredItemsStrength.push_back(47);
            acquiredItemsStrength.push_back(777);


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
            saveToFile(savedData);
            cout << "The game is now reset\n";

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
    vector<int> newVec;
    int* newArr;
    switch (ident) {
        case 1: newInt = stoi(newstring);
            break;
        case 2: newFloat = stof(newstring);
            break;
        case 3: newVec = vectorHandler(newstring);
            break;
        case 4: newArr = arrayHandler(newstring);
            break;
        default: break;
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
    /*
    cout << "arr[] = ";
    for (i = 0; i <= j; i++) {
        cout << arr[i] << " ";
    }
    */
    return arr;
}

vector<int> vectorHandler(string str) {
    vector<int> vec;
    stringstream ssr(str);
    int num;

    while (ssr >> num) {
        vec.push_back(num);
    }
    /*
    for (auto i : vec) {
        cout << i << "\n";
    }
    */
    return vec;
}

//This will attempt to open the two required save files
// True if the files are available and valid
// False if files are not available or are invalid
bool checkFile() {

  ifstream saveState ("gameData");
  ifstream saveHash ("gameData.hash");
  string hashString;
  int validation;
    if (saveState.is_open() && saveHash.is_open()) {
        cout<<"Found save state and hash"<<endl;
        getline(saveHash,hashString);
        istringstream iss(hashString);
        iss >> fileHash;
        saveState.close();
        saveHash.close();
        cout<<fileHash<<endl;
        validation = validateFile();
        if (validation == 0) {return true;}
        else {return false;}
    }
    else {
        cout << "Unable to find valid save state."<<endl;
        return false;
    }

}
