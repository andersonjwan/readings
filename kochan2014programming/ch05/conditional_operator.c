#include <stdio.h>
#include <stdbool.h>

int main(void) {
  int num;

  printf("Please enter a number: ");
  scanf("%d", &num);

  /* condition ? expression1 : expression2 */
  num = (num >= 0) ? num : -num;

  printf("|num| = %d\n", num);
  return 0;
}
