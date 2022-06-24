#include <stdio.h>

int main(void) {
  float numf1 = 123.125, numf2;
  int   numi1, numi2 = -150;
  char  c = 'a';

  numi1 = numf1; // floating to integer conversion
  printf("%f assigned to an int produces %i\n", numf1, numi1);

  numf1 = numi2; // integer to floating conversion
  printf("%i assigned to a float produces %f\n", numi2, numf1);

  numf1 = (numi2 / 100); // integer divided by integer
  printf("%i divided by 100 produces %f\n", numi2, numf1);

  numf2 = (numi2 / 100.0); // integer divided by a float
  printf("%i divided by 100.0 produces %f\n", numi2, numf2);

  numf2 = (float) numi2 / 100; // type cast operator
  printf("(float) %i divided by 100 produces %f\n", numi2, numf2);

  return 0;
}
