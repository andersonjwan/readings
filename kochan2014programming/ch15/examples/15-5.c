#include <stdio.h>

int main(void) {
  char file_inName[64], file_outName[64];

  // file pointer(s)
  FILE *in_file, *out_file;
  int character;

  // get file names from user
  printf("Enter name of file to be copied: ");
  scanf("%63s", file_inName);

  printf("Enter name of output file: ");
  scanf("%63s", file_outName);

  // open file(s)

  in_file = fopen(file_inName, "r");

  // test that file was opened correctly
  if(in_file == NULL) {
    printf("Can't open %s for reading.\n", file_inName);
    return 1;
  }

  out_file = fopen(file_outName, "w");

  // test that file was opened correctly
  if(out_file == NULL) {
    printf("Can't open %s for writing.\n", file_outName);
    return 2;
  }

  // copy file content(s)
  while((character = getc(in_file)) != EOF) {
    putc(character, out_file); // place character into output file
  }

  // close file(s)
  fclose(in_file);
  fclose(out_file);

  printf("File has been copied.\n");

  return 0;
}
