#include <stdio.h>

int main(void) {
  int n, number, triangularNumber, counter = 1;
  
  while(counter <= 5) {
    // prompt
    printf("What triangular number would you like: ");
    scanf("%d", &number);

    triangularNumber = 0;
    n = 1;

    while(n <= number) {
      triangularNumber += n;
      ++n;
    }

    printf("Triangular number %d is %d.\n\n", number, triangularNumber);
    ++counter;
  }

  return 0;
}
