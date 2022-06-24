#include <stdio.h>

int main(void) {
  struct int_pointers {
    int *ptr1;
    int *ptr2;
  } pointers;

  int i1 = 100, i2;

  pointers.ptr1 = &i1;
  pointers.ptr2 = &i2;

  *pointers.ptr2 = -97; // i2 = -97

  printf("i1 = %i, *pointers.ptr1 = %i\n", i1, *pointers.ptr1);
  printf("i2 = %i, *pointers.ptr2 = %i\n", i2, *pointers.ptr2);
  return 0;
}
