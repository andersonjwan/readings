#include <stdio.h>

/* structure definition(s) */
struct time {
  int hours;
  int minutes;
  int seconds;
};

/* function declaration(s) */
struct time elapsed_time(struct time, struct time);

int main(void) {
  struct time first, second, diff;

  printf("Please enter the first time (HH:MM:SS): ");
  scanf("%i:%i:%i", &first.hours, &first.minutes, &first.seconds);

  printf("Please enter the second time (HH:MM:SS): ");
  scanf("%i:%i:%i", &second.hours, &second.minutes, &second.seconds);

  diff = elapsed_time(first, second);

  printf("Time between: %.2i:%.2i:%.2i\n", diff.hours, diff.minutes, diff.seconds);
  return 0;
}

struct time elapsed_time(struct time firstTime, struct time secondTime) {
  /**
   * elapsed_time determines the amount of time between two times
   * represented in the 24-hour clock cycle.
   */

  auto struct time timeDifference;

  if(secondTime.seconds - firstTime.seconds < 0) {
    timeDifference.seconds = 60 - firstTime.seconds + secondTime.seconds;

    if(secondTime.minutes - firstTime.minutes < 0) {
      timeDifference.minutes = 60 - firstTime.minutes + secondTime.minutes - 1;
    }
    else {
      timeDifference.minutes = secondTime.minutes - firstTime.minutes;
    }
  }
  else {
    timeDifference.seconds = secondTime.seconds - firstTime.seconds;

    if(secondTime.minutes - firstTime.minutes < 0) {
      timeDifference.minutes = 60 - firstTime.minutes + secondTime.minutes;
    }
    else {
      timeDifference.minutes = secondTime.minutes - firstTime.minutes;
    }
  }

  if(timeDifference.minutes == 0) {
    timeDifference.hours = secondTime.hours - firstTime.hours;
  }
  else {
    timeDifference.hours = secondTime.hours - firstTime.hours - 1;
  }

  return timeDifference;
}
