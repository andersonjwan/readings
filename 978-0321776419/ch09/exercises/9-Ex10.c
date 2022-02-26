#include <stdio.h>

struct entry {
  char word[15];
  char definition[25];
};

void dictionarySort(struct entry [], const int);
int compareTo(const char [], const char []);
void printDictionary(struct entry [], const int);

int main(void) {
  struct entry dictionary[100] =
    {{"apple", "fruit"},
     {"banana", "fruit"},
     {"apricot", "fruit"},
     {"tomato", "vegetable"},
     {"orange", "fruit"},
     {"lettuce", "vegetable"},
     {"carrot", "vegetable"}};

  printf("Original List:\n");
  printDictionary(dictionary, 7);

  printf("====================\n");
  dictionarySort(dictionary, 7);
  printf("Sorted List:\n");
  printDictionary(dictionary, 7);
  return 0;
}

void dictionarySort(struct entry dictionary[], const int entryCount) {
  int i, j;
  struct entry tempEntry;

  for(i = 0; i < entryCount - 1; ++i) {
    for(j = i + 1; j < entryCount; ++j) {
      if(compareTo(dictionary[i].word, dictionary[j].word) == 1) {
        tempEntry = dictionary[i];
        dictionary[i] = dictionary[j];
        dictionary[j] = tempEntry;
      }
    }
  }
}

int compareTo(const char entry1[], const char entry2[]) {
  int i = 0, result;

  while(entry1[i] == entry2[i] && entry1[i] != '\0') {
    ++i;
  }

  if(entry1[i] < entry2[i]) {
    result = -1; // entry1 comes before lexigraphically
  }
  else if(entry1[i] > entry2[i]) {
    result = 1; // entry1 comes after lexigraphically
  }
  else {
    result = 0; // entry1 and entry2 are equivalent
  }

  return result;
}

void printDictionary(struct entry dictionary[], const int entryCount) {
  int i;

  for(i = 0; i < entryCount; ++i) {
    printf("%s: %s\n", dictionary[i].word, dictionary[i].definition);
  }
}
