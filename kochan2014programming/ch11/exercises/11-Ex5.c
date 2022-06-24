#include <stdio.h>

int bit_test(unsigned int, int);
int bit_set(unsigned int, int);

int main(void) {
  unsigned int num = 5, bit_position = 30, result;
  
  result = bit_test(num, bit_position);

  printf("bit at position %i is ", bit_position);

  if(result) {
    printf("turned on.\n");
  }
  else {
    printf("turned off.\n");
  }

  printf("2 + [first bit set high] = %i\n", bit_set(2, 32));
  printf("0 + [fifth bit set high] = %i\n", bit_set(0, 28));
  return 0;
}

int bit_test(unsigned int num, int bit) {
  unsigned int test_int = num | 1;
  int position = 32;

  while(position > bit) {
    num >>= 1; // srl
    --position;
  }

  if(num & test_int) {
    return 1;
  }
  else {
    return 0;
  }
}


int bit_set(unsigned int num, int bit) {
  unsigned int temp_num = num;
  int position = 32;

  while(position > bit) {
    temp_num >>= 1; // srl
    --position;
  }

  // turn bit on
  temp_num = temp_num | 1;

  // shift back
  while(position < 32) {
    temp_num <<= 1; // sll
    ++position;
  }

  // turn original bits high
  temp_num = temp_num | num;

  return temp_num;
}
