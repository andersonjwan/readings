#include <stdio.h>

/* forward declaration(s) */
int strLength(const char []);

int main(void) {

  const char word1[] = {'a', 's', 't', 'e', 'r', '\0'};
  const char word2[] = {'a', 't', '\0'};
  const char word3[] = {'a', 'w', 'e', '\0'};

  printf("%i\t%i\t%i\n", strLength(word1), strLength(word2), strLength(word3));

  return 0;
}

int strLength(const char string[]) {
  /**
   * strLength counts the number of characters
   * in a character array besides the null
   * character.
   *
   * @param string[]
   * @return length
   */

  int length = 0;

  while(string[length] != '\0') {
    ++length;
  }

  return length;
}
