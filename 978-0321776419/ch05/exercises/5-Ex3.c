#include <stdio.h>

int main(void) {
  int num1, num2;

  // prompt user
  printf("Please enter two number separated by a space: ");
  scanf("%d %d", &num1, &num2);

  if(num2 == 0) {
    printf("Division by zero.\n");
  }
  else {
    printf("%d / %d = %.3lf\n", num1, num2, (double) num1 / num2);
  }

  return 0;
}
