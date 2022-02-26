#include <stdio.h>

int main(void) {
  // headers
  printf("Rows\t\t\t\tDots\n");
  printf("-------------------\n");

  // calculation(s)
  for(int i = 5; i <= 50; i += 5) {
    printf("%2d\t\t\t\t\t%d\n", i, (i * (i + 1) /2));
  }

  return 0;
}
