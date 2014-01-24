//////////////////////////////////////////////////////////////////
//  Student name: Leila Yammine
//  Course: COSC 4553 - Information Security
//  Assignment: #2 - Double Transposition Cipher
//  File name: Yammine2.c
//  Program Purpose: Encrypts or decrypts a file using a double transposition cipher.
//
//  Program Limitations: None known
//  Development Computer: Macbook Pro
//  Operating System: OS X Mavericks
//  Integrated Development Environment (IDE): None (Terminal)
//  Compiler: GNU++
//  Build Directions:
//  Program's Operational Status: Compiles and runs with no errors. Error handling correct for bad argument input. Problem: Prints these error messages to output file.
//////////////////////////////////////////////////////////////////

#include <stdio.h>

//Global variables
int rows = 6;
int columns = 4;

//Decrypts the ciphertext
void decrypt(FILE *fileIn, FILE *fileOut) {
  char[][] plainText;
  char[][] cipherText;
  char x = 'x';

  //Read in text to decrypt 
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns, j++) {
      x = fgetc(fileIn);
      if(x != EOF) {
        plainText[i][j] = x;
      }
      else {
        break;
      }
    }
    if(x == EOF) {
      break;
    }
  }

  //Shuffle the rows (0,1,2,3,4,5) --> (3,5,0,2,1,4)                                                                                                                                                               
  for(int i = 0; i < columns; i++) {
    cipherText[0][i] = plainText[3][i];
    cipherText[1][i] = plainText[5][i];
    cipherText[2][i] = plainText[0][i];
    cipherText[3][i] = plainText[2][i];
    cipherText[4][i] = plainText[1][i];
    cipherText[5][i] = plainText[4][i];
  }

  //Shuffle the columns (0,1,2,3) --> (3,2,0,1)                                                                                                                                                                    
  for(int i = 0; i < rows; i++) {
    cipherText[i][0] = plainText[i][3];
    cipherText[i][1] = plainText[i][2];
    cipherText[i][2] = plainText[i][0];
    cipherText[i][3] = plainText[i][1];
  }

  //Close files and print to screen 
  fclose(fileIn);
  fclose(fileOut);
  printf("Decryption is done");
}

//Encrypts the plaintext
void encrypt(FILE *fileIn, FILE *fileOut) {
  char[][] plainText;
  char[][] cipherText;
  char x = 'x';

  //Read in text to encrypt
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns, j++) {
      x = fgetc(fileIn);
      if(x != EOF) {
	plainText[i][j] = x;
      }
      else {
	break;
      }
    }
    if(x == EOF) {
      break;
    }
  }

  //Shuffle the rows (0,1,2,3,4,5) --> (3,5,0,2,1,4)
  for(int i = 0; i < columns; i++) {
    cipherText[0][i] = plainText[3][i];
    cipherText[1][i] = plainText[5][i];
    cipherText[2][i] = plainText[0][i];
    cipherText[3][i] = plainText[2][i];  
    cipherText[4][i] = plainText[1][i];
    cipherText[5][i] = plainText[4][i];
  }

  //Shuffle the columns (0,1,2,3) --> (3,2,0,1)
  for(int i = 0; i < rows; i++) {
    cipherText[i][0] = plainText[i][3];
    cipherText[i][1] = plainText[i][2];  
    cipherText[i][2] = plainText[i][0];
    cipherText[i][3] = plainText[i][1];
  }

  //Close files and print to screen
  fclose(fileIn);
  fclose(fileOut);
  printf("Encryption is done");
}

//Main function. Receives input arguments and calls decrypt() or encrypt() accordingly
int main(int argc, const char * argv[]) {

  if (argc != 2) {
    printf("Usage: a.exe {-e | -d}");
    return 1;
  }

  FILE *plainText = fopen("plainText.txt", "r");
  FILE *cipherText = fopen("cipherText.txt", "w");

  char choice = argv[1];
  if(choice == 'd') {
    decrypt(cipherText, plainText);
  }
  else if(choice == 'e') {
    encrypt(plainText, cipherText);
  }
  else {
    printf("Usage: a.exe {-e | -d} integer-key");
    return 1;
  }

} //End main
