#include <stdio.h>

void sort(int *, const int);

int main(void) {
  int i;
  int array[16] = {34, -5, 6, 0, 12, 100, 56, 22, 44, -3, -9, 12, 17, 22, 6, 11};

  printf("The array before sorting:\n");

  printf("[");
  for(i = 0; i < 15; ++i) {
    printf("%d, ", *(array + i));
  }
  printf("%d]\n", *(array + 15));

  sort(array, 16);

  printf("\n\nThe array after sorting:\n");

  printf("[");
  for(i = 0; i < 15; ++i) {
    printf("%d, ", *(array + i));
  }
  printf("%d]\n", *(array + 15));

  return 0;
}

void sort(int * array, const int size) {
  int temp;
  int * const array_end = &array[0] + size;
  int * array_temp = array;

  for( ; array < array_end - 1; ++array) {
    for(array_temp = array + 1; array_temp < array_end; ++array_temp) {
      if(*array > *array_temp) {
        temp = *array;
        *array = *array_temp;
        *array_temp = temp;
      }
    }
  }
}
