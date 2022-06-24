#include <stdio.h>

#define INT_SIZE 32 /** machine dependent word size! **/

unsigned int rotate(unsigned int, int);

int main(void) {
  printf("Rotate 01234: %i\n", rotate(01234u, 5));
  return 0;
}

unsigned int rotate(unsigned int value, int n) {
  unsigned int result, bits;

  if(n > 0) {
    n = n % INT_SIZE;
  }
  else {
    n = -(-n % INT_SIZE);
  }

  if(n == 0) {
    result = value;
  }
  else if(n > 0) {
    bits = value >> (INT_SIZE - n);
    result = value << n | bits;
  }
  else {
    n = -n;
    bits = value << (INT_SIZE - n);
    result = value >> n | bits;
  }

  return result;
}
