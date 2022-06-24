#include <stdio.h>

/* forward declaration(s) */
void transposeMatrix(int nRows, int nCols, int matrix[][nCols],
                    int newMatrix[][nRows]);
void printMatrix(int nRows, int nCols, int matrix[][nCols]);

int main(void) {
  int matrix[4][5] = {{1, 2, 3, 4, 5}, {5, 7, 8, 9, 10}, {11, 12, 13, 14, 15},
                      {17, 18, 19, 20, 21}};
  int newMatrix[5][4];

  printMatrix(4, 5, matrix);

  transposeMatrix(4, 5, matrix, newMatrix);
  printf("\n");
  printMatrix(5, 4, newMatrix);

  return 0;
}

void transposeMatrix(int nRows, int nCols, int matrix[nRows][nCols],
                     int newMatrix[nCols][nRows]) {
  auto int row, column;

  for(row = 0; row < nRows; ++row) {
    for(column = 0; column < nCols; ++column) {
      newMatrix[column][row] = matrix[row][column];
    }
  }
}

void printMatrix(int nRows, int nCols, int matrix[nRows][nCols]) {
  auto int row, column;

  for(row = 0; row < nRows; ++row) {
    for(column = 0; column < nCols; ++column) {
      printf("%3d", matrix[row][column]);
    }

    printf("\n");
  }
}
