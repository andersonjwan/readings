#include <stdio.h>

int main(void) {
  float x = 2.55;
  float function;

  function = 3 * (x * x * x) - 5 * (x * x) + 6;
  printf("f(%f) = %f\n", x, function);

  return 0;
}
