/* Program to find the greatest common divisor between
   two non-negative integers */
#include <stdio.h>

int main(void) {
  int u, v, temp;

  printf("Please type in two non-negative integers: ");
  scanf("%d %d", &u, &v);

  while(v != 0) {
    temp = u % v;
    u = v;
    v = temp;
  }

  printf("The greatest common divisor is: %d.\n", u);

  return 0;
}
