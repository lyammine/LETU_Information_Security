//////////////////////////////////////////////////////////////////
//  Student name: Leila Yammine
//  Course: COSC 4553 - Information Security
//  Assignment: #1 - Simple Arithmetic Cipher
//  File name: Yammine1.c
//  Program Purpose: Encrypts and decrypts a text file using a
//  simple arithmetic cipher and a nonnegative integer key.
//
//  Program Limitations: None known
//  Development Computer: Macbook Pro
//  Operating System: OS X Mavericks
//  Integrated Development Environment (IDE): XCode
//  Compiler: GNU++
//  Build Directions:
//  Program's Operational Status: Compiles and runs with no errors. Error handling correct for bad argument input. Problem: Prints these error messages to output file.
//////////////////////////////////////////////////////////////////

#include <stdio.h>

//Decrypts each character read from file by subtracting integer key value and prints to output file
void decrypt(FILE *fileIn, FILE *fileOut, int key) {
    int x = 0;
    while (x != EOF) {
        x = fgetc(fileIn);
        x += key;
        fprintf(fileOut, "%c", x);
    }
    fclose(fileIn);
    fclose(fileOut);
    printf("Decryption is done");
}

//Encrypts each character read from file by adding integer key value and prints to output file
void encrypt(FILE *fileIn, FILE *fileOut, int key) {
    int x = 0;
    while (x != EOF) {\
        x = fgetc(fileIn);
        x -= key;
        fprintf(fileOut, "%c", x);
    }
    fclose(fileIn);
    fclose(fileOut);
    printf("Encryption is done");
}

//Main function. Receives input arguments and encrypts or decrypts data accordingly
int main(int argc, const char * argv[])
{

    if (argc != 5) {
        printf("Usage: a.exe {-e | -d} integer-key");
        return 1;
    }
    
    int choice = (int)argv[1];
    int key = (int)argv[2];
    FILE *fileIn = fopen(argv[3], "r");
    FILE *fileOut = fopen(argv[4], "w");
    
    if(key < 0 || key > 120) {
        printf("Usage: Integer key must range between 0 and 120 inclusive");
        return 1;
    }
    
    printf("Usage: a.exe {-e | -d} integer-key");
    
    switch (choice) {
        case 'd':
            decrypt(fileIn, fileOut, key);
            break;
        
        case 'e':
            encrypt(fileIn, fileOut, key);
            break;
            
        default:
            break;
    }
    fclose(fileOut);
    fclose(fileIn);
    
    return 0;
}


