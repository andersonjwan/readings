#include <stdio.h>

int main(void) {

  struct entry {
    int value;
    struct entry *next;
  };

  struct entry n1, n2, n3;
  struct entry *linked_list_start = &n1; // point to START

  n1.value = 100;
  n1.next = &n2;

  n2.value = 200;
  n2.next = &n3;

  n3.value = 300;
  n3.next = (struct entry *) 0; // point to NULL

  while(linked_list_start != (struct entry *) 0) {
    printf("%i\n", linked_list_start->value);
    linked_list_start = linked_list_start->next;
  }

  return 0;
}
