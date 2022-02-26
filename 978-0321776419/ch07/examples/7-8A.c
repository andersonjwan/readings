#include <stdio.h>

float absoluteValue(float num) {
  if(num < 0) {
    return -num;
  }

  return num;
}

float squareRoot(float num) {
  auto const float epsilon = 0.00001;
  auto float guess = 1.0;

  /* forward declaration(s) */
  float absoluteValue(float);

  if(num < 0) {
    printf("Negative argument passed. Cannot eval squareRoot(%f).\n", num);
    return -1.0;
  }

  while(absoluteValue((guess * guess) - num) >= epsilon) {
    guess = ((num / guess) + guess) / 2.0;
  }

  return guess;
}

int main(void) {
  printf("squareRoot(-2.0) = %f\n", squareRoot(-2.0));
  printf("squareRoot(4.0) = %f\n", squareRoot(4.0));

  return 0;
}
