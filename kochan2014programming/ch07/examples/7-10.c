#include <stdio.h>

int minimum(int [], int);

int main(void) {
  int array1[5] = {157, -28, -37, 26, 10};
  int array2[7] = {12, 45, 1, 10, 5, 3, 22};

  printf("array1's minimum: %d\n", minimum(array1, 5));
  printf("array2's minimum: %d\n", minimum(array2, 7));

  return 0;
}

int minimum(int values[], int numElements) {
  auto int minValue, i;

  minValue = values[0];

  for(i = 1; i < numElements; ++i) {
    if(values[i] < minValue) {
      minValue = values[i];
    }
  }

  return minValue;
}
