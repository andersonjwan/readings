#include <stdio.h>

int main(void) {
  // file name(s)
  char in_file_name[64], out_file_name[64];

  // file(s)
  FILE *in_file, *out_file;
  int character;

  // prompt for file to be copied
  printf("Enter file name to be copied: ");
  scanf("%63s", in_file_name);

  // prompt for file to be written
  printf("Enter file name to be written: ");
  scanf("%63s", out_file_name);

  // open file(s)
  if((in_file = fopen(in_file_name, "r")) == NULL) {
    fprintf(stderr, "%s does not exist.\n", in_file_name);
    return 1;
  }

  if((out_file = fopen(out_file_name, "w")) == NULL) {
    fprintf(stderr, "%s could not be opened.\n", out_file_name);
    return 2;
  }

  // copy file(s)
  while((character = getc(in_file)) != EOF) {
    if(character >= 'a' && character <= 'z') {
      character = character - 32;

      putc(character, out_file); // write upper to out_file
    }
    else {
      putc(character, out_file); // write to out_file
    }
  }

  // close file(s)
  fclose(in_file);
  fclose(out_file);

  return 0;
}
