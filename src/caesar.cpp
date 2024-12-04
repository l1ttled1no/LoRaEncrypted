#include "caesar.hpp"
// #include <stdexcept>

// ---------------------- Original Caesar ----------------------
OriginalCaesar::OriginalCaesar(int shift) {
    this->shift = shift % 95;
}

char *OriginalCaesar::CaesarEncryption(char *input) {
    // Char range: 32-126
    unsigned int length = strlen(input);
    char *output = new char[length + 1];
    int *tmp = new int[length];
    for (int i = 0; i < strlen(input); i++) {
        tmp[i] = (int)input[i] + shift;
        if (tmp[i] > 126) {
            tmp[i] = tmp[i] - 95;
        } else if (tmp[i] < 32) {
            tmp[i] = tmp[i] + 95;
        }
        output[i] = (char)tmp[i];
    }
    output[strlen(input)] = '\0';
    delete[] tmp;
    return output;
}

char *OriginalCaesar::CaesarDecryption(char *input) {
    // Char range: 32-126
    unsigned int length = strlen(input);
    char *output = new char[length + 1];
    int *tmp = new int[length];
    for (int i = 0; i < strlen(input); i++) {
        tmp[i] = (int)input[i] - shift;
        if (tmp[i] > 126) {
            tmp[i] = tmp[i] - 95;
        } else if (tmp[i] < 32) {
            tmp[i] = tmp[i] + 95;
        }
        output[i] = (char)tmp[i];
    }
    return output;
}

// // ---------------------- Advanced Caesar ---------------------- 
// UpgradedCaesar::UpgradedCaesar(int a, int b) {
//     if (a <= 0 || b < 0){
//         throw std::invalid_argument("a must be greater than 0");
//     }
//     this->a = a; 
//     this->b = b;
// }

// char *UpgradedCaesar::CaesarEncryption (char *input){
//     // encrypted_char = (a * original_char + b) % 94 + 33
//     int len = strlen(input);
//     char *output = new char[len + 1];
//     for (int i = 0; i < len; i++) {
//         output[i] = (char)(((a * ((int)input[i] - 33) + b) % 94) + 33);
//     }
//     output[len] = '\0';
//     return output;
// }

// int modInverse(int a, int m) {
//     a = a % m;
//     for (int x = 1; x < m; x++) {
//         if ((a * x) % m == 1) {
//             return x;
//         }
//     }
//     throw std::invalid_argument("No modular inverse found");
// }

// char UpgradedCaesar::decryptor(char ch){
//     int mod_inv = modInverse(a, 94);
//     int decrypted_char = (mod_inv * ((ch - 33) - b + 94)) % 94;
//     return (char)(decrypted_char + 33);
// }

// char *UpgradedCaesar::CaesarDecryption(char *input) {
//     int len = strlen(input);
//     char *output = new char[len + 1];
//     int mod_inv = modInverse(a, 94);
    
//     for (int i = 0; i < len; i++) {
//         int decrypted_char = (mod_inv * ((input[i] - 33) - b + 94)) % 94;
//         output[i] = (char)(decrypted_char + 33);
//     }
//     output[len] = '\0';
//     return output;
// }
