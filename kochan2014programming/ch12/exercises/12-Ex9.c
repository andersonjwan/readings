#include <stdio.h>

#define ABSOLUTE_VALUE(x) (((x) < 0) ? -(x) : (x))

int main(void) {
  printf("abs(%i): %i\n", 10 + 12, ABSOLUTE_VALUE(10 + 12));
  printf("abs(%i): %i\n", -10 + 2, ABSOLUTE_VALUE(-10 + 2));

  return 0;
}
