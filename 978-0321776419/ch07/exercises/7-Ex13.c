#include <stdio.h>
#include <stdbool.h>

/* forward declaration(s) */
void sort(int [], int, bool);
void printArray(int, int []);

int main(void) {
  int arraySample[10] = {2, 4, 7, 8, 6, 5, 4, 1, 3, 0};
  printf("Original: ");
  printArray(10, arraySample);

  sort(arraySample, 10, true);
  printf("Sorted (ascending): ");
  printArray(10, arraySample);

  sort(arraySample, 10, false);
  printf("Sorted (descending): ");
  printArray(10, arraySample);

  return 0;
}

void sort(int array[], int n, bool ascending) {
  auto int i, j, temp;

  if(ascending) {
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
  else {
    for(i = 0; i < n - 1; ++i) {
      for(j = i + 1; j < n; ++j) {
        if(array[i] < array[j]) {
          temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }
      }
    }
  }
}

void printArray(int size, int array[size]) {
  auto int i;

  printf("[");
  for(i = 0; i < size - 1; ++i) {
    printf("%d, ", array[i]);
  }

  printf("%d]\n", array[size - 1]);
}
