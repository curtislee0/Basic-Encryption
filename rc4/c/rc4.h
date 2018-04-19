/*
 * Curtis Lee
 * cuslee@ucsc.edu
 * 4/21/17
 * CMPS 122
 * source code for RC4 
 */

#ifndef _RC4_H_INCLUDE_
#define _RC4_H_INCLUDE_

// Key-scheduling Algorithm
int ksa(unsigned char* s, unsigned char* k, int length);

// Pseudo-random Generation Algorithm
int prga(unsigned char* s, unsigned char* p, unsigned char* c, int length);

#endif