#include "vigenere.hpp"

Vigenere::Vigenere(const char *key) {
    this->key = key;
    this->keyLength = strlen(key);
}

Vigenere::~Vigenere() {
    // No need to delete key since it's a const char*
}

char *Vigenere::keyGen(int length) {
    char *output = new char[length + 1];
    for (int i = 0; i < length; i++) {
        output[i] = key[i % keyLength];
    }
    output[length] = '\0';
    return output;
}

char *Vigenere::VigenereEncryption(char *input) {
    char *output = new char[strlen(input) + 1];
    char *key = keyGen(strlen(input));
    for (int i = 0; i < strlen(input); i++) {
        output[i] = (char)(((input[i] - 32 + key[i] - 32) % 95) + 32);
    }
    output[strlen(input)] = '\0';
    delete[] key;
    return output;
}

char *Vigenere::VigenereDecryption(char *input) {
    char *output = new char[strlen(input) + 1];
    char *key = keyGen(strlen(input));
    for (int i = 0; i < strlen(input); i++) {
        output[i] = (char)(((input[i] - 32 - (key[i] - 32) + 95) % 95) + 32);
    }
    output[strlen(input)] = '\0';
    delete[] key;
    return output;
}