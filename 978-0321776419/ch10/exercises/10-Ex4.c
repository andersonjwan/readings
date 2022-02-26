#include <stdio.h>

struct node {
  int data;
  struct node *next;
};

void removeNode(struct node *);
void printList(const struct node *);

int main(void) {
  // created node(s)
  struct node * iterator, head, n1, n2, n3;

  // init data
  iterator = &n1;
  head.data = -1;
  n1.data = 100;
  n2.data = 200;
  n3.data = 300;

  // linking
  head.next = &n1;
  n1.next = &n2;
  n2.next = &n3;
  n3.next = (struct node *) 0; // null

  printf("List Before:\n");
  printList(iterator);

  printf("\nRemoving %i...\n", n2.data);
  removeNode(&n1); // remove node after n1
  printf("List After:\n");
  printList(iterator);

  printf("\nRemoving %i...\n", n3.data);
  removeNode(&n1);
  printf("List After:\n");
  printList(iterator);

  return 0;
}

void removeNode(struct node * ref_node) {
  if(ref_node->next->next != (struct node *) 0) {
    // node exists after the node to be removed
    ref_node->next = ref_node->next->next;
  }
  else {
    // node does not exist after the node to be removed
    ref_node->next = (struct node *) 0;
  }
}

void printList(const struct node * iterator) {
  while(iterator != (struct node *) 0) {
    if(iterator->data != -1) {
      printf("Data: %i, Address: %p\n", iterator->data, iterator->next);
    }

    // next node
    iterator = iterator->next;
  }
}
