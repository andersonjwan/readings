#include <stdio.h>

#define IS_UPPER_CASE(c) (((c) >= 'A' && (c) <= 'Z') ? 1 : 0)

int main(void) {
  printf("Is %c uppercase?: %i\n", 'B', IS_UPPER_CASE('B'));
  printf("Is %c uppercase?: %i\n", 'z', IS_UPPER_CASE('z'));

  return 0;
}
