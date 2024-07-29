// Maya Thompson
// CS 1, Section #0107
// Assignment #6, Problem #1
// Summary: This program takes a user's inputted string and applies user-decided manipulations to the string


// PSEUDOCODE //

/*
Declare and initialize variables, arrays, and function prototypes
Prompt the user to enter a word, a sentence, or a string of numbers
Store the user input as a C++ string
Display a menu to prompt a user how they would like their string to be manipulated
Store the user input and validate it is an accepted input
Apply the selected manipulation
Display to the user the manipulation has been applied to the string
Continue to display the menu and process selected manipulations until the user selects to exit
Display the manipulated string
If the user selects 9, end program
*/

#include <iostream>
#include <stdlib.h>
#include <cctype>
#include <ctime>
#include <cstring>
#include <algorithm>

using namespace std;

// Declare and initialize variables
char menuSelection = '1';
int i = 0;
int j = 0;

// Arrays
const int MAXCHARS = 81; // max elements in all array strings
char userString[MAXCHARS]; // stores user's string

// Function Prototypes
void countWords(char string[]);
void countConsonants(char string[]);
bool isAVowel(char character);
void jumbleString(char string[]);
void strcopy(char string1[], char string2[]);
void strreverse(char string[]);



int main(){

// Prompt the user to enter a word, a sentence, or a string of numbers
    cout << "Enter a string:  ";
    cin.getline(userString, MAXCHARS, '\n'); // Store the user input as a C++ string

// Display a menu to prompt a user how they would like their string to be manipulated and store their input

    cout << "USE THIS MENU TO MANIPULATE YOUR STRING" << endl
         << "---------------------------------------" << endl
         << "1) Inverse String" << endl
         << "2) Reverse String" << endl
         << "3) To Uppercase" << endl
         << "4) Jumble string" << endl
         << "5) Count Number Words" << endl
         << "6) Count Consonants" << endl
         << "7) Enter a Different String" << endl
         << "8) Print the String" << endl
         << "9) Quit" << endl << endl
         << "Enter your choice: " << endl;
        
    cin >> menuSelection;
    cin.ignore();


    // Validate user's response
    while (menuSelection != '1' &&
           menuSelection != '2' &&
           menuSelection != '3' &&
           menuSelection != '4' &&
           menuSelection != '5' &&
           menuSelection != '6' &&
           menuSelection != '7' &&
           menuSelection != '8' &&
           menuSelection != '9') {
        
        cout << "Invalid selection. Please trying again" << endl;
        
        cout << "USE THIS MENU TO MANIPULATE YOUR STRING" << endl
             << "---------------------------------------" << endl
             << "1) Inverse String" << endl
             << "2) Reverse String" << endl
             << "3) To Uppercase" << endl
             << "4) Jumble string" << endl
             << "5) Count Number Words" << endl
             << "6) Count Consonants" << endl
             << "7) Enter a Different String" << endl
             << "8) Print the String" << endl
             << "9) Quit" << endl << endl
             << "Enter your choice: " << endl;
         
        cin >> menuSelection;
        cin.ignore();

    }

    while (menuSelection != '9') {

    switch (menuSelection) {
        case '1':
            // inverse string 
            i = 0;
            while (userString[i] != '\0') {
                if (isupper(userString[i])) {
                    userString[i] = tolower(userString[i]);
                } else {
                    userString[i] = toupper(userString[i]);
                }
                i++;
            }
            break;
        case '2':
           // reverse string
            strreverse(userString);
           break;
        case '3':
            // convert to uppercase 
           while (userString[j] != '\0') {
                if (islower(userString[j])) { // check if lower
                    userString[j] = toupper(userString[j]); // change to upper
                } 
                j++;
            } 
            break;
        case '4':
            // jumble string
            jumbleString(userString);
            break;
        case '5':
            // count number words
            countWords(userString);
            break;
        case '6':
            // count consonants
            countConsonants(userString);
            break;
        case '7':
            // enter a different string
            cout << "Enter a new string:  "; // Prompt the user to enter a word, a sentence, or a string of numbers
            cin.ignore(); // clear all previous inputs
            cin.getline(userString, MAXCHARS, '\n'); // Store the new string
            break;
        case '8':
            // print string
            cout << endl << userString << endl << endl;
            break;
    }
    
        cout << "USE THIS MENU TO MANIPULATE YOUR STRING" << endl
             << "---------------------------------------" << endl
             << "1) Inverse String" << endl
             << "2) Reverse String" << endl
             << "3) To Uppercase" << endl
             << "4) Jumble string" << endl
             << "5) Count Number Words" << endl
             << "6) Count Consonants" << endl
             << "7) Enter a Different String" << endl
             << "8) Print the String" << endl
             << "9) Quit" << endl << endl
             << "Enter your choice: " << endl;

        cin >> menuSelection;
        cin.ignore();

} 

    return 0;
}


// Function Definitions

// Function to copy one string to another string
void strcopy(char destString[], char sourceString[]) {
    int i = 0;
    while (sourceString[i] != '\0') {
        destString[i] = sourceString[i];
        i++;
    }
    destString[i] = '\0';
    return;
}

// Function to reverse string
void strreverse(char stringArr[]) {   
    char tempString[MAXCHARS];
    int stringLen = strlen(stringArr);
    int j = stringLen - 1; // starting position of j
    for (int i = 0; i < stringLen; i++, j--) {
        tempString[j] = stringArr[i];
    } tempString[stringLen] = '\0'; // terminate with null
    strcopy(userString, tempString);
}

// Function to jumble string
void jumbleString(char string[]) {
    char jumbledString[MAXCHARS];
    strcopy(jumbledString, string); // copy to a new string to jumble
    char temp; 
    int ranNum = 0;
    int length = strlen(jumbledString); 

    for (int i = 0; i < length; i++) {
        temp = jumbledString[i]; // copy [i] position to a temp char
        ranNum = rand() % length;  // generate a random number for new [i] position
        jumbledString[i] = jumbledString[ranNum]; // move randomized position char to [i]
        jumbledString[ranNum] = temp; // fill random position with old [i] position
    }

    cout << jumbledString << endl; // display jumbled string
}

// Function to count words
void countWords(char string[]) {
    int count = 0; // counts words
    bool word = false; // are we in a word
    int length = strlen(string); // stop before '\0'

    for (int i = 0; i < length; i++) {

        if (isspace(string[i])) {   // if [i] is a space 
            word = false; // not in a word
        } else {  // if [i] isn't a space
            if (!word) {  // and [i] was not in a word
                count++; // this is new word --> add to count 
                word = true; // now in a word
            }
        }
    }
    // display number of words
    cout << endl << "The string " << endl << string << endl << " has " << count << " word(s)." << endl;
}

// Function to check for vowels
bool isAVowel(char character) {
    bool vowel = false;
    if (isalpha(character)) {
        if (character == 'a' ||
            character == 'A' || 
            character == 'e' ||
            character == 'E' ||
            character == 'i' ||
            character == 'I' ||
            character == 'o' ||
            character == 'O' ||
            character == 'u' ||
            character == 'U') {
                vowel = true;
        } 
    }
    return vowel;
}

// Function to count consonants
void countConsonants(char string[]) {
    int count = 0;
    bool consonants = false;
    int length = strlen(string);

    for (int i = 0; i < length; i++) {
        if (isalpha(string[i])) {
            if (!isAVowel(string[i])) {
                count++;
            }
        }
    }
    // display number of consonants
    cout << endl << "The string " << endl << string << endl << " has " << count << " consonant(s)." << endl;
}