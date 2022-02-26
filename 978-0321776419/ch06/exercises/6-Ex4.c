#include <stdio.h>

int main(void) {
  float values[10], sum = 0;

  /* init indices to zero */
  for(int i = 0; i < 10; ++i) {
    values[i] = 0;
  }

  /* prompt for input values */
  for(int i = 0; i < 10; ++i) {
    printf("Value %d: ", i + 1);
    scanf("%f", &values[i]);
  }

  /* calculate sum */
  for (int i = 0; i < 10; ++i) {
      sum += values[i];
  }

  printf("Average: %.2f\n", (sum / 10));
  return 0;
}
