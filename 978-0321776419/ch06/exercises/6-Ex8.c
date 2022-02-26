#include <stdio.h>

int main(void) {
  int array_size, sum = 0;

  /* prompt user for number of terms */
  printf("How many terms would you like to sum? ");
  scanf("%d", &array_size);

  int variable_numbers[array_size];
  for(int i = 0; i < array_size; ++i) {
    printf("Number %d: ", i + 1);
    scanf("%d", &variable_numbers[i]);
  }

  /* calculate the sum */
  for(int i = 0; i < array_size; ++i) {
    sum += variable_numbers[i];
  }

  printf("Sum: %d\n", sum);
  return 0;
}
