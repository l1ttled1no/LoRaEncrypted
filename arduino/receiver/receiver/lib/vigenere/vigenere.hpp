#include <string.h> 

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