#include <stdio.h>

unsigned int rotate(unsigned int, int);
int int_size();

int main(void) {
  unsigned int w1 = 0xabcdef00u, w2 = 0xffff1122u;

  printf("%x\n", rotate(w1, 8));
  printf("%x\n", rotate(w1, -15));
  printf("%x\n", rotate(w2, 4));
  printf("%x\n", rotate(w2, -2));
  printf("%x\n", rotate(w1, 0));
  printf("%x\n", rotate(w1, 44));

  return 0;
}

unsigned int rotate(unsigned int value, int n) {
  unsigned int result, bits;

  if(n > 0) {
    n = n % 32;
  }
  else {
    n = -(-n % int_size());
  }

  if(n == 0) {
    result = value;
  }
  else if(n > 0) {
    bits = value >> (int_size() - n);
    result = value << n | bits;
  }
  else {
    n = -n;
    bits = value << (int_size() - n);
    result = value >> n | bits;
  }

  return result;
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
