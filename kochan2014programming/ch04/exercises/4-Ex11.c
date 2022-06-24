#include <stdio.h>

int main(void) {
  int number, right_digit, sum = 0;

  // prompt
  printf("Enter a number: ");
  scanf("%d", &number);

  while(number != 0) {
    right_digit = number % 10;
    sum += right_digit;

    number /= 10;
  }

  printf("The sum of the digits is: %d\n", sum);
  return 0;
}
