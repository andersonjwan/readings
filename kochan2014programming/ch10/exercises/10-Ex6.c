#include <stdio.h>

struct doubleNode {
  int data;
  struct doubleNode *prev;
  struct doubleNode *next;
};

void printList(struct doubleNode *);
void insertNode(struct doubleNode *, struct doubleNode *);
void removeNode(struct doubleNode *);
struct doubleNode * getIterator(struct doubleNode *);

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

  // display initialized contents
  printList(getIterator(iterator));

  /* insert new node(s) */
  struct doubleNode n5, n6, n7;

  // init data for new node(s)
  n5.data = 500;
  n6.data = 600;
  n7.data = 700;

  // insert node(s)
  insertNode(&n5, &n3); // insert between 2 and 3
  insertNode(&n6, &n1); // insert before 1
  insertNode(&n7, &n5); // insert between 2 and 5

  printf("\nAfter Insertion:\n");
  printList(getIterator(iterator));

  /* remove node(s) */
  removeNode(&n1);
  removeNode(&n2);
  removeNode(&n3);

  printf("\nAfter Removal:\n");
  printList(getIterator(iterator));
  return 0;
}

void printList(struct doubleNode * iterator) {
  while(iterator != (struct doubleNode *) 0) {
    printf("Data: %i, Previous Address: %p, Next Address: %p\n",
           iterator->data, iterator->prev, iterator->next);

    iterator = iterator->next;
  }
}

void insertNode(struct doubleNode * new_node,
                struct doubleNode * position_node) {
  // set the new node
  new_node->next = position_node; // shifting right

  // set the previous node
  if(position_node->prev != (struct doubleNode *) 0) {
    new_node->prev = position_node->prev;
    position_node->prev->next = new_node;
  }
  else {
    new_node->prev = (struct doubleNode *) 0;
  }

  // set the next node
  position_node->prev = new_node;
}

void removeNode(struct doubleNode * node_to_remove) {
  if(node_to_remove->prev != (struct doubleNode *) 0) {
    // point the previous node to the node after
    node_to_remove->prev->next = node_to_remove->next;
  }
  else {
    node_to_remove->next->prev = (struct doubleNode *) 0;
  }
}

struct doubleNode * getIterator(struct doubleNode * node) {
  // returns a pointer to the first node of the linked list
  while(node->prev != (struct doubleNode *) 0) {
    node = node->prev;
  }

  return node;
}
