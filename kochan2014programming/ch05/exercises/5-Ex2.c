#include <stdio.h>

int main(void) {
  int num1, num2;

  printf("Please enter two integer separated by a space: ");
  scanf("%d %d", &num1, &num2);

  if(num1 % num2 == 0) {
    printf("%d is divisible by %d.\n", num1, num2);
  }
  else {
    printf("%d is not divisible by %d.\n", num1, num2);
  }

  return 0;
}
