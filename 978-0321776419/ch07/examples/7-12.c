#include <stdio.h>

/* forward declaration(s) */
void sort(int [], int);

int main(void) {
  int i;
  int array[16] = {34, -5, 6, 0, 12, 100, 56, 22, 44, -3, -9, 12, 17, 22, 6, 11};

  printf("The array before sorting:\n");

  printf("[");
  for(i = 0; i < 15; ++i) {
    printf("%d, ", array[i]);
  }
  printf("%d]\n", array[15]);

  sort(array, 16);

  printf("\n\nThe array after sorting:\n");

  printf("[");
  for(i = 0; i < 15; ++i) {
    printf("%d, ", array[i]);
  }
  printf("%d]\n", array[15]);

  return 0;
}

void sort(int array[], int n) {
  auto int i, j, temp;

  for(i = 0; i < n - 1; ++i) {
    for(j = i + 1; j < n; ++j) {
      if(array[i] > array[j]) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
}
