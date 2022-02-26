#include <stdio.h>

int arraySum(int *, const int);

int main(void) {
  int values[10] = {3, 7, -9, 3, 6, -1, 7, 9, 1, -5};

  printf("The sum is %i\n", arraySum(&values[0], 10));
  return 0;
}

int arraySum(int * array, const int size) {
  int sum = 0;

  // points to one after last element
  int * const arrayEnd = &array[0] + size;

  for( ; array < arrayEnd; ++array) {
    sum += *array;
  }

  return sum;
}
