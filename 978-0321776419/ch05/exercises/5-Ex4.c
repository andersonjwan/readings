#include <stdio.h>

int main(void) {
  double accum;
  double operand;
  char operator;

  // initial prompt
  printf("Begin Calculations\n");
  scanf("%lf %c", &operand, &operator);

  while(operator != 'E') {
    // test input
    if(operator == 'S') {
      accum = operand;
      printf("= %.6lf\n", accum);
    }
    else if(operator == '/') {
      if(operand != 0) {
        accum /= operand;
        printf("= %.6lf\n", accum);
      }
      else {
        printf("Division by zero.\n");
      }
    }
    else if(operator == '-') {
      accum -= operand;
      printf("= %.6lf\n", accum);
    }
    else if(operator == '*') {
      accum *= operand;
      printf("= %.6lf\n", accum);
    }
    else if(operator == '+') {
      accum += operand;
      printf("= %.6lf\n", accum);
    }
    else {
      printf("%c is an unknown operator.\n", operator);
    }

    // prompt for operand
    scanf("%lf %c", &operand, &operator);
  }

  printf("End of Calculations.\n");

  return 0;
}
