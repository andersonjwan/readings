#include <stdio.h>

/* forward declaration(s) */
int arraySum(int, int []);

int main(void) {
  int arraySample[5] = {1, 2, 3, 1, 1};

  printf("Sum = %d\n", arraySum(5, arraySample));
  return 0;
}

int arraySum(int size, int array[size]) {
  auto int i, sum = 0;

  for(i = 0; i < size; ++i) {
    sum += array[i];
  }

  return sum;
}
