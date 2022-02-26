#include <stdio.h>

int main(void) {
  int n;

  // headers
  printf("Values\t\t\t\tn\t\t\t\tn^2\n");
  printf("-------------------------\n");

  for(n = 1; n < 11; ++n) {
    printf("%2d   \t\t|\t\t%3d\t\t|\t\t%3d\n", n, n, n * n);
  }

  return 0;
}
