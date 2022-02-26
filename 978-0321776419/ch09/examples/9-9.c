#include <stdio.h>
#include <stdbool.h>

/* structure definition(s) */
struct entry {
  char word[15];
  char definition[50];
};

/* forward declaration(s) */
bool equalStrings(const char [], const char []);
int lookup(const struct entry [], const char [], const int);

int main(void) {
  const struct entry dictionary[100] =
    {{"aardvark", "A burrowing African mammal."},
     {"abyss", "A bottomless pit."},
     {"acument", "Mentally sharp; keen."},
     {"addle", "To become confused"},
     {"aerie", "A high nest"},
     {"affix", "To append; attach."},
     {"agar", "A jelly made from seaweed."},
     {"ahoy", "A nautical call of greeting."},
     {"aigrette", "An ornamental cluster of feathers."},
     {"ajar", "Partially opened."}};

  char word[10];
  int entries = 10;
  int entry;

  printf("Enter word search: ");
  scanf("%14s", word);
  entry = lookup(dictionary, word, entries);

  if(entry != -1) {
    printf("%s: %s\n",dictionary[entry].word, dictionary[entry].definition);
  }
  else {
    printf("Sorry, the word %s is not in my dictionary.\n", word);
  }

  return 0;
}

bool equalStrings(const char str1[], const char str2[]) {
  int i = 0;
  bool areEqual;

  // traverse strings and compare character equalities
  while(str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0') {
    ++i;
  }

  // test that the end of both strings have been met
  if(str1[i] == '\0' && str2[i] == '\0') {
    areEqual = true;
  }
  else {
    areEqual = false;
  }

  return areEqual;
}

int lookup(const struct entry dictionary[], const char searchEntry[], const int numEntries) {
  int i;

  for(i = 0; i < numEntries; ++i) {
    if(equalStrings(searchEntry, dictionary[i].word)) {
      return i;
    }
  }

  return -1;
}
