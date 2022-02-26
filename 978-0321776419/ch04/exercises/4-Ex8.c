#include <stdio.h>

int main(void) {
  int n, number, triangularNumber, counter, iterations;

  // prompt for number of triangular number calculations
  printf("How many triangle numbers would you like: ");
  scanf("%d", &iterations);

  for(counter = 1; counter <= iterations; ++counter) {
    printf("What triangular number would you like: ");
    scanf("%d", &number);

    triangularNumber = 0;

    for(n = 1; n <= number; ++n) {
      triangularNumber += n;
    }

    printf("Triangular number %d is %d.\n\n", number, triangularNumber);
  }

  return 0;
}
