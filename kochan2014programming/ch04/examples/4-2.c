/* Program to calculate the 200th triangular number
   Introduction of the for statement */

#include <stdio.h>

int main(void) {
  int n, triangularNumber;

  triangularNumber = 0; // initial value

  for(n = 1; n <= 200; n += 1) {
    triangularNumber += n;
  }

  printf("The 200th triangular number is %i\n", triangularNumber);

  return 0;
}
