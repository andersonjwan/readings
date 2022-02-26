#include <stdio.h>

int main(void) {
  int n, fact;

  // headers
  printf("Factorial\t\t\t\tResult\n");
  printf("--------------------------\n");

  // calculation
  for(n = 1; n <= 10; n++) {

    fact = n;
    for(int i = 1; i < n; i++) {
      fact = i * fact;
    }

    printf("%2d!\t\t\t\t\t\t\t%d\n", n, fact);
  }

  return 0;
}
