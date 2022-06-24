#include <stdio.h>
#include <stdbool.h>

/* forward declaration(s) */
bool alphabetic(const char);
int countWords(const char []);

int main(void) {
  const char text1[] = "Well, here goes.";
  const char text2[] = "And here we go... again.";

  printf("%s - words = %i\n", text1, countWords(text1));
  printf("%s - words = %i\n", text2, countWords(text2));
  return 0;
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
        ++wordCount;
        lookingForWord = false;
      }
    }
    else {
      lookingForWord = true;
    }
  }

  return wordCount;
}
