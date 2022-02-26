#include <stdio.h>

/* forward declaration(s) */
void scalarMultiply(int nRows, int nCols, int [nRows][nCols], int);
void displayMatrix(int nRows, int nCols, int [nRows][nCols]);

int main(void) {
  int sampleMatrix[5][5] = {{7, 16, 55, 13, 12},
                            {12, 10, 52, 0, 7},
                            {-2, 1, 2, 4, 9},
                            {1, 2, 3, 5, 7},
                            {10, 20, 34, 3, -2}};

  printf("Original Matrix:\n");
  displayMatrix(5, 5, sampleMatrix);

  scalarMultiply(5, 5, sampleMatrix, 2);
  printf("\nMatrix multiplied by 2:\n");
  displayMatrix(5, 5, sampleMatrix);

  scalarMultiply(5, 5, sampleMatrix, -1);
  printf("\nMatrix multiplied by -1:\n");
  displayMatrix(5, 5, sampleMatrix);

  return 0;
}

void scalarMultiply(int nRows, int nCols, int matrix[nRows][nCols], int scalar) {
  auto int row, column;

  for(row = 0; row < nRows; ++row) {
    for(column = 0; column < nCols; ++column) {
      matrix[row][column] *= scalar;
    }
  }
}

void displayMatrix(int nRows, int nCols, int matrix[nRows][nCols]) {
  auto int row, column;

  for(row = 0; row < nRows; ++row) {
    for(column = 0; column < nCols; ++column) {
      printf("%5d", matrix[row][column]);
    }

    printf("\n");
  }
}
