#include <iostream> 
#include <string.h> 
#include <stdexcept>

using std::cout;
using std::endl;

class Vigenere {
    private:
        const char *key;
        int keyLength;
    public:
        Vigenere(const char *key);
        char *keyGen(int length);
        char *VigenereEncryption(char *input);
        char *VigenereDecryption(char *input);
        ~Vigenere();
};