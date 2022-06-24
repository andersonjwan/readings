#include <stdio.h>

int main(void) {
  int n, number, triangularNumber, counter;

  for(counter = 1; counter <= 5; counter++) {
    printf("What triangular number would you like: ");
    scanf("%d", &number);

    triangularNumber = 0;

    for(n = 1; n <= number; n++) {
      triangularNumber += n;
    }

    printf("Triangular number %d is %d.\n\n", number, triangularNumber);
  }

  return 0;
}
