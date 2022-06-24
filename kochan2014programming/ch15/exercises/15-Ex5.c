#include <stdio.h>

int main(void) {
  char f_name[64], character;
  int m, n, col_pos = 0;
  FILE *file_in;

  // prompt for column width
  printf("Starting column: ");
  scanf("%d", &m);
  printf("Ending column: ");
  scanf("%d", &n);

  // prompt for file name
  printf("File Name: ");
  scanf("%s", f_name);

  // open file
  if((file_in = fopen(f_name, "r")) == NULL) {
    printf("Unable to open %s.\n", f_name);
    return 1;
  }

  while(!feof(file_in)) {
    // move up to column starting point
    while(col_pos < m) {
      character = getc(file_in);
      ++col_pos;
    }

    // print specified column width
    while(col_pos >= m && col_pos <= n) {
      character = getc(file_in);

      // test for end line and file condition(s)
      if(character == '\n' || character == EOF) {
        break;
      }

      fprintf(stdout, "%c", character);
      ++col_pos;
    }

    if(character == '\n') {
      // newline
      fprintf(stdout, "\n");

      //character = getc(file_in); // read after newline character
      col_pos = 0;
    }
    else {
      // move to the end of the line
      do {
        character = getc(file_in);
      }
      while(character != '\n' && character != EOF);
    }
  }

  // close file
  fclose(file_in);

  return 0;
}
