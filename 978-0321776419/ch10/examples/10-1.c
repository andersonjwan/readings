#include <stdio.h>

int main(void) {
  int x, count = 10;
  int * int_ptr;

  int_ptr = &count; // point to 'count' address
  x = *int_ptr;     // indirection operator

  printf("count = %i, x = %i\n", count, x);
  return 0;
}
