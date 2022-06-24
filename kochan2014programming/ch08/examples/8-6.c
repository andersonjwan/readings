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
  // init array of time structs
  struct time testTimes[5] = {{11, 59, 59}, {12, 0, 0}, {1, 29, 59},
                              {23, 59, 59}, {19, 12, 27}};
  int i = 0;
  for(i = 0; i < 5; ++i) {
    printf("Time is %.2i:%.2i:%.2i", testTimes[i].hour, testTimes[i].minute,
           testTimes[i].second);

    // update time
    testTimes[i] = timeUpdate(testTimes[i]);

    // display new time
    printf("... one second later, it's %.2i:%.2i:%.2i\n", testTimes[i].hour,
           testTimes[i].minute, testTimes[i].second);
  }

  return 0;
}

struct time timeUpdate(struct time now) {
  /**
   * timeUpdate updates the time based on the seconds,
   * minutes, and hours of the passed time. Increments the
   * time by one second.
   */

  ++now.second;   // increment seconds by 1

  if(now.second == 60) {    // next minute
    now.second = 0;
    ++now.minute; // increment minutes by 1

    if(now.minute == 60) { // next hour
      now.minute = 0;
      ++now.hour; // increment hours by 1

      if(now.hour == 24) {  // next day
        now.hour = 0;
      }
    }
  }

  return now;
}
