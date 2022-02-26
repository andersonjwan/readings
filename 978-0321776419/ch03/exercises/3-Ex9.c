#include <stdio.h>

int main(void) {
  int next_mult, i, j;

  // prob. #1
  i = 365;
  j = 7;

  next_mult = i + j - i % j;
  printf("The next largest even multiple of %i and %i: %i\n", i, j, next_mult);

  // prob. #2
  i = 12258;
  j = 23;

  next_mult = i + j - i % j;
  printf("The next largest even multiple of %i and %i: %i\n", i, j, next_mult);

  // prob. #3 printf("The next largest even multiple of %i and %i: %i\n", i, j, next_mult);

  i = 996;
  j = 4;

  next_mult = i + j - i % j;
  printf("The next largest even multiple of %i and %i: %i\n", i, j, next_mult);

  return 0;
}
