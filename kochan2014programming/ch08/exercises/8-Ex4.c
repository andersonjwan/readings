#include <stdio.h>

/* struct definition(s) */
struct date {
  int month;
  int day;
  int year;
};

/* functino prototype declaration(s) */
int interFunctionF(struct date);
int interFunctionG(struct date);
int interFunctionN(struct date);
void translateDay(struct date);

int main(void) {
  struct date first;

  printf("Pleaser enter the date (MM/DD/YYYY): ");
  scanf("%i/%i/%i", &first.month, &first.day, &first.year);

  printf("%i/%i/%i is a ", first.month, first.day, first.year);
  translateDay(first);
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

void translateDay(struct date current) {
  auto int result;

  result = interFunctionN(current) - 621049;
  result %= 7; // result = 0 to 6 (inclusive)

  switch(result) {
  case 0: {
    printf("Sunday.\n");
    return;
  }
    break;
  case 1: {
    printf("Monday.\n");
    return;
  }
    break;
  case 2: {
    printf("Tuesday.\n");
    return;
  }
    break;
  case 3: {
    printf("Wednesday.\n");
    return;
  }
    break;
  case 4: {
    printf("Thursday.\n");
    return;
  }
    break;
  case 5: {
    printf("Friday.\n");
    return;
  }
    break;
  case 6: {
    printf("Saturday.\n");
    return;
  }
    break;
  default: {
    printf("No corresponding weekday for %i.\n", result);
    return;
  }
    break;
  }
}
