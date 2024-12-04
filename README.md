# LoRaEncryption
Encrypting and Decrypting data via LoRa transmission.

> [!CAUTION]
> Please note that the code and materials provided in this repository are intended for EDUCATIONAL purposes only and is NOT SAFE to be used in production.
> The Dev kit we will using in this project is Arduino Uno, with a EByte E32-433T20D in this project.
## Background


## Algorithm using in this project 

Because of the limitation of the LoRa transmission, limitation of time, and the need for a lightweight encryption algorithm, we choose to use the [Caesar cipher](https://en.wikipedia.org/wiki/Caesar_cipher) and the [Vigenère cipher](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher) algorithm.

## To build this project (Algorithm for Testing)

1. Clone the repository: 

```bash
git clone https://github.com/l1ttled1no/LoRaEncryption
```
2. Build the project

>[!NOTE]
> The shift in Caesar cipher can be modified in main.cpp file. 
> The key in Vigenère cipher can be modified in main.cpp file.
First, build the main executable:

```bash
g++ -Ilib -o main main.cpp src/*.cpp
```

Then, 