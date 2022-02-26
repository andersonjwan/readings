#include <stdio.h>

int main(void) {
  struct date {
    int month;
    int day;
    int year;
  };

  struct date today, tomorrow;

  const int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  // user prompt(s)
  printf("Enter today's date (mm dd yyyy): ");
  scanf("%d %d %d", &today.month, &today.day, &today.year);

  // tomorrow calculation(s)
  if(today.day != daysPerMonth[today.month - 1]) {
    tomorrow.day = today.day + 1;
    tomorrow.month = today.month;
    tomorrow.year = today.year;
  }
  else if(today.month == 12) {
    tomorrow.day = 1;
    tomorrow.month = 1;
    tomorrow.year = today.year + 1;
  }
  else {
    tomorrow.day = 1;
    tomorrow.month = today.month + 1;
    tomorrow.year = today.year;
  }

  printf("Tomorrow's date is %.2d/%.2d/%.2d.\n", tomorrow.month, tomorrow.day,
         tomorrow.year % 100);

  return 0;
}
