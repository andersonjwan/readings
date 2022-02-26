#include <stdio.h>

int gcd(int u, int v) {
  auto int temp;

  while(v != 0) {
    temp = u % v;
    u = v;
    v = temp;
  }

  return u;
}

int main(void) {
  printf("The GCD of %d and %d is %d\n", 150, 35, gcd(150, 35));
  printf("The GCD of %d and %d is %d\n", 1026, 405, gcd(1026, 405));
  printf("The GCD of %d and %d is %d\n", 83, 240, gcd(83, 240));

  return 0;
}
