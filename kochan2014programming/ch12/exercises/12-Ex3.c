#include <stdio.h>

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int main(void) {
  printf("Minimum between -10 and 20 is %i\n", MIN(-10, 20));

  return 0;
}
