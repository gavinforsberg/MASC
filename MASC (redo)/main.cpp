//
//  main.cpp
//  MASC (redo)
//
//  Created by Gavin Forsberg on 10/24/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#include "MASC.hpp"
#include <iostream>
using namespace std;

int main()
{
    MASC cipher;
    
    //user selects to input their own key or have one generated
    char keySelection = ' ';
    cout << "Please Make a selection: \n(1) Type in a key \n(2) Have a key generated for you" << endl << endl;
    cin >> keySelection;
    cout << "\nChoice: " << keySelection << endl << endl;
    
    if(keySelection == '1')
        cipher.inputKey();
    else if(keySelection == '2')
        cipher.generateKey();

    
    //Gathers the plaintext
    cin.clear(); cin.ignore(10000, '\n');
    string plaintext = " ";
    cout << "\nEnter the plaintext: " << endl;
    getline(cin, plaintext);
    
    //Asks user to disguise or keep original spacing
    char spaceSelection = ' ';
    cout << "\n\nPlease make a selection: \n(1) Preserve spacing from plaintext when creating ciphertext \n(2) Disguise original spacing" << endl << endl;
    //cin.clear(); cin.ignore(10000, '\n');
    cin >> spaceSelection;
    cout << "Choice: " << spaceSelection;

    //Encrypts with original spacing
    string cipher1 = cipher.encrypt(plaintext);
    if(spaceSelection == '1')
    {
        cout << "\nNow encrypting plaintext..." << endl;
        cout << "Ciphertext is: " << endl;
        cout << cipher.encrypt(plaintext) << endl << endl;
    }
    else if(spaceSelection == '2')
    {   //Default spacing is 5
        int spacing = 5;
        cout << "\n\nHow many letters should appear in each grouping? \nPlease Enter for default spacing of 5." << endl;
        
        
        if(cin.ignore().peek() == '\n')
            spacing = 5;
        else
            cin >> spacing;
        
        cout << "Spacing: " << spacing << endl << endl;
        
        //Adds the uniform spacing wanted by user
        cout << "\nNow encrypting plaintext..." << endl;
        cout << "Ciphertext is: " << endl;
        cipher.addSpacing(plaintext, spacing);
    }
    
    cout << endl;
    
    //Decrypts the ciphered text
    cipher.decrypt(cipher1);
    
    cout << endl << endl;
    
}
