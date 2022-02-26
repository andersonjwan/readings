/* Program to evaluate simple expressions of the form:
   value operator value */

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
    if(op2 == 0) {
      printf("Division by zero.\n");
    }
    else {
      printf("%.2f\n", op1 / op2);
    }
  }
  else {
    printf("Unknown operator.\n");
  }

  return 0;
}
