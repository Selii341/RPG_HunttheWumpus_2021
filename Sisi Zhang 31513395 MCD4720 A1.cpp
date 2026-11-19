/*
* Name:                        Sisi Zhang A1
* Student Name :               Sisi Zhang
* Student ID:                  31513395
* 
* Tutorial Teacher:            Robert Smith
* FileName:                    MCD4720  ASSIGENMENT1
* 
* Date Created:                18/11/2020
* Data Updated:
* 
* Version:                     0.1
* 
* Description:                 Assignment 1 of MCD4720 T3 , 2020 Fundamentals of c++."RPG Generator"
*                              The Amazing RPG Character Generator.
*/



#include <iostream>
#include <string>
#include <fstream>
#include<time.h>
#include <vector>
#include<sstream>


using namespace std;
void runmenu();
void displayText();
void createLists();
void generateCharacter();
ifstream readFile;
vector<string> Data1; fstream File1; string obj1;   
vector<string> Data2; fstream File2; string obj2;
vector<string> Data3; fstream File3; string obj3;
vector<string> VectorData;  string FileData;//To creat the  new vector
vector<string>::iterator iter;

string name;//define characters
string result;//the  reslut from option 4 to 5
void saveData();
void loadData(); 



int main() {
        
        runmenu();  //Display the runmenu();
       ifstream readFile;

     system("pause");
         return 0;
    }
//task 1
void runmenu()
{
    bool continueMenu = true;//check the menu and define it is true
    while (continueMenu) {

        cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\tThe Amazing RPG Character Generator \n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[ 1 ] End Testing the Program\n";
        cout << "[ 2 ] Display ¡°About¡± Information\n";
        cout << "[ 3 ] Read and store data from files\n";
        cout << "[ 4 ] Generate a random Character \n";
        cout << "[ 5 ] Save a Character to file\n";
        cout << "[ 6 ] Load saved Characters from file \n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        //creat a variable of  option from the user
        int option;
        cout << "which option would you like (1-6) : ";
        cin >> option;                                        //output

        //Use switch to jump to each function
        switch (option) {
        case 1://End Testing the Program
            continueMenu = false;
            cout << "Weclome to your next visit" << endl;
            break;

        case 2://Display ¡°About¡± Information
            displayText();
            break;

        case 3://Read and store data from files
            createLists();
            break;

        case 4://Generate a random Character
            generateCharacter();
            break;

        case 5://Save a Character to file
            saveData();
            break;
        case 6://Load saved Characters from file
            loadData();
            break;
        default:
            break;
        }
    }
}
//task 2 
void displayText() { //creat an ifstream obj.& use the readfile to open the actual file.
    ifstream readFile;
    readFile.open("RPGAbout.txt");
    string File_in;
    if (readFile.is_open()) {//test the file is open
        while (!readFile.eof()) {//read until end of file is reached
            getline(readFile,File_in);
            cout << File_in << endl;
        }
    }
}
 //task3       
