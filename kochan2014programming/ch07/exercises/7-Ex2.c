#include <stdio.h>

/* forward declaration(s) */
int calculateTriangularNumber(int);

int main(void) {
  int triangleNum;

  printf("Please enter the triangle number: ");
  scanf("%d", &triangleNum);

  printf("Result: %d\n", calculateTriangularNumber(triangleNum));
  return 0;
}

int calculateTriangularNumber(int num) {
  auto int i, triangularNumber = 0;

  for(i = 1; i <= num; ++i) {
    triangularNumber += i;
  }

  return triangularNumber;
}
