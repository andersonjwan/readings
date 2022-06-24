#include <stdio.h>

/* forward declaration(s) */
void scalarMultiply(int [][5], int);
void displayMatrix(int [][5]);
int elementSum(int [][5]);

int main(void) {
  int sampleMatrix[3][5] =  { {7, 16, 55, 13, 12},
                              {12, 10, 52, 0, 7},
                              {-2, 1, 2, 4, 9} };

  printf("Original Matrix:\n");
  displayMatrix(sampleMatrix);
  printf("Element Sum: %d\n", elementSum(sampleMatrix));

  scalarMultiply(sampleMatrix, 2);
  printf("\nMatrix multiplied by 2:\n");
  displayMatrix(sampleMatrix);
  printf("Element Sum: %d\n", elementSum(sampleMatrix));

  scalarMultiply(sampleMatrix, -1);
  printf("\nMatrix multipled by -1:\n");
  displayMatrix(sampleMatrix);
  printf("Element Sum: %d\n", elementSum(sampleMatrix));

  return 0;
}

void scalarMultiply(int matrix[][5], int scalar) {
  auto int row, column;

  for(row = 0; row < 3; ++row) {
    for(column = 0; column < 5; ++column) {
      matrix[row][column] *= scalar;
    }
  }
}

int elementSum(int matrix[][5]) {
  auto int row, column, sum = 0;

  for(row = 0; row < 3; ++row) {
    for(column = 0; column < 5; ++column) {
      sum += matrix[row][column];
    }
  }

  return sum;
}

void displayMatrix(int matrix[][5]) {
  auto int row, column;

  for(row = 0; row < 3; ++row) {
    for (column = 0; column < 5; ++column) {
      printf("%5d", matrix[row][column]);
    }

    printf("\n");
  }
}
