#include <stdio.h>

#define SHIFT(value, n) (((n) > 0) ? (value << n) : (value >> n))

int main(void) {
  printf("%o\n", SHIFT(0177777u, 5));

  return 0;
}
