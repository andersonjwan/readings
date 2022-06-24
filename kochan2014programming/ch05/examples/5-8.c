/* Program to evaluate simple expressions of the form
   number operator number */

#include <stdio.h>

int main(void) {
  float op1, op2;
  char operator;

  printf("Type in your expression.\n");
  scanf("%f %c %f", &op1, &operator, &op2);

  if(operator == '+') {
    printf("%.2f\n", op1 + op2);
  }
  else if(operator == '-') {
    printf("%.2f\n", op1 - op2);
  }
  else if(operator == '*') {
    printf("%.2f\n", op1 * op2);
  }
  else if(operator == '/') {
    printf("%.2f\n", op1 / op2);
  }
  else {
    printf("The expression is formatted incorrectly.\nPlease try again.\n");
  }

  return 0;
}
