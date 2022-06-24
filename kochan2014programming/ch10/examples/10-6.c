#include <stdio.h>

int main(void) {
  struct entry {
    int value;
    struct entry *next;
  };

  struct entry n1, n2, n3, n4, n5;
  int i;

  n1.value = 100;
  n2.value = 200;
  n3.value = 300;
  n4.value = 400;
  n5.value = 500;

  // point to next structure
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = &n5;

  i = n1.next->value; // i = n2.value
  printf("%i   ", i);

  printf("%i\n", n3.next->value); // n3.next->value == n4.value
  return 0;
}
