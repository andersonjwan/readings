#include <stdio.h>

/* forward declaration(s) */
int gcd(int, int);
int lcm(int, int);

int main(void) {
  printf("lcm(5, 15) = %d\n", lcm(5, 15));
  printf("lcm(15, 10) = %d\n", lcm(15, 10));
  return 0;
}

int gcd(int u, int v) {
  auto int temp;

  while(v != 0) {
    temp = u % v;
    u = v;
    v = temp;
  }

  return u;
}

int lcm(int u, int v) {
  return (u * v) / (gcd(u, v));
}
