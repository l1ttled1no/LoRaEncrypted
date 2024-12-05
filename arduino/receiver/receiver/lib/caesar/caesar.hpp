#ifndef CAESAR_HPP
#define CAESAR_HPP
#include <string.h>


class Caesar{ 
    private: 
        int shift; 
    public:
        Caesar(int shift = 5); 
        char *CaesarEncryption (char *input); 
        char *CaesarDecryption (char *input);
}; 



#endif // CAESAR_HPP