/* program to evaluate simple expressions of the form
   [value] [operator] [value] */

#include <stdio.h>

int main(void) {
  float op1, op2;
  char operator;

  // prompt
  printf("Type in your expression. \n");
  scanf("%f %c %f", &op1, &operator, &op2);

  switch(operator) {
  case '+':
    printf("%.2f\n", op1 + op2);
    break;
  case '-':
    printf("%.2f\n", op1 - op2);
    break;
  case '*':
    printf("%.2f\n", op1 * op2);
    break;
  case '/':
    if(op2 == 0) {
      printf("Division by zero.\n");
    }
    else {
      printf("%.2f\n", op1 / op2);
    }
    break;
  default:
    printf("Unknown operator.\n");
    break;
  }

  return 0;
}
