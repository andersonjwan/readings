#include <stdio.h>

/* forward declaration(s) */
float absoluteValue(float);
float squareRoot(float);
void polyCoefficients(int [3]);
int calcDiscriminant(int [3]);
void calcRoot1(int [3]);
void calcRoot2(int [2]);

int main(void) {
  int coefficients[3];

  polyCoefficients(coefficients);
  calcRoot1(coefficients);
  calcRoot2(coefficients);

  return 0;
}

float absoluteValue(float num) {
  if(num < 0) {
    return -num;
  }

  return num;
}

float squareRoot(float num) {
  static const float epsilon = 0.00001;
  auto float guess = 1.0;

  while(absoluteValue((guess * guess) - num) >= epsilon) {
    guess = ((num / guess) + guess) / 2.0;
  }

  return guess;
}

void polyCoefficients(int polynomial[3]) {
  // a coefficient
  printf("Please enter the coefficient of a: ");
  scanf("%d", &polynomial[0]);

  // b coefficient
  printf("Please enter the coefficient of b: ");
  scanf("%d", &polynomial[1]);

  // c coefficient
  printf("Please enter the coefficent of c: ");
  scanf("%d", &polynomial[2]);
}

int calcDiscriminant(int polynomial[3]) {
  auto int discr = (polynomial[1] * polynomial[1])
    - (4 * polynomial[0] * polynomial[2]);

  return discr;
}

void calcRoot1(int polynomial[3]) {
  auto float root1;

  if(calcDiscriminant(polynomial) < 0) {
    printf("False. Roots are imaginary.\n");
  }
  else {
    root1 = -polynomial[1] + squareRoot(calcDiscriminant(polynomial))
      / (2 * polynomial[0]);

    printf("Root 1: %f\n", root1);
  }
}

void calcRoot2(int polynomial[3]) {
  auto float root2;

  if(calcDiscriminant(polynomial) < 0) {
    printf("False. Roots are imaginary.\n");
  }
  else {
    root2 = -polynomial[1] - squareRoot(calcDiscriminant(polynomial))
      / (2 * polynomial[0]);

    printf("Root 2: %f\n", root2);
  }
}
