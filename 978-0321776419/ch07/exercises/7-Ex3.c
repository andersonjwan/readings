#include <stdio.h>

/* forward declaration(s) */
float absoluteValue(float);
float squareRoot(float, float);

int main(void) {
  float number, accuracy;

  printf("Please enter a number: ");
  scanf("%f", &number);
  printf("Please enter the accuracy: ");
  scanf("%f", &accuracy);

  printf("Result: %f\n", squareRoot(number, accuracy));
  return 0;
}

float absoluteValue(float num) {
  if(num < 0) {
    return -num;
  }

  return num;
}

float squareRoot(float num, float epsilon) {
  auto float guess = 1.0;

  while(absoluteValue((guess * guess) - num) >= epsilon) {
    guess = ((num / guess) + guess) / 2.0;
  }

  return guess;
}
