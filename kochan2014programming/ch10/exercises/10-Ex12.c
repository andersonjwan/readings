#include <stdio.h>

int main(void) {
  char * message = "Programming in C is fun.\n";
  char message2[] = "You said it.\n";
  char *format = "x = %i\n";
  int x = 100;

  /*** set 1 ***/
  printf("Programming in C is fun.\n");       // valid
  printf("%s", "Programming in C is fun.\n"); // valid
  printf("%s", message);                      // valid
  printf(message);                            // valid

  /*** set 2 ***/
  printf("You said it.\n");                   // valid
  printf("%s", message2);                     // valid
  printf(message2);                           // valid
  printf("%s", &message2[0]);                 // valid

  /*** set 3 ***/
  printf("said it.\n");                       // valid
  printf(message2 + 4);                       // valid - starts at index 4
  printf("%s", message2 + 4);                 // valid - starts at index 4
  printf("%s", &message2[4]);                 // valid - starts at index 4

  /*** set 4 ***/
  printf("x = %i.\n", x);                     // valid
  printf(format, x);                          // valid
  return 0;
}
