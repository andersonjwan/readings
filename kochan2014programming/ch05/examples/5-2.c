/* Program to calculate the average of a set of grades and count
   the number of failing test grades */
#include <stdio.h>

int main(void) {
  int numberOfGrades, i, grade;
  int gradeTotal = 0;
  int failureCount = 0;
  float average;

  printf("How many grades will you be entering?: ");
  scanf("%d", &numberOfGrades);

  for(i = 1; i <= numberOfGrades; ++i) {
    printf("Enter grade #%d: ", i);
    scanf("%d", &grade);

    gradeTotal += grade;

    if(grade < 65) {
      ++failureCount;
    }
  }

  // calculate average grade
  average = (float) gradeTotal / numberOfGrades;

  printf("\nGrade Average: %.2f\n", average);
  printf("Number of Failures: %d\n", failureCount);

  return 0;
}
