#include <stdio.h>

int main(void) {
  // variable declaration
  int F = 27;
  float C;

  // conversion
  C = (F - 32) / 1.8;
  printf("%iF is %fC.\n", F, C);

  return 0;
}
