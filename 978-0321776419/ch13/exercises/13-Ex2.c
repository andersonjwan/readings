#include <stdio.h>

enum month {janurary = 1, february, march, april, may, june, july, august,
            september, october, november, december};

char * monthName(enum month);

int main(void) {
  printf("%s\n", monthName(2));
  printf("%s\n", monthName(5));

  return 0;
}

char * monthName(enum month thisMonth) {
  switch(thisMonth) {
  case 1:
    return "January";
  case 2:
    return "February";
  case 3:
    return "March";
  case 4:
    return "April";
  case 5:
    return "May";
  case 6:
    return "June";
  case 7:
    return "July";
  case 8:
    return "August";
  case 9:
    return "September";
  case 10:
    return "October";
  case 11:
    return "November";
  case 12:
    return "December";
  default:
    return "Unspecified number.";
  }
}
