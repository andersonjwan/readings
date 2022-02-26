#include <stdio.h>

int main(void) {
  int year, rem_4, rem_100, rem_400;

  printf("Enter the year to be tested: ");
  scanf("%d", &year);

  rem_4 = year % 4;
  rem_100 = year % 100;
  rem_400 = year % 400;

  if((rem_4 == 0 && rem_100 != 0) || rem_400 == 0) {
    printf("%d is a leap year.\n", year);
  }
  else {
    printf("%d is not a leap year.\n", year);
  }

  return 0;
}
