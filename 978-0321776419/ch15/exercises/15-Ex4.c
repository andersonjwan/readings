#include <stdio.h>

int main(void) {
  char f1_name[64], f2_name[64];
  char line[80];

  // file pointer(s)
  FILE *f1, *f2;

  // prompt for file name(s)
  printf("First File: ");
  scanf("%63s", &f1_name[0]);
  printf("Second File: ");
  scanf("%63s", &f2_name[0]);

  // open file(s)
  if((f1 = fopen(f1_name, "r")) == NULL) {
    printf("Unable to open %s.\n", f1_name);
  }

  if((f2 = fopen(f2_name, "r")) == NULL) {
    printf("Unable to open %s.\n", f2_name);
  }

  // interlace files to stdout
  while(!feof(f1) || !feof(f2)) {
    // print from first file
    if((fgets(line, 80, f1)) != NULL) {
      fprintf(stdout, "%s", line);
    }

    // print from second file
    if((fgets(line, 80, f2)) != NULL) {
      fprintf(stdout, "%s", line);
    }
  }

  // close file(s)
  fclose(f1);
  fclose(f2);

  return 0;
}
