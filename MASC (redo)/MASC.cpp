//
//  MASC.cpp
//  MASC (redo)
//
//  Created by Gavin Forsberg on 10/24/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#include "MASC.hpp"
#include <iostream>
#include <random>
using namespace std;

MASC cipher;

string MASC::generateKey()
{
    //random number generator
    random_device rng;
    const auto seed = rng.entropy() ? rng() : time(NULL);
    mt19937_64 rnd(seed);
    uniform_int_distribution<int>dist{65,90};
    
    //Shuffles the alphabet
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    shuffle(alpha.begin(), alpha.end(), rnd);
    
    cipher.keyword = alpha;
    
    //Displays key
    cout << "Key is: " << cipher.keyword;
    return cipher.keyword;
}

string MASC::inputKey()
{
    string input = " ";
    //Prompts user to input key
    cout << "Enter a key to be used for encryption and decryption. Include each letter of the alphabet, none repeated: " << endl;
    cin >> input;
    
    //Checks input key for size and repeats
    verifyUserKey(input);
    
    cipher.keyword = input;
    
    return cipher.keyword;
}

void MASC::verifyUserKey(string userInput)
{
    //Checking that key is 26 characters
    while(userInput.length() != 26)
    {
        cin.clear(); cin.ignore(10000, '\n'); cout << endl;
        cerr << "Incorrect key length. Must be 26 characters." << endl << endl;
        cout << "Enter a key to be used for encryption and decryption. Include each letter of the alphabet, none repeated: " << endl;
        cin >> userInput;
    }

    //Checking that key does not contain repeated characters
    bool duplicates = true;

    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZZ";

    for(int i = 0; i < userInput.length(); ++i)
    {
        for(int j = i + 1; j < userInput.length(); ++j)
        {
            if(userInput[i] == userInput[j])
                duplicates = true;
            else
            {
                duplicates = false;
                break;
            }
        }

        if(duplicates == true)
        {
            cin.clear(); cin.ignore(10000, '\n'); cout << endl;
            cerr << "Error: letters in key must be used only once." << endl << endl;
            inputKey();
        }
    }
}

string MASC::encrypt(string plaintext)
{
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ciphered = plaintext;
    
    for(int i = 0; i < ciphered.length(); ++i)
    {
        for(int j = 0; j < alpha.length(); ++j)
        {   //Checks plaintext characters against same location in the alphabet
            if(toupper(ciphered[i]) == alpha[j])
            {   //swaps plaintext characters with characters at that location in the key
                ciphered[i] = cipher.keyword[j];
                break;
            }
        }
    }

    return ciphered;
}

//Source: Scott Wiliams
string MASC::addSpacing(string plaintext, const int spacing)
{
    //If user wants spacing every [number] characters, will add spaces then encrypt text
    int counter = 0;
    string spacedString;
    
    for(const auto letter : plaintext)
    {
        if(letter == ' ')
            continue;
         
        ++counter;
        spacedString += letter;
        
        if(counter % spacing == 0)
            spacedString += " ";
    }
    
    //encrypt(spacedString);
    cout << encrypt(spacedString);
    
    return spacedString;
}

//Source: Scott Williams
string MASC::decrypt(string cipheredText)
{
    int cipherTextLength = static_cast<int>(cipheredText.length());
    int keyIndex;
    
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string plainText;

    for (int i = 0; i < cipherTextLength; ++i)
    {
        keyIndex = static_cast<int>(cipher.keyword.find(cipheredText[i]));
        
        if (keyIndex != -1)
            plainText += alpha[keyIndex];
        else
            plainText += " ";
    }

    cout << "\nNow decrypting ciphertext... \nPlaintext is: ";
    cout << plainText;
    return plainText;
}

/*
string MASC::decrypt(string ciphered)
{
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string plaintxt = ciphered;
    
    for(int i = 0; i < ciphered.length(); ++i)
    {
        for(int j = 0; j < alpha.length(); ++j)
        {
            if(toupper(ciphered[i]) == cipher.keyword[j])
            {
                plaintxt[i] = alpha[j];
                break;
            }
        }
    }
    
    cout << "\nNow decrypting ciphertext... \nPlaintext is: ";
    cout << plaintxt;
    return plaintxt;
}
*/
