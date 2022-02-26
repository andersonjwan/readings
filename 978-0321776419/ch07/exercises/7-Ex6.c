#include <stdio.h>

/* forward declaration(s) */
double absoluteValue(double);
double squareRoot(double);

int main(void) {
  printf("squareRoot(2.0) = %f\n", squareRoot(2.0));
  printf("squareRoot(144.0) = %f\n", squareRoot(144.0));
  printf("squareRoot(17.5) = %f\n", squareRoot(17.5));

  return 0;
}

double absoluteValue(double num) {
  if(num < 0) {
    return -num;
  }

  return num;
}

double squareRoot(double num) {
  static const double epsilon = 0.000000001;
  auto double guess = 1.0;

  while(absoluteValue((guess * guess) - num) >= epsilon) {
    guess = ((num / guess) + guess) / 2.0;
  }

  return guess;
}
