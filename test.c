/*
 * Katherene Lugo
 This file contains several test cases for hasUniqueChars function
 from hasUniqueChars.c 
 */

#include <stdio.h>    // printf
#include <stdbool.h>  // to define a boolean type and true, false
#include <string.h>   // strcpy  to copy a string
#include <assert.h>


// declaration of function from hasUniqueChars.c
bool hasUniqueChars(char * inputStr);


int main() {

  // ------------------------------------------------------------
  // Examples of declaring string constants
  /* Example 1 */
  char string1[] = "A string declared as an array.\n";

  /* Example 2 */
  char *string2 = "A string declared as a pointer.\n";

  /* Example 3 */
  char string3[128];   // can copy in up to 127 characters
                       // chose 128 because it is a multiple of 8 bytes
  strcpy(string3, "A string constant copied in.\n");

  // You can uncomment these to see how the strings were initialized above.
  // Then you can comment these out again once you see that the 
  // strings were created correctly
  // printf ("%s", string1);
  // printf ("%s", string2);
  // printf ("%s", string3);

  // -------------------------------------------------------------
  // Thorough and exhaustive tests of hasUniqueChars()  
  bool ok;    // holds the result of hasUniqueChars(); used in asserts
  
  // Test 1: a test case that should return false because characters are duplicated
  strcpy(string3, "This should fail (l and s and i and h)");
  ok = hasUniqueChars(string3);
  assert(!(ok));
  
  // Test 2: This should be true and not fail, but won't work until you
  // complete the hasUniqueChars() function
  strcpy(string3, "abcdefghij");
  ok = hasUniqueChars(string3);
  assert(ok);
  
  // Test 3: a test case that should be true and not fail because spaces are not duplicates
  strcpy(string3, "              ");
  ok = hasUniqueChars(string3);
  assert(ok);

  // Test 4: a test case that should be true and not fail because there are no duplicates
  strcpy(string3, "a b c d e f g h i j");
  ok = hasUniqueChars(string3);
  assert(ok);

  // Test 5: a test case that should be true and not fail because there are no duplicates
  strcpy(string3, "0 1 2 3 4 5 6 7 8 9");
  ok = hasUniqueChars(string3);
  assert(ok);

  // Test 6: a test case that should be true and not fail because there are no duplicates and it includes all the printable characters
  // found in checkBitsexcl_amp
  strcpy(string3, "!'#$&()*+,-./0123456789:;<\"=>?@\%");
  ok = hasUniqueChars(string3);
  assert(ok);

  // Test 7: a test case that should return false because there are duplicates and it includes all the printable characters
  // found in checkBitsexcl_amp
  strcpy(string3, "!'#$&()*+,-./0123456789:;<\%=\">?@!");
  ok = hasUniqueChars(string3);
  assert(!(ok));

  // Test 8: a test that should be true and not fail because it contains a range of characters from both checkBitsexcl_amp
  // and checkBitsA_z with no duplicates
  strcpy(string3, "!A#Fg^}[]fmz");
  ok = hasUniqueChars(string3);
  assert((ok));

  // Test 9: a test that should be true and not fail because it contains all of the characters from 
  // checkBitsA_z with no duplicates
  strcpy(string3, "ABCDEFGHIJKLMNOPQRS]TUVWXYZ[^_`abcdefghijklmnopqrstuvwxyz{|}~");
  ok = hasUniqueChars(string3);
  assert((ok));

  // Test 10: a test that should return false because it contains all of the characters from
  // checkBitsA_z with duplicates
  strcpy(string3, "ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_`abcdefghijklmnopqrstuvwxyz{|}~A");
  ok = hasUniqueChars(string3);
  assert(!(ok));

  // Test 11: a test that should return true and not fail because it contains all of the characters from both checkBitsexcl_amp
  // and checkBitsA_z with duplicates
  strcpy(string3, "ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_`abcdefghijklmnopqrstuvwxyz{|}~!'#$&()*+,-./01\%345\"6789:;<=>?@");
  ok = hasUniqueChars(string3);
  assert((ok));

  // Test 12: a test that should return false because it contains all of the characters from both checkBitsexcl_amp
  // and checkBitsA_z with duplicates
  strcpy(string3, "ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_`abcdefghijklmnopqrstuvwxyz{|}~!'#$&()*+,-./0\%123\"456789:;<=>?@ABC");
  ok = hasUniqueChars(string3);
  assert(!(ok));

  // Test 13: a test case that should return false because there are duplicates
  strcpy(string3, "aaaaaaAAAAA");
  ok = hasUniqueChars(string3);
  assert(!(ok));

  // Test 14: a test case that should return false because there are duplicates
  strcpy(string3, "!!!!!!!!!!!!!!!");
  ok = hasUniqueChars(string3);
  assert(!(ok));

  // Test 15: a test case that should return false because there are duplicates (with spaces)
  strcpy(string3, "a a a a a a a a a a A A");
  ok = hasUniqueChars(string3);
  assert(!(ok));

  // Test 16: a test case that should return false because there are duplicates (with spaces)
  strcpy(string3, "! ! ! ! ! ! ! ! ! ! ! ! ! ! !");
  ok = hasUniqueChars(string3);
  assert(!(ok));

  // Test 17: a test case that should be true and not fail baecause there are no duplicates and
  // a ~ (higher end of range testing for ascii printable characters)
  strcpy(string3, "abcdefgh~");
  ok = hasUniqueChars(string3);
  assert(ok);

  // Test 18: a test case that should be true and not fail baecause there are no duplicates and
  // a ! (lower end of range testing for ascii printable characters)
  strcpy(string3, "abcdefgh!");
  ok = hasUniqueChars(string3);
  assert(ok);

  // Test 19: a test case that should return false baecause there are duplicates of 
  // ~ which is at the end of higher range for ascii printable characters
  strcpy(string3, "~abcdefgh~");
  ok = hasUniqueChars(string3);
  assert(!(ok));

  // Test 20: a test case that should return false baecause there are duplicates of 
  // ! which is at the end of lower range for ascii printable characters
  strcpy(string3, "!abcdefgh!");
  ok = hasUniqueChars(string3);
  assert(!(ok));

  // Tests 21-23: test cases that are commented out for sake of not causing program exit failure
  // should cause program exit failure when commented back in

  // strcpy(string3, "a b cc\n");
  // ok = hasUniqueChars(string3);

  // strcpy(string3, "a b cc\t");
  // ok = hasUniqueChars(string3);

  // strcpy(string3, "a b cc\r");
  // ok = hasUniqueChars(string3);
  
  return 0;
}