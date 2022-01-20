//
//  MASC.hpp
//  MASC (redo)
//
//  Created by Gavin Forsberg on 10/24/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#ifndef MASC_hpp
#define MASC_hpp
#include <stdio.h>
#include <string>

class MASC
{
public:
    std::string generateKey();
    std::string inputKey();
    void verifyUserKey(std::string userInput);
    
    std::string encrypt(std::string plaintext);
    std::string addSpacing(std::string plaintext, const int spacing);
    
    std::string decrypt(std::string cipheredText);
    
private:
    std::string keyword;
    std::string ciphered;
};

#endif /* MASC_hpp */
