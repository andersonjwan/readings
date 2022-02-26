#include <stdio.h>

/* forward declaration(s) */
long int x_to_the_n(int, int);

int main(void) {
  printf("2^2 = %ld\n", x_to_the_n(2, 2));
  printf("8^8 = %ld\n", x_to_the_n(8, 8));
  printf("3^4 = %ld\n", x_to_the_n(3, 4));

  return 0;
}

long int x_to_the_n(int x, int n) {
  auto int i;
  auto long int result = x;

  for(i = 1; i < n; ++i) {
    result = result * x;
  }

  return result;
}
