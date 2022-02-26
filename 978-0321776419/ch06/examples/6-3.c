#include <stdio.h>

int main(void) {
  int fibonacci[15], i;

  fibonacci[0] = 0; // by definition
  fibonacci[1] = 1; // by definition

  // build fibonacci sequence
  for(i = 2; i < 15; ++i) {
    fibonacci[i] = fibonacci[i - 2] + fibonacci[i - 1];
  }

  // print array
  for(i = 0; i < 15; ++i) {
    printf("%d\n", fibonacci[i]);
  }

  return 0;
}
