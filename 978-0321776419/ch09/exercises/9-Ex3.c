#include <stdio.h>
#include <stdbool.h>

/* forward declaration(s) */
void readLine(char []);
bool alphabetic(const char);
int countWords(const char []);

int main(void) {
  char lineText[81];
  int totalWords = 0;
  bool textEnd = false;

  printf("Type in your text:\n");
  printf("Press 'Return' when finished.\n");
  printf("\n>> ");

  while(!textEnd) {
    readLine(lineText);

    if(lineText[0] == '\0') {
      textEnd = true;
    }
    else {
      totalWords += countWords(lineText);
    }
  }

  printf("Total Words: %i.\n", totalWords);
  return 0;
}

void readLine(char buffer[]) {
  int i = 0;

  do {
    buffer[i] = getchar();
    ++i;
  }
  while(buffer[i - 1] != '\n');

  buffer[i - 1] = '\0';
}

bool alphabetic(const char c) {
  if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
    return true;
  }
  else if(c == '\'' || c == '-') {
    return true;
  }

  return false;
}

int countWords(const char line[]) {
  int i, wordCount = 0;
  bool searchingWord = true;

  for(i = 0; line[i] != '\0'; ++i) {
    if(line[i] == '{' || line[i] == '(') {
      ++wordCount;
      searchingWord = false;
    }
    else if(alphabetic(line[i])) {
      if(searchingWord) {
        ++wordCount;
        searchingWord = false;
      }
    }
    else {
      searchingWord = true;
    }
  }

  return wordCount;
}
