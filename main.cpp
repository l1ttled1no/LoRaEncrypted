#include <iostream>
#include "lib/caesar.hpp"
#include "lib/vigenere.hpp"

using std::cout;
using std::endl; 

Caesar   caesar(10); // Insert the shifting value here
Vigenere vigenere("l1ttled1no"); // Insert the key here

void caesarTest(char *input){
    cout << "--------------Caesar Algorithm--------------" << endl;
    cout << "Original text: " << input << endl;
    char *encrypted = caesar.CaesarEncryption(input);
    cout << "Encrypted text: " << encrypted << endl;
    char *decrypted = caesar.CaesarDecryption(encrypted);
    cout << "Decrypted text: " << decrypted << endl;
}

void vigenereTest(char *input){
    cout << "--------------Vigenere Algorithm--------------" << endl;
    cout << "Original text: " << input << endl;
    char *encrypted = vigenere.VigenereEncryption(input);
    cout << "Encrypted text: " << encrypted << endl;
    char *decrypted = vigenere.VigenereDecryption(encrypted);
    cout << "Decrypted text: " << decrypted << endl;
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        throw std::invalid_argument("No input provided");
    }
    int length = 0;
    for (int i = 1; i < argc; i++) {
        length += strlen(argv[i]) + 1; // +1 for space or null terminator
    }
    char *input = new char[length];
    input[0] = '\0'; // Initialize input to an empty string
    for (int i = 1; i < argc; i++) {
        strcat(input, argv[i]);
        if (i < argc - 1) {
            strcat(input, " "); // Add space between arguments
        }
    }
    cout << "Input: " << input << endl;
    caesarTest(input);
    vigenereTest(input);
    delete[] input; // Free allocated memory
    return 0;
}
