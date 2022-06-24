#include <stdio.h>

int main(void) {
  int numbers[150], i;

  /* init indices to zero */
  for(int i = 2; i < 150; ++i) {
    numbers[i] = 0;
  }

  i = 2;
  while(i <= 150) {
    if(numbers[i] == 0) {
      printf("%d\n", numbers[i]);
    }

    for(int j = 0; j <= 150; ++j) {
      if((i * j) <= 150) {
        numbers[(i * j)] = 1;
      }
    }

    ++i;
  }

  /* print array content(s) */
  for(int i = 0; i < 150; ++i) {
    printf("numbers[%d] = %d\n", i, numbers[i]);
  }

  return 0;
}
