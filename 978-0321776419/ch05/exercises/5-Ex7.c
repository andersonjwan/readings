#include <stdio.h>
#include <stdbool.h>

int main(void) {
  int p, d;
  bool isPrime;

  printf("%d\t", 2);

  for(p = 3; p <= 50; p += 2) {
    isPrime = true;

    for(d = 3; d < p; d += 2) {
      if(p % d == 0) {
        isPrime = false;
        break;
      }
    }

    if(isPrime) {
      printf("%d\t", p);
    }
  }

  printf("\n");
  return 0;
}
