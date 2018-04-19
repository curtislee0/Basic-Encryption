/*
 * Curtis Lee
 * cuslee@ucsc.edu
 * 4/21/17
 * CMPS 122
 * header for RC4 
 */

#include <stdio.h>
#include <stdlib.h>
#include "rc4.h"

// Keyscheduling Algorithm
// This function takes in unsigned char array s of length 256 and initinalizes
// it.
int ksa(unsigned char* s, unsigned char* k, int length){
	
	int i=0;
	int j=0;
	unsigned char temp, t[256];
	
	// Initialize s and create an array t to store values from k to add to
	// s in a later step.
	for(i=0; i<256; i++){
		s[i] = i;
		t[i] = k[i%length];
	}
	
	// Permutate s
	// Calculate j which is an index to swap with i
	for(i=0; i<256; i++){
		j = (j+s[i]+t[i])%256;
		temp = s[i]; //Start swap values
		s[i] = s[j];
		s[j] = temp;
	}
	
	return 0;
}

// Pseudo-random Generation Algorithm
// Taking s initialized by the ksa, we find byte k and xor with p (plaintext)
// to create c (ciphertext).
int prga(unsigned char* s, unsigned char* p, unsigned char* c, int length){
	
	int i=0;
	int j=0;
	int t, index;
	unsigned char temp,k;
	
	// Stream generation of byte k to xor with plaintext
	for(index=0; index<length; index++){
		i = (i+1)%256; //Find swap values
		j = (j+s[i])%256;
		temp = s[i]; //Start swap values
		s[i] = s[j];
		s[j] = temp;
		t = (s[i]+s[j])%256; //Select byte
		k = s[t];
		c[index] = p[index]^k; //XOR byte
	}
	
	return 0;
}