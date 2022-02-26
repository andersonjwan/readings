#include <stdio.h>
#include <stdbool.h>

float strToFloat(const char []);

int main(void) {
  printf("%.4f\n", strToFloat("-867.6921"));
  printf("%.2f\n", strToFloat("10.23") + 0.5);
  return 0;
}

float strToFloat(const char string[]) {
  int i;
  float digitEquivalent, factor, result = 0;
  bool isNegative;

  // check negativity
  if(string[0] == '-') {
    i = 1, isNegative = true;
  }
  else {
    i = 0, isNegative = false;
  }

  // convert left-side of decimal
  for(; string[i] >= '0' && string[i] <= '9' && string[i] != '.';
      ++i) {
    digitEquivalent = string[i] - '0';
    result = result * 10 + digitEquivalent;
  }

  // skip over decimal
  ++i;

  // convert right-side of decimal
  factor = 10;
  for(; string[i] >= '0' && string[i] <= '9'; ++i) {
    digitEquivalent = (string[i] - '0') / factor;
    factor *= 10;

    printf("%f\n", digitEquivalent);
    result = result + digitEquivalent;
  }

  // decided negative versus positive
  if(isNegative) {
    return -result;
  }
  else {
    return result;
  }
}
