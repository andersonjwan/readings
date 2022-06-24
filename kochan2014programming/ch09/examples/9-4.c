#include <stdio.h>
#include <stdbool.h>

/* forward declaration(s) */
bool equalStrings(const char [], const char []);

int main(void) {
  const char stra[] = "string compare test";
  const char strb[] = "string";

  printf("%i\n", equalStrings(stra, strb));
  printf("%i\n", equalStrings(stra, stra));
  printf("%i\n", equalStrings(strb, "string"));

  return 0;
}

bool equalStrings(const char str1[], const char str2[]) {
  /**
   * equalStrings tests if two character arrays are identical
   * in elements and size.
   */

  int i = 0;
  bool areEqual;

  while(str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0') {
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
