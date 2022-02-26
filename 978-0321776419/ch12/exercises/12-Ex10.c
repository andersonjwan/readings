#include <stdio.h>

#define printx(n) printf("%i\n", x ## n)

int main(void) {
  int i;

  int x1 = 1, x2 = 2, x3 = 3, x4 = 4, x5 = 5;

  for(i = 1; i < 6; ++i) {
    printx(i);
  }

  return 0;
}

/* No. The for loop is not able to display a list of variables
 * from x1-x100. This is due to the case that the macro simply passes
 * 'i' as the parameter and not the actual value; therefore, the printf
 * statement attempts to print the value stored in 'xi' which does not
 * exist.
 */
