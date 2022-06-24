#include <stdio.h>
#include <stdbool.h>

/* forward declaration(s) */
void sort(void);
void printArray(void);

/* global variable(s) */
int g_arraySampleSize = 10;
int g_arraySample[10] = {2, 4, 7, 8, 6, 5, 4, 1, 3, 0};
bool g_ascending = true;

int main(void) {
  printf("Original: ");
  printArray();

  sort();
  printf("Sorted (ascending): ");
  printArray();

  g_ascending = false;
  sort();
  printf("Sorted (descending): ");
  printArray();

  return 0;
}

void sort(void) {
  auto int i, j, temp;

  if(g_ascending) {
    for(i = 0; i < g_arraySampleSize - 1; ++i) {
      for(j = i + 1; j < g_arraySampleSize; ++j) {
        if(g_arraySample[i] > g_arraySample[j]) {
          temp = g_arraySample[i];
          g_arraySample[i] = g_arraySample[j];
          g_arraySample[j] = temp;
        }
      }
    }
  }
  else {
    for(i = 0; i < g_arraySampleSize - 1; ++i) {
      for(j = i + 1; j < g_arraySampleSize; ++j) {
        if(g_arraySample[i] < g_arraySample[j]) {
          temp = g_arraySample[i];
          g_arraySample[i] = g_arraySample[j];
          g_arraySample[j] = temp;
        }
      }
    }
  }
}

void printArray(void) {
  auto int i;

  printf("[");
  for(i = 0; i < g_arraySampleSize - 1; ++i) {
    printf("%d, ", g_arraySample[i]);
  }

  printf("%d]\n", g_arraySample[g_arraySampleSize - 1]);
}
