// program to reverse the digits of a number
#include <stdio.h>

int main(void) {
  int number, right_digit;

  printf("Enter a number: ");
  scanf("%d", &number);

  do {
    right_digit = number % 10;
    printf("%d", right_digit);

    number /= 10;
  }
  while(number != 0);

  printf("\n");
  return 0;
}
