#include <stdio.h>

int main(void) {
  int values[10]; // array declaration of size 10
  int index;

  values[0] = 197;
  values[2] = -100;
  values[5] = 350;
  values[3] = values[0] + values[5];
  values[9] = values[5] / 10;
  --values[2];

  /* print array content(s) */
  for(index = 0; index < 10; ++index) {
    printf("values[%d] = %d\n", index, values[index]);
  }

  return 0;
}
