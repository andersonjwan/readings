#include <stdio.h>

int main(void) {
  const char baseDigits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                               'A', 'B', 'C', 'D', 'E', 'F'};
  int convertedNumber[64];
  long int numberToConvert;
  int nextDigit, base, index = 0;

  // get the number and the base
  printf("Number to be converted? ");
  scanf("%ld", &numberToConvert);

  printf("Base? ");
  scanf("%d", &base);

  // convert to indicated base
  do {
    convertedNumber[index] = numberToConvert % base;
    numberToConvert /= base;

    ++index;
  }
  while(numberToConvert != 0);

  // display the results in reverse order
  printf("Converted Number = ");

  for(--index; index >= 0; --index) {
    nextDigit = convertedNumber[index];
    printf("%c", baseDigits[nextDigit]);
  }

  printf("\n");
  return 0;
}
