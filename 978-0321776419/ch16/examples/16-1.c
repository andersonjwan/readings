#include <stdio.h>

int main(int argc, char * argv[]) {
  FILE *input, *output;
  int character;

  if(argc != 3) {
    fprintf(stderr, "Two file names not supplied.\n");
    return 1;
  }

  if((input = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Unable to read %s.\n", argv[1]);
    return 2;
  }

  if((output = fopen(argv[2], "w")) == NULL) {
    fprintf(stderr, "Unable to write %s.\n", argv[2]);
    return 3;
  }

  while((character = getc(input)) != EOF) {
    putc(character, output);
  }

  printf("%s has been copied into %s.\n", argv[1], argv[2]);

  // close file(s)
  fclose(input);
  fclose(output);

  return 0;
}
