#include <stdio.h>

struct node {
  int data;
  struct node *next;
};

void insertNode(struct node *, struct node *);
void printList(const struct node *);

int main(void) {
  // create node(s)
  struct node n1, n2, n3;

  // init data
  n1.data = 100;
  n2.data = 200;
  n3.data = 300;

  // linking
  struct node * iterator = &n1; // initial pointer
  n1.next = &n2;
  n2.next = &n3;
  n3.next = (struct node *) 0;  // null

  printf("List Before:\n");
  printList(iterator);

  // insert new node at the end
  struct node newNode = {500, (struct node *) 0};

  insertNode(&newNode, &n2);

  printf("\nList After:\n");
  printList(iterator);
  return 0;
}

void insertNode(struct node * toInsertNode,
                struct node * positionNode) {
  toInsertNode->next = positionNode->next;
  positionNode->next = toInsertNode;
}

void printList(const struct node * iterator) {
  while(iterator != (struct node *) 0) {
    printf("Data: %i, Address: %i\n", iterator->data, iterator->next);

    // next node
    iterator = iterator->next;
  }
}