void createLists()
{//read the  file //creat an ifstream obj.& use the file to open theactual.txt.
    ifstream readFile;
    vector<string> Data1; fstream File1; string obj1;   //load data from the file and save it in the string obj
    vector<string> Data2; fstream File2; string obj2;
    vector<string> Data3; fstream File3; string obj3;
    cout << "\nData loading from charAttributes.txt\n\n";
    File1.open("charTypes.txt");
    if (File1.is_open() == true) {//test the file is open
        while (!File1.eof()) {
            getline(File1, obj1);//read until end of file is reached
            Data1.push_back(obj1);//load the data from the string and store into collection (VECTOR)

        }
    }

    //read the second file//creat an ifstream obj.& use the file2 to open the charAttributes.txt.
    cout << "\nData loading from charAttributes.txt\n\n";

    File2.open("charAttributes.txt");

    if (File2.is_open() == true) {//test the file is open
        while (!File2.eof()) {
            getline(File2, obj2);//read until end of file is reached
            Data2.push_back(obj2); //load the data from the string and store into collection (VECTOR)
        }
    }

    //read the second file//creat an ifstream obj.& use the file3 to open the  charAttMins.txt.
    cout << "\nData loading from charAttMins.txt\n\n";

    File3.open("charAttMins.txt");

    if (File3.is_open() == true) {//test the file is open
        while (!File3.eof()) {
            getline(File3, obj3);//read until end of file is reached
            Data3.push_back(obj3); //load the data from the string and store into collection (VECTOR)  
        }
    }
    //creat new vector to store the variables for option 4 and 5
    
    readFile.open("savedCharacters.txt");
    string FileData;
    getline(readFile,FileData);
    
    readFile >> FileData;
    if (readFile.is_open() == true) {
        while (!readFile.eof()) {
            //Load the data from the string and store into collection 
            getline(readFile, FileData);
          VectorData.push_back(FileData);
        }
    
        }
       
    
}
 //task4  
    void generateCharacter() {
        //creat 6 chars. and choose them randomly
        cout << "  \n";
         int name;
        srand(time(NULL));//seed the random; 0-5=6
        name = rand() % 6;//creat 6 characters
        stringstream nn1, nn2, nn3, nn4, nn5, nn6;//string the name and use if to add into result
        nn1 << "\nWizard\n"; nn2 << "\nHealer\n"; nn3 << "\nThief\n"; nn4 << "\nRanger\n"; nn5 << "\nFighter\n"; nn6 << "\nBarbarian\n";
        string n0 = nn1.str(); string n1 = nn2.str(); string n2 = nn3.str(); string n3 = nn4.str(); string n4 = nn5.str(); string n5 = nn6.str();
        if (name == 0) {  result += n0;cout << "\nWizard\n"; }
        else if (name == 1) { result += n1; cout << "\nHealer\n"; }
        else if (name == 2) { result += n2; cout << "\nThief\n"; }
        else if (name == 3) { result += n3; cout << "\nRanger\n"; }
        else if (name == 4) { result += n4; cout << "\nFighter\n"; }
        else if (name == 5) { result += n5; ; cout << "\nBarbarian\n"; }
        else { cout << "\nthere is no other characters\n"; }
        
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"; 
        srand(time(NULL));//seed randoms
       int  a, b, c, d, e, f, g, h, i, j, k, l;
       stringstream ss1, ss2, ss3, ss4, ss5, ss6, ss7, ss8, ss9, ss10, ss11, ss12,r1,r2,r3,r4,r5,r6;//stringthe random int and +
          a = rand() % 6, b = rand() % 6;//to make them mininmum and random (within random)
           cout <<"Strength: " << a + b << " [The the minimum Strength is " << a << " and the random value is " << b << " ]\n";
            c = rand() % 6, d = rand() % 6;
           cout << "Endurance: " << c + d << " [The the minimum Endurance is " << c << " and the random value is " << d << " ]\n";
           e = rand() % 6, f = rand() % 6;
           cout << "Dexterity: " << e + f << " [The the minimum Dexterity is " << e << " and the random value is " << f << " ]\n";
            g = rand() % 6, h = rand() % 6;
           cout << "Intelligence: " << g + h << " [The the minimum Intelligence is " << g << " and the random value is " << h << " ]\n";
           i = rand() % 6, j = rand() % 6;
           cout << "Wisdom: " << i + j << " [The the minimum Wisdom is " << i << " and the random value is " << j << " ]\n";
           k = rand() % 6, l = rand() % 6;
           cout << "Charisma: " << k + l << " [The the minimum Charisma is " << k << " and the random value is " << l << " ]\n\n";
           result += "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
           //put the variables into the result
           ss1 << a; ss2 << b; ss3 << c; ss4 << d; ss5 << e; ss6 << f; ss7 << g; ss8 << h; ss9 << i; ss10 << j; ss11 << k; ss12 << l;
           r1 << a + b; r2 << c + d; r3 << e + f; r4 << g + h; r5 << i + j; r6 << k + l;
           string s1 = ss1.str();  string s2 = ss2.str(); string s3 = ss3.str(); string s4 = ss4.str(); string s5 = ss5.str(); string s6 = ss6.str(); string s7 = ss7.str(); string s8 = ss8.str(); string s9 = ss9.str(); string s10 = ss10.str(); string s11 = ss11.str(); string s12 = ss12.str();
           string rr1 = r1.str();  string rr2 = r2.str(); string rr3 = r3.str(); string rr4 = r4.str(); string rr5 = r5.str(); string rr6 = r6.str();
           result += "Strength: "; result +=rr1; result += " [The the minimum Strength is "; result += s1; result += " and the random value is "; result += s2; result += " ]\n";
           result += "Endurance: "; result +=rr2; result += " [The the minimum Strength is "; result += s3; result += " and the random value is "; result += s4; result += " ]\n";
           result += "Dexterity: "; result += rr3; result += " [The the minimum Strength is "; result += s5; result += " and the random value is "; result += s6; result += " ]\n";
           result += "Intelligence: "; result += rr4; result += " [The the minimum Strength is "; result += s7; result += " and the random value is "; result += s8; result += " ]\n";
           result += "Wisdom: ";  result += rr5; result += " [The the minimum Strength is "; result += s9; result += " and the random value is "; result += s10; result += " ]\n";
           result += "Charisma: "; result += rr6; result += " [The the minimum Strength is "; result += s11; result += " and the random value is "; result += s12; result += " ]\n";
    
    
    }
 //task5 
 void saveData() {
     

     //define at the begining
        ofstream WriteFile;
        char usersChoice;
        string FileData;
        cout << result ;//display the last generater
        cout << "\n\nDo you want to save the character? (y/n)";//Ask whether to save the dataor not
        cin >> usersChoice;
        //if usere don't enter y or n,ask the user to do it again
        while (usersChoice != 'y' && usersChoice != 'n') {
            cout << "\n\nDo you want to save the character? (y/n)";
            cin >> usersChoice;
        }
        //Save the data in the file(¡°savedCharacters.txt")
        if (usersChoice == 'y') {
             //write to file
            WriteFile.open("savedCharacters.txt");
            WriteFile << result << endl;
            }
        
        else {
            cout << endl; 
        } //ifstream readFile;        *these codes are in order to check storing the data in the right way.
        //readFile.open("savedCharacters.txt");
        //while (!readFile.eof()) {//read until end of file is reached
        //    getline(readFile, FileData);
        //   cout << FileData << endl;}
    }
//task6           
 void loadData() {
     //load the data in the vector  and print all the decision 

     /*vector<string>::iterator iter;
     for (iter = VectorData.begin(); iter != VectorData.end(); iter++) { cout << *iter << "\n"; }
     system("pause");*/cout << endl;
     ifstream readfile;
     readfile.open("savedCharacters.txt");
     string a;
     if (readfile.is_open()) {
         while (!readfile.eof()) {
             getline(readfile, a);
             cout << a << endl;
         }
     }

 }
 
     
    
 
      
       
      
   