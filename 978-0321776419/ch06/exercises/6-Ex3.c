#include <stdio.h>

int main(void) {
  int ratingCounters[10], i, response;

  /* init indices to 0 */
  for(i = 0; i < 10; ++i) {
    ratingCounters[i] = 0;
  }

  /* prompt */
  printf("Enter your reponses:\n");
  printf("(Enter 999 to exit input responses.)\n");

  do {
    scanf("%d", &response);

    if(response < 1 || response > 10) {
      printf("Bad response. Try again.\n");
    }
    else {
      ++ratingCounters[response - 1];
    }
  }
  while(response != 999);

  printf("\n\nRating\t\tNumber of Responses\n");
  printf("---------\t--------------------\n");

  for(i = 0; i < 10; ++i) {
    printf("%4d%14d\n", i + 1, ratingCounters[i]);
  }

  return 0;
}
