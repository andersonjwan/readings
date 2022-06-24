#include <stdio.h>
#include <stdbool.h>

int strToInt(const char []);

int main(void) {
  printf("%i\n", strToInt("245"));
  printf("%i\n", strToInt("100") + 25);
  printf("%i\n", strToInt("13x5"));
  printf("%i\n", strToInt("-12") + 12);
  return 0;
}

int strToInt(const char string[]) {
  int i, intEquivalent, result = 0;
  bool isNegative;

  // check for negative
  if(string[0] == '-') {
    i = 1, isNegative = true;
  }
  else {
    i = 0, isNegative = false;
  }

  // convert string to integer
  for(; string[i] >= '0' && string[i] <= '9'; ++i) {
    intEquivalent = string[i] - '0';
    result = result * 10 + intEquivalent;
  }

  // convert to negative
  if(isNegative) {
    return -result;
  }
  else {
    return result;
  }
}
