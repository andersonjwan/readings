#include <stdio.h>

int main(void) {
  int a = 100;
  int b = 2;
  int c = 25;
  int d = 4;
  int result;

  result = a - b; // subtraction
  printf("%i - %i = %i\n", a, b, result);

  result = b * c; // multiplication
  printf("%i * %i = %i\n", b, c, result);

  result = a / c; // division
  printf("%i / %i = %i\n", a, c, result);

  result = a + b * c; // precedence
  printf("%i + %i * %i = %i\n", a, b, c, result);

  printf("%i * %i + %i * %i = %i\n", a, b, c, d, a * b + c * d);

  return 0;
}
