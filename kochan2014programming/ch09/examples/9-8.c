#include <stdio.h>
#include <stdbool.h>

/* forward declaration(s) */
void readLine(char []);
bool alphabetic(const char);
int countWords(const char []);

int main(void) {
  char text[81];
  int totalWords = 0;
  bool textEnd = false;

  printf("Type in your text.\n");
  printf("When you are done, press 'RETURN'.\n\n");

  while(!textEnd) {
    readLine(text);

    if(text[0] == '\0') {
      textEnd = true;
    }
    else {
      totalWords += countWords(text);
    }
  }

  printf("\nThere are %i words in the above text.\n", totalWords);
  return 0;
}

void readLine(char buffer[]) {
  char character;
  int i = 0;

  do {
    character = getchar();
    buffer[i] = character;
    ++i;
  }
  while(character != '\n');

  // set null character
  buffer[i - 1] = '\0';
}

bool alphabetic(const char c) {
  if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
    return true;
  }
  else {
    return false;
  }
}

int countWords(const char string[]) {
  int i, wordCount = 0;
  bool lookingForWord = true;

  for(i = 0; string[i] != '\0'; ++i) {
    if(alphabetic(string[i])) {
      if(lookingForWord) {
        /* initial letter of word found,
           traversing the same word */
        ++wordCount;
        lookingForWord = false;
      }
    }
    else {
      /* character is not alphabetic;
         start looking for the start of another
         word */
      lookingForWord = true;
    }
  }

  return wordCount;
}
