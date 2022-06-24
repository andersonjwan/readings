#include <stdio.h>

struct doubleNode {
  int data;
  struct doubleNode *prev;
  struct doubleNode *next;
};

void printList(struct doubleNode *);

int main(void) {
  // create node(s)
  struct doubleNode n1, n2, n3, n4, * iterator = &n1;

  // init data
  n1.data = 100;
  n2.data = 200;
  n3.data = 300;
  n4.data = 400;

  // linking
  n1.prev = (struct doubleNode *) 0; // null
  n1.next = &n2;

  n2.prev = &n1;
  n2.next = &n3;

  n3.prev = &n2;
  n3.next = &n4;

  n4.prev = &n3;
  n4.next = (struct doubleNode *) 0; // null

  printList(iterator);
  return 0;
}

void printList(struct doubleNode * iterator) {
  while(iterator != (struct doubleNode *) 0) {
    printf("Data: %i, Previous Address: %p, Next Address: %p\n",
           iterator->data, iterator->prev, iterator->next);

    iterator = iterator->next;
  }
}
