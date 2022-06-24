#include <stdio.h>

int arraySum(int [], const int);

int main(void) {
  int values[10] = {3, 7, -9, 3, 6, -1, 7, 9, 1, -5};

  printf("The sum is %i\n", arraySum(values, 10));
  return 0;
}

int arraySum(int array[], const int size) {
  int sum = 0, *array_ptr;
  int * const arrayEnd = &array[0] + size;

  for(array_ptr = &array[0]; array_ptr < arrayEnd; ++array_ptr) {
    sum += *array_ptr;
  }

  return sum;
}
