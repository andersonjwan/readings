/* The triangular number represents the total number of dots
   necessary to represent a triangle up to a certain row. (i.e. to get
   to the fourth row, you start at 1 and sum every integer from 1 to 4.
   This leads with 1 + 2 + 3 + 4 = 10 dots total).
*/

#include <stdio.h>

int main(void) {
  int triangularNumber;

  triangularNumber = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8;

  printf("The eighth triangular number is %i\n", triangularNumber);

  return 0;
}
