#include <stdio.h>
#include <stdbool.h>

/* struct definition(s) */
struct date {
  int month;
  int day;
  int year;
};

/* forward declaration(s) */
int numberOfDays(struct date);
bool isLeapYear(struct date);


int main(void) {
  struct date today, tomorrow;

  // prompt user
  printf("Enter today's date (mm dd yyyy): ");
  scanf("%d %d %d", &today.month, &today.day, &today.year);

  if(today.day != numberOfDays(today)) {
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
         tomorrow.year);
  return 0;
}

int numberOfDays(struct date todayTemp) {
  auto int days;
  auto const int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31,
                                     31, 30, 31, 30, 31};

  if(isLeapYear(todayTemp) == true && todayTemp.month == 2) {
    days = 29;
  }
  else {
    days = daysPerMonth[todayTemp.month - 1];
  }

  return days;
}

bool isLeapYear(struct date todayTemp) {
  auto bool leapYearFlag;

  if(((todayTemp.year % 4 == 0) && (todayTemp.year % 100 != 0)) ||
     (todayTemp.year % 400 == 0)) {
    leapYearFlag = true;
  }
  else {
    leapYearFlag = false;
  }

  return leapYearFlag;
}
