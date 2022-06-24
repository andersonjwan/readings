#include <stdio.h>

struct node {
  int data;
  struct node * next;
};

void sort3(struct node *);
void printList(const struct node *);

int main(void) {
  // create node(s)
  struct node n1, n2, n3;

  // set data value(s)
  n1.data = 400;
  n2.data = 75;
  n3.data = 100;

  // linking
  n1.next = &n2;
  n2.next = &n3;
  n3.next = (struct node *) 0;

  printf("Before:\n");
  printList(&n1);

  sort3(&n1);

  printf("\nAfter:\n");
  printList(&n1);

  return 0;
}

void sort3(struct node * iterator) {
  int temp;
  struct node * iterator_2 = iterator->next;

  for( ; iterator->next != (struct node *) 0; iterator = iterator->next) {
    for(iterator_2 = iterator->next; iterator_2 != (struct node *) 0;
        iterator_2 = iterator_2->next) {
      if(iterator->data > iterator_2->data) {
        temp = iterator->data;
        iterator->data = iterator_2->data;
        iterator_2->data = temp;
      }
    }
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
