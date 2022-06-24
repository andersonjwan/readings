#include <stdio.h>

int main(void) {
  int n, number, triangularNumber;

  // prompt
  printf("What triangular number do you want?: ");
  scanf("%d", &number);

  triangularNumber = 0;
  n = 1;

  while(n <= number) {
    triangularNumber += n;
    ++n;
  }

  printf("Triangular number %d is %d\n", number, triangularNumber);
  return 0;
}
