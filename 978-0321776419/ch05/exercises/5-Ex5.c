#include <stdio.h>
#include <stdbool.h>

int main(void) {
  int number, right_digit;
  bool isNegative = false;

  printf("Enter a number: ");
  scanf("%d", &number);

  if(number < 0) {
    do {
      right_digit = number % 10;
      printf("%d", -right_digit);

      number /= 10;
    }
    while(number != 0);

    printf("-");
  }
  else {
    do {
      right_digit = number % 10;
      printf("%d", right_digit);

      number /= 10;
    }
    while(number != 0);
  }

  printf("\n");
  return 0;
}
