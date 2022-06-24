#include <stdio.h>
#include <stdbool.h>

struct date {
  int month;
  int day;
  int year;
};

void dateUpdate(struct date *);
int numberOfDays(struct date *);
bool isLeapYear(struct date *);

int main(void) {
  struct date dateToday = {8, 14, 2019};

  printf("Today's Date: %i/%i/%i.\n", dateToday.month, dateToday.day,
         dateToday.year);

  dateUpdate(&dateToday);

  printf("Tomorrow's Date: %i/%i/%i.\n", dateToday.month, dateToday.day,
         dateToday.year);
  return 0;
}

void dateUpdate(struct date * today) {
  if(today->day != numberOfDays(today)) {
    today->day = today->day + 1;
  }
  else if(today->month == 12) {
    today->day = 1;
    today->month = 1;
    today->year = today->year + 1;
  }
  else {
    today->day = 1;
    today->month = today->month + 1;
  }
}

int numberOfDays(struct date * today) {
  int days;
  const int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if(isLeapYear(today) && today->month == 2) {
    days = 29;
  }
  else {
    days = daysPerMonth[today->month - 1];
  }
}

bool isLeapYear(struct date * today) {
  bool isLeapYearFlag;

  if((today->year % 4 == 0 && today->year % 100 != 0) || today->year % 400 == 0) {
    isLeapYearFlag = true;
  }
  else {
    isLeapYearFlag = false;
  }

  return isLeapYearFlag;
}
