#include <stdio.h>

/* structure definition(s) */
struct date {
  int month;
  int day;
  int year;
};

/* function prototype declaration(s) */
int interFunctionF(struct date);
int interFunctionG(struct date);
int interFunctionN(struct date);
int calcDayDifference(struct date, struct date);

int main(void) {
  struct date first, second;

  printf("Please enter the first date (MM/DD/YYYY): ");
  scanf("%i/%i/%i", &first.month, &first.day, &first.year);

  printf("Please enter the second date (MM/DD/YYYY): ");
  scanf("%i/%i/%i", &second.month, &second.day, &second.year);

  printf("Number of days between dates: %i\n",
         calcDayDifference(first, second));

  return 0;
}

int interFunctionF(struct date current) {
  if(current.month <= 2) {
    return (current.year - 1);
  }
  else {
    return current.year;
  }
}

int interFunctionG(struct date current) {
  if(current.month <= 2) {
    return (current.month + 13);
  }
  else {
    return (current.month + 1);
  }
}

int interFunctionN(struct date current) {
  auto double result;

  result = ((1461 * interFunctionF(current)) / 4) +
    153 * interFunctionG(current) / 5 + current.day;

  return result;
}

int calcDayDifference(struct date firstDate, struct date secondDate) {
  return interFunctionN(secondDate) - interFunctionN(firstDate);
}
