#include <stdio.h>

/* structure definition(s) */
struct entry {
  char word[15];
  char definition[50];
};

/* forward declaration(s) */
int compareStrings(const char [], const char []);
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

  char word[15];
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

int compareStrings(const char s1[], const char s2[]) {
  int i = 0, answer;

  while(s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0') {
    ++i;
  }

  if(s1[i] < s2[i]) {
    answer = -1;
  }
  else if(s1[i] > s2[i]) {
    answer = 1;
  }
  else {
    answer = 0;
  }

  return answer;
}

int lookup(const struct entry dictionary[], const char termSearch[],
           const int numEntries) {
  int low = 0;
  int high = numEntries - 1;
  int mid, result;

  while(low <= high) {
    mid = (low + high) / 2;
    result = compareStrings(dictionary[mid].word, termSearch);

    if(result == -1) {
      low = mid + 1;
    }
    else if(result == 1) {
      high = mid - 1;
    }
    else {
      return mid;
    }
  }

  return -1;
}
