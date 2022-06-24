#include <stdio.h>

/* forward declaration(s) */
int strToInt(const char []);

int main(void) {
  printf("%i\n", strToInt("245"));
  printf("%i\n", strToInt("100") + 25);
  printf("%i\n", strToInt("13x5"));

  return 0;
}

int strToInt(const char string[]) {
  int i, intEquivalent, result = 0;

  for(i = 0; string[i] >= '0' && string[i] <= '9'; ++i) {
    intEquivalent = string[i] - '0';
    result = result * 10 + intEquivalent;
  }

  return result;
}
