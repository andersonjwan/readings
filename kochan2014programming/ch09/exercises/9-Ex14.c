#include <stdio.h>
#include <stdbool.h>

void intToStr(int, char []);

int main(void) {
  char string[10];
  int num = 123;

  intToStr(num, string);

  printf(" %i  ->  %s\n", num, string);
  printf("[int]   [string]\n");
  return 0;
}

void intToStr(int num, char string[]) {
  bool isNegative;
  int rightDigit, digitCount = 0, i = 0, j = 0;
  char tempString[20];

  // test negativity
  if(num < 0) {
    isNegative = true, num *= -1;
  }
  else {
    isNegative = false;
  }

  do {
    rightDigit = num % 10;
    num = num / 10;

    ++digitCount;
    tempString[i] = rightDigit + '0';
    ++i;
  }
  while(num != 0);

  // reverse string
  for(i = 0, j = digitCount - 1; j >= 0; ++i, --j) {
    string[i] = tempString[j];
  }

  // append null character
  string[i] = '\0';
}
