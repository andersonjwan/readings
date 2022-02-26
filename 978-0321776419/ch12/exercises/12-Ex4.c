#include <stdio.h>

#define MAX3(x, y, z) (((x) > (y)) ? (((x) > (z)) ? (x) : (z)) : (((y) > (z)) ? (y) : (z)))

int main(void) {
  printf("MAX3(10, 22, 12): %i\n", MAX3(10, 22, 12));

  return 0;
}
