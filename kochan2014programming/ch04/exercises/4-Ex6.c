#include <stdio.h>

int main(void) {
  int n, triangularNumber;

  triangularNumber = 0;

  for(n = 1; n <= 200; n += 1) {
    triangularNumber += n;
  }

  printf("%-2d               %d\n", n, triangularNumber);
  return 0;
}
