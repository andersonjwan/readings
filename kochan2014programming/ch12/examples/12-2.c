#include <stdio.h>

#define PI 3.141592654

double circleArea(double);
double circleCircumference(double);
double circleVolume(double);

int main(void) {
  printf("radius = 1: %.4f     %.4f     %.4f\n", circleArea(1.0),
         circleCircumference(1.0), circleVolume(1.0));

  printf("radius = 4.98: %.4f     %.4f     %.4f\n", circleArea(4.98),
         circleCircumference(4.98), circleVolume(4.98));

  return 0;
}

double circleArea(double radius) {
  return PI * (radius * radius);
}

double circleCircumference(double radius) {
  return 2.0 * PI * radius;
}

double circleVolume(double radius) {
  return (4.0 / 3.0) * PI * (radius * radius * radius);
}
