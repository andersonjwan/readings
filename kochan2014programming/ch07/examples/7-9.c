#include <stdio.h>

int minimum(int []);

int main(void) {
  int scores[10], i, minScore;

  printf("Enter 10 scores:\n");

  for(i = 0; i < 10; ++i) {
    scanf("%d", &scores[i]);
  }

  minScore = minimum(scores);
  printf("\nMinimum score is %d\n", minScore);

  return 0;
}

int minimum(int values[10]) {
  auto int minValue, i;

  minValue = values[0];

  for(i = 1; i < 10; ++i) {
    if(values[i] < minValue) {
      minValue = values[i];
    }
  }

  return minValue;
}
