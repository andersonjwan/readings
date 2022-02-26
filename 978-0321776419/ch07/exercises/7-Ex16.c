#include <stdio.h>
#include <stdbool.h>

/* forward declaration(s) */
void getNumberAndBase(void);
void convertNumber(void);
void displayConvertedNumber(void);

/* global variable(s) */
int g_convertedNumber[64];
long int g_numberToConvert;
int g_base;
int g_digit = 0;
bool g_mainFlag = true;

int main(void) {
  while(g_mainFlag) {
    getNumberAndBase();

    if(g_mainFlag) {
      convertNumber();
      displayConvertedNumber();
    }

    g_digit = 0;
  }

  return 0;
}

void getNumberAndBase(void) {
  printf("Number to be converted? ");
  scanf("%li", &g_numberToConvert);

  if(g_numberToConvert == 0) {
    g_mainFlag = false;
  }
  else {
    do {
      printf("Base? ");
      scanf("%d", &g_base);

      if(g_base < 2 || g_base > 16) {
        printf("Bad base. Must be between 2 - 16 (inclusive).\n");
      }
    }
    while(g_base < 2 || g_base > 16);
  }
}

void convertNumber(void) {
  do {
    g_convertedNumber[g_digit] = g_numberToConvert % g_base;
    ++g_digit;

    g_numberToConvert /= g_base;
  }
  while(g_numberToConvert != 0);
}

void displayConvertedNumber(void) {
  auto const char baseDigits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
                                    '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  auto int nextDigit;

  printf("Converted Number = ");
  for(--g_digit; g_digit >= 0; --g_digit) {
    nextDigit = g_convertedNumber[g_digit];
    printf("%c", baseDigits[nextDigit]);
  }

  printf("\n");
}
