#include <stdio.h>

void gcd(int u, int v) {
  auto int temp;

  printf("The gcd of %d and %d is ", u, v);

  while(v != 0) {
    temp = u % v;
    u = v;
    v = temp;
  }

  printf("%d\n", u);
  return;
}

int main(void) {
  gcd(150, 35);
  gcd(1026, 405);
  gcd(83, 240);

  return 0;
}
