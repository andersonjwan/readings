#include <stdio.h>

int main(void) {

  struct node {
    int value;
    struct node *next;
  };

  struct node n1, n2, n3, n4, n5;
  struct node *iterator;

  // set values
  n1.value = 1;
  n2.value = 2;
  n3.value = 3;
  n4.value = 4;
  n5.value = 5;

  // linking
  iterator = &n1; // point to first struct
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = &n5;
  n5.next = (struct node *) 0; // point to NULL

  // traverse linked-list
  while(iterator != (struct node *) 0) {
    printf("Value: %i, Address: %i\n", iterator->value, iterator->next);

    // point to next struct
    iterator = iterator->next; /* sets the pointer of type 'struct node' to pointer
                                  to the next structure address */
  }
  return 0;
}
