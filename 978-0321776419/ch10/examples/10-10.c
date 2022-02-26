#include <stdio.h>

struct node {
  int data;
  struct node *next;
};

struct node * findEntry(struct node *, int);

int main(void) {
  struct node n1, n2, n3;
  struct node *iterator, *initList = &n1;

  int search;

  n1.data = 100;
  n1.next = &n2;
  n2.data = 200;
  n2.next = &n3;
  n3.data = 300;
  n3.next = (struct node *) 0;

  printf("Enter value to locate: ");
  scanf("%i", &search);

  iterator = findEntry(initList, search);

  if(iterator != (struct node *) 0) {
    printf("Found %i.\n", iterator->data);
  }
  else {
    printf("Not found.\n");
  }

  return 0;
}

struct node * findEntry(struct node * list, int match) {
  while(list != (struct node *) 0) {
    if(list->data == match) {
      return (list);
    }
    else {
      list = list->next;
    }
  }

  return (struct node *) 0;
}
