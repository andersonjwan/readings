#include <stdio.h>

int main(void) {
  int n, n_power;

  printf("TABLE OF POWERS OF TWO\n\n");
  printf(" n     2 to the n\n");
  printf("---    ---------------\n");

  n_power = 1;
  for(n = 0; n <= 10; n++) {
    printf("%2d        %d\n", n, n_power);
    n_power *= 2;
  }

  return 0;
}
