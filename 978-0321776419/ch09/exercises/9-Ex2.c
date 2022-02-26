#include <stdio.h>

/* forward declaration(s) */
bool equalStrings(const char [], const char []);

int main(void) {

  return 0;
}

bool equalStrings(const char str1[], const char str2[]) {
  int i = 0;
  bool areEqual;

  while(str1[i] == str2[i] && str1[i] != '\0') {
    // traverse through both character arrays simultaneously
    // and check for character equality and for end-of-string
    // condition.
    ++i;
  }

  if(str1[i] == '\0' && str2[i] == '\0') {
    areEqual = true;
  }
  else {
    areEqual = false;
  }

  return areEqual;
}

/* Response 1:
 * The replacement of the while-loop relational conditions
 * is allowed due to the case that if the first string is shorter
 * than the second, then the null-character is reached first; therefore,
 * the strings are not the same and the index of both do not point to
 * the end of the string. Additionally, if the first string is
 * longer than the second string, then the second string will result
 * in a null-character first leading to the case that the characters
 * are not equivalent; therefore, when tested after the while-loop,
 * both strings at the respective index do not result in the null
 * character.
 */
