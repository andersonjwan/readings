#include <stdio.h>
#include <stdbool.h>

/* forward declaration(s) */
int findString(const char [], const char []);

int main(void) {
  printf("Location: %i\n", findString("a chatterbox", "hat"));
  return 0;
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
