#include <stdio.h>

int main(void) {
  // struct definition
  struct date {
    int month;
    int day;
    int year;
  };

  struct date today;

  // structure declaration
  today.month = 7;
  today.day = 24;
  today.year = 2019;

  printf("Today's date is %.2d/%.2d/%.2d.\n", today.month, today.day, today.year % 100);

  return 0;
}
