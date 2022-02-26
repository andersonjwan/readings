#include <stdio.h>

int int_size();

int main(void) {
  printf("%i bits\n", int_size());
  return 0;
}

int int_size() {
  unsigned int num = ~0, bit_count = 0;
  unsigned int test = 0;

  while(num & test != 1) {
    num = num >> 1;
    ++bit_count;
  }

  return bit_count;
}
