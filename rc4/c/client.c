/*
 * Curtis Lee
 * cuslee@ucsc.edu
 * 4/21/17
 * CMPS 122
 * test file for RC4 
 */

#include <stdio.h>
#include <stdlib.h>
#include "rc4.h"

int main(int argc, char* argv[]){
	
	unsigned long flen;
	unsigned char sEncrypt[256];
	unsigned char sDecrypt[256];
	FILE *f;
	
	if(argc==4){
		
		/* Read files */
		printf("Reading files...\n");
		
		// Read in key
		f = fopen(argv[1], "r");
		fseek(f,0,SEEK_END); //Get length
		flen = ftell(f);
		fseek(f,0,SEEK_SET); //Go to front to read
		
		unsigned char key[flen+1]; //Initialize array
		fread(key, flen, 1, f);
		fclose(f);
		
		// Read in plaintext
		f = fopen(argv[2], "r");
		fseek(f,0,SEEK_END); //Get length
		flen = ftell(f);
		fseek(f,0,SEEK_SET); //Go to front to read
		
		unsigned char plain[flen+1]; //Initialize arrays
		unsigned char cipher[flen+1];
		unsigned char plain2[flen+1];
		fread(plain, flen, 1, f);
		fclose(f);
		
		// Store length of key
		int keysize = (sizeof(key)) - 1;
		
		printf("Finished reading files.\n");
		printf("Key:\n%s\n", key);
		printf("Plaintext:\n%s\n", plain);
		
		/* Start doing rc4 encryption/decryption */
		// Start encryption
		printf("Encrypting...\n");
		
		int plainlen = (sizeof(plain)) - 1; //Get the length to iterate over
		ksa(sEncrypt,key,keysize);          //whole text
		prga(sEncrypt,plain,cipher,plainlen);
		
		printf("Finished encrypting.\nCiphertext:\n%s\n", cipher);
		
		// Start decryption
		printf("Decrypting...\n");
		
		int cipherlen = (sizeof(cipher)) - 1; //Get the length to iterate over
		ksa(sDecrypt,key,keysize);            //whole text
		prga(sDecrypt,cipher,plain2,cipherlen);
		
		printf("Finished decrypting.\nPlaintext:\n%s\n", plain2);
		
		// Print decrypted message to file
		f = fopen(argv[3], "w");
		fwrite(plain2, flen, 1, f);
		fclose(f);
	}else{
		printf("Usage: ./client [key(textfile)] [plaintext(textfile)] [decrypted(filename)]\n");
	}
	
	return 0;
}