#include <stdio.h>
#include <stdbool.h>

int main(void) {
  char file_name[64], line[80], response;
  int line_count = 0;
  bool read = true;

  // file(s)
  FILE *file_1;

  // prompt for file name
  printf("File Name: ");
  scanf("%s", &file_name[0]);

  // open file(s)
  file_1 = fopen(file_name, "r"); // read-mode

  // read line(s)
  while(read && !feof(file_1)) {
    // read line
    fgets(line, 80, file_1); // store read-line into 'line'

    // print line
    if(line[0] != '\0') {
      fprintf(stdout, "%s", line); // print line to stdout
    }

    // reset line
    line[0] = '\0'; // null character

    // increment 'line_count'
    ++line_count;

    if(line_count >= 20) {
      printf("Response: ");
      scanf(" %c", &response);

      if(response == 'q') {
        read = false;
      }

      line_count = 0;
    }
  }

  // close file(s)
  fclose(file_1);

  return 0;
}
