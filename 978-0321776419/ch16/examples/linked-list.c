#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct entry {
  int data;
  struct entry * next;
};

/* forward declaration(s) */
struct entry * createList(struct entry *);
struct entry * addEntry(struct entry *);
void printEntries(struct entry *);

int main(void) {
  int value;
  struct entry * iter = NULL, * curr = NULL;

  printf("Linked List Testing; Enter '-1' to exit.\n");
  while(true) {
    printf("Value: ");
    scanf("%d", &value);

    if(value != -1) {
      if(iter == NULL) {
        iter = createList(iter);
        curr = iter;

        iter->data = value;
      }
      else {
        curr = addEntry(iter);
        curr->data = value;
      }
    }
    else {
      break;
    }
  }

  // print list
  printf("Printing List...\n");
  printEntries(iter);

  return 0;
}

struct entry * createList(struct entry * list_ptr) {
  if(list_ptr == NULL) {
    // get storage for new entry
    list_ptr = (struct entry *) malloc(sizeof(struct entry));

    // set next to null
    list_ptr->next = (struct entry *) 0;
  }

  return list_ptr;
}

struct entry * addEntry(struct entry * list_ptr) {
  // find the end of the list
  while(list_ptr->next != NULL) {
    list_ptr = list_ptr->next;
  }

  // get storage for new entry
  list_ptr->next = (struct entry *) malloc(sizeof(struct entry));

  // add null to the new end of the list
  if(list_ptr->next != NULL) {
    (list_ptr->next)->next = (struct entry *) NULL;
  }

  return list_ptr->next;
}

void printEntries(struct entry * list_ptr) {
  if(list_ptr == NULL) {
    printf("No elements within list.\n");
    return;
  }

  // iterate through list
  while(list_ptr != NULL) {
    printf("%d, %p, Next: %p\n", list_ptr->data, list_ptr, list_ptr->next);

    list_ptr = list_ptr->next;
  }
}
