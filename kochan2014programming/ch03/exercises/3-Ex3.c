#include <stdio.h>

int main(void) {
  // the following are invalid constants
  /*
    1. 0x10.5 -> hexadecimal require an exponent, no decimals
    2. 0X0G1 -> hexadecimal requires digits 1 - F, not G
    3. 98.6U -> floating point values cannot be assigned as unsigned
    4. 17777s -> signed values are automatically assumed, therefore explicit statement not necessary
    5. 1.2Fe-7 -> unable to assign scientific notation, hexadecimal, and float all at once
    6. 15,000 -> no commas allowed

  */

  int testConstant = +123;

  printf("The test constant is: %i\n", testConstant);
}
