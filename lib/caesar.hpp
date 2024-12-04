#ifndef CAESAR_HPP
#define CAESAR_HPP
#include <iostream>
#include <string.h>
#include <stdexcept>

using std::cout; 
using std::endl;
class Caesar{ 
    private: 
        int shift; 
    public:
        Caesar(int shift = 5); 
        char *CaesarEncryption (char *input); 
        char *CaesarDecryption (char *input);
}; 



#endif // CAESAR_HPP