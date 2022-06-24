#include <stdio.h>

/* structure definition(s) */
struct time {
  int hour;
  int minute;
  int second;
};

/* function prototype declaration(s) */
struct time timeUpdate(struct time);

int main(void) {
  struct time currentTime, futureTime;

  printf("Enter the time (hh:mm:ss): ");
  scanf("%i:%i:%i", &currentTime.hour, &currentTime.minute,
        &currentTime.second);

  // increment time by one second accordingly
  futureTime = timeUpdate(currentTime);

  printf("Updated time is %.2i:%.2i:%.2i\n", futureTime.hour, futureTime.minute,
         futureTime.second);

  return 0;
}

struct time timeUpdate(struct time now) {
  /**
   * timeUpdate updates the time based on the seconds,
   * minutes, and hours of the passed time.
   */

  ++now.second;    // increment seconds by 1

  if(now.second == 60) {   // next minutes
    now.second = 0;

    ++now.minute; // increment minutes by 1

    if(now.minute == 60) { // next hour
      now.minute = 0;

      ++now.hour; // increment hours by 1

      if(now.hour == 24) { // next day
        now.hour = 0;
      }
    }
  }

  return now;
}
