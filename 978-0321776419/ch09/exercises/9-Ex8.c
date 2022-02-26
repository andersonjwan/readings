#include <stdio.h>
#include <stdbool.h>

int findString(const char[], const char []);
void removeString(char [], int, int);
void insertString(char [], const char [], int);
void replaceString(char [], const char [], const char []);
void findNullCharacter(const char []);

int main(void) {
  char source[] = "this is the 1";
  char source2[] = "they're magically delicious";

  printf("Original String: %s\n", source);

  replaceString(source, "1", "one");
  printf("New String: %s\n", source);

  printf("Original String: %s\n", source2);
  replaceString(source2, "magically", "tastefully");
  printf("New String: %s\n", source2);

  return 0;
}

void replaceString(char source[], const char s1[], const char s2[]) {
  int i = 0, s1Size = 0;

  // determine string size
  while(s1[i] != '\0') {
    ++s1Size, ++i;
  }

  // find string location to be removed
  int s1Location  = findString(source, s1);

  // remove string
  removeString(source, s1Location, s1Size);

  // insert new string
  insertString(source, s2, s1Location);
}

int findString(const char source[], const char search[]) {
  int i, j, jj;
  bool found = false;

  for(i = 0; source[i] != '\0'; ++i) {
    if(source[i] == search[0]) {
      found = true;

      for(j = i, jj = 0; search[jj] != '\0'; ++j, ++jj) {
        if(source[j] == search[jj]) {
          found = true;
        }
        else {
          found = false;
        }
      }

      if(search[jj] == '\0') {
        return i;
      }
    }
    else {
      found = false;
    }
  }

  return -1;
}

void removeString(char string[], int start, int extension) {
  int i, j;
  char tempString[81];

  // transfer characters to tempString
  for(i = 0, j = 0; string[i] != '\0'; ++i) {
    if(i < start || i >= (start + extension)) {
      tempString[j] = string[i];
      ++j;
    }
  }

  // append null characters
  tempString[j] = '\0';

  // write new string to string
  for(i = 0; tempString[i] != '\0'; ++i) {
    string[i] = tempString[i];
  }

  // append null character
  string[i] = '\0';
}

void insertString(char source[], const char insert[], int start) {
  int i, j, k;
  char tempString[81];

  // write up to the start of the insertion point
  for(i = 0, j = 0; i < start; ++i, ++j) {
    tempString[i] = source[j];
  }

  // insert string
  for(k = 0; insert[k] != '\0'; ++k, ++i) {
    tempString[i] = insert[k];
  }

  // append the rest of the source string
  while(source[j] != '\0') {
    tempString[i] = source[j];
    ++i, ++j;
  }

  // append null character
  tempString[i] = '\0';

  // rewrite over source
  for(int i = 0; tempString[i] != '\0'; ++i) {
    source[i] = tempString[i];
  }

  // append null character
  source[i] = '\0';
}

void findNullCharacter(const char string[]) {
  int i = 0;

  while(string[i] != '\0' && i < 81) {
    ++i;
  }

  if(string[i] == '\0') {
    printf("Null character found at %i.\n", i);
  }
  else {
    printf("Null character NOT found at %i.\n", i);
  }
}
