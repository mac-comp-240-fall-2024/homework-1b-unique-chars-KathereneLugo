/*
 * hasUniqueChars.c
 * 
 * Function and helper function code with ultimate goal of checking for duplicate characters
 * in a given string.
 * 
 * Author: Katherene Lugo
 */

#include <stdio.h>  // fprintf, printf
#include <stdlib.h> // exit() defined here
#include <string.h> // useful string operations
#include <ctype.h>  //useful character operations
#include <stdbool.h>  // to define a boolean type and true, false
                      // see https://en.wikibooks.org/wiki/C_Programming/stdbool.h

#include "binary_convert.h"


/*
 * This function is for debugging by printing out the value
 * of an input insigned long as a binary string.
 */
void seeBits(unsigned long value, char *debug_text) {
  
  // string to represent binary value of variable value
  char *bin_str;

  bin_str = ulong_to_bin_str(value);
  printf("%s%s\n", debug_text, bin_str);
  free(bin_str);
  
}



/*
 * Given an input string of chars, check for any non-printing
 * characters and print an error and exit if the string has any.
 */
void checkInvalid(char * inputStr) {
  char nextChar;
  int i;
  
  for(i = 0; i < strlen(inputStr); i++) {
    nextChar = inputStr[i];

    // if nextChar is invalid (31 or less or 127 as an ascii char code), then bail out
    if ((nextChar <= 31 ) || (nextChar == 127)) {
      fprintf(stderr, "invalid character in string\n");
      exit(EXIT_FAILURE);
    }
  }
}


/*
 * This function takes an input string (pointer to a sequence of characters)
 * and iterates through its characters, checking for duplicates. The function
 * checks which range of printable characters it is currently iterating through
 * using 2 unsigned long. Depending on which is the current range, The function 
 * tracks which characters have not been seen before and uses bitwise operators
 * to keep track of them once they are seen. If the character is a space, the 
 * program continues normally. Otherwise, the chracter has been seen before
 * and the program returns the boolean false OR the chracter is one that
 is an invalid input string ex: \n \t \r
 */
bool hasUniqueChars(char * inputStr) {
  // bail out quickly if any invalid characters
  checkInvalid(inputStr);
  
  int i;   // loop counter
  
  // unsigned long can handle 64 different chars in a string
  // if a bit at a position is 1, then we have seen that character
  unsigned long checkBitsA_z = 0;   // for checking A through z and {|}~
  unsigned long checkBitsexcl_amp = 0;  // for checking ! though @ 
  unsigned long pos;
  unsigned long x;

  char nextChar;         // next character in string to check
  int len = strlen(inputStr);

  
  for(i = 0; i < len; i++) {
    nextChar = inputStr[i];
    if(nextChar >= 65 && nextChar <= 126){
      pos = 1;
      pos = pos << (nextChar-65);
      x = pos & checkBitsA_z;
      if(x == 0){
        checkBitsA_z = pos | checkBitsA_z;
      }else {
        return false;
      }
    }else if (nextChar >= 33 && nextChar <= 64){
      pos = 1;
      pos = pos << (nextChar-33);
      if((pos & checkBitsexcl_amp) == 0){
        checkBitsexcl_amp = pos | checkBitsexcl_amp;
      }else {
        return false;
      }
    }else if(nextChar == ' '){
        continue;
      }
  }

  // if through all the characters, then no duplicates found
  return true;
  
}
