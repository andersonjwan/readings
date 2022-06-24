#include <stdio.h>

int main(void) {
  int i, numFibs;

  printf("How many Fibonacci numbers do you want? (between 1 - 75) ");
  scanf("%d", &numFibs);

  if(numFibs < 1 || numFibs > 75) {
    printf("Bad number, sorry!\n");
    return 0;
  }

  unsigned long long int fibonacci[numFibs];

  fibonacci[0] = 0; // by definition
  fibonacci[1] = 1; // by definition

  for(i = 2; i < numFibs; ++i) {
    fibonacci[i] = fibonacci[i - 2] + fibonacci[i - 1];
  }

  for(i = 0; i < numFibs; ++i) {
    printf("%llu\t", fibonacci[i]);
  }

  printf("\n");
  return 0;
}
