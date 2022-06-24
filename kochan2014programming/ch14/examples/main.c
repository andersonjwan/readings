#include <stdio.h>

void foo(void);

int i = 5;

int main(void) {
  printf("i: %i\n", i);

  foo();

  printf("i: %i\n", i);

  return 0;
}
