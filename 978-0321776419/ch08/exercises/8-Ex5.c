#include <stdio.h>
#include <stdbool.h>

/* structure definition(s) */
struct date {
  int month;
  int day;
  int year;
};

struct time {
  int hours;
  int minutes;
  int seconds;
};

struct dateAndTime {
  struct date sdate;
  struct time stime;
};

/* forward declaration(s) */
struct time timeUpdate(struct time);
struct date dateUpdate(struct date);
int numberOfDays(struct date);
bool isLeapYear(struct date);
struct dateAndTime clockKeeper(struct dateAndTime);

int main(void) {
  struct dateAndTime first, next;
  printf("Please enter the date (MM/DD/YYYY): ");
  scanf("%i/%i/%i", &first.sdate.month, &first.sdate.day, &first.sdate.year);
  printf("Please enter the time (HH:MM:SS): ");
  scanf("%i:%i:%i", &first.stime.hours, &first.stime.minutes,
        &first.stime.seconds);

  next = clockKeeper(first);

  printf("+1sec: %.2i/%.2i/%.4i, %.2i:%.2i:%.2i\n", next.sdate.month,
         next.sdate.day, next.sdate.year, next.stime.hours,
         next.stime.minutes, next.stime.seconds);

  return 0;
}

struct time timeUpdate(struct time current) {
  /**
   * timeUpdate updates the time structure held within the
   * dateAndTime structure based on the seconds, minutes, and
   * hours of the passed time - increments the time by one
   * second.
   */

  ++current.seconds; //   increment seconds by 1

  if(current.seconds == 60) {   // next minute
    current.seconds = 0;
    ++current.minutes; // increment minutes by 1

    if(current.minutes == 60) { // next hour
      current.minutes = 0;
      ++current.hours; // increment hours by 1

      if(current.hours == 24) { // next day
        current.hours = 0;
      }
    }
  }

  return current;
}

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

struct dateAndTime clockKeeper(struct dateAndTime current) {
  // update time
  current.stime = timeUpdate(current.stime); // pass time structure

  if(current.stime.hours == 0 && current.stime.minutes == 0 &&
     current.stime.seconds == 0) {
    current.sdate = dateUpdate(current.sdate);
  }

  return current;
}
