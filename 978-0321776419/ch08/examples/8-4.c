#include <stdio.h>
#include <stdbool.h>

/* struct definition(s) */
struct date {
  int month;
  int day;
  int year;
};

/* forward declaration(s) */
struct date dateUpdate(struct date);
int numberOfDays(struct date);
bool isLeapYear(struct date);

/* MAIN FUNCTION */
int main(void) {
  struct date today, tomorrow;

  printf("Enter today's date (mm dd yyyy): ");
  scanf("%d %d %d", &today.month, &today.day, &today.year);

  tomorrow = dateUpdate(today);

  printf("Tomorrow's date is %.2d/%.2d/%.2d.\n", tomorrow.month, tomorrow.day,
         tomorrow.year);
  return 0;
}


/* FUNCTION(S) */
struct date dateUpdate(struct date today) {
  auto struct date tomorrow;

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

  return tomorrow;
}

int numberOfDays(struct date today) {
  auto int days;
  auto const int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30,
                                     31, 30, 31};

  if(isLeapYear(today) && today.month == 2) {
    days = 29;
  }
  else {
    days = daysPerMonth[today.month - 1];
  }

  return days;
}

bool isLeapYear(struct date today) {
  auto bool isLeapYearFlag;

  if((today.year % 4 == 0 && today.year % 100 != 0) || today.year % 400 == 0) {
    isLeapYearFlag = true;
  }
  else {
    isLeapYearFlag = false;
  }

  return isLeapYearFlag;
}
