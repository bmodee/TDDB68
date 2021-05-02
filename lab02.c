#include <stdio.h>
#include <stdlib.h>

struct list_item {
  int value;
  struct list_item * next;
};

void append(struct list_item *first, int x){ /* puts x at the end of the list */
  struct list_item* current = first;
  while(current->next != NULL) {
    current = current->next;
  }
  struct list_item *new_item = malloc(sizeof(*new_item));
  new_item->value = x;
  new_item->next = NULL;
  current->next = new_item;
}
void prepend(struct list_item *first, int x){ /* puts x at the beginning of the list */
  struct list_item *new_item = malloc(sizeof(*new_item));
  new_item->value = x;
  new_item->next = first->next;
  first->next = new_item;
}

void print(struct list_item *first){  /* prints all elements in the list */
  struct list_item* current = first;
  while(current != NULL) {
    if(current->value != -1) {
      printf("%d" ", ", current->value);
    }
    current = current->next;
  }
  printf("\n");
}
/* input_sorted: find the first element in the list larger than x
and input x right before that element */
void input_sorted(struct list_item *first, int x){
  struct list_item* current = first;
  while(current->next->value <= x) {
    current = current->next;
  }
  struct list_item *new_item = malloc(sizeof(*new_item));
  new_item->value = x;
  new_item->next = current->next;
  current->next = new_item;
}

void clear(struct list_item *first){ /* free everything dynamically allocated */
  struct list_item* current_item = first;
  struct list_item* next_item = first->next;
  while(next_item != NULL) {
    free(current_item);
    current_item = next_item;
    next_item = next_item->next;
  }
  free(current_item);
}

int main( int argc, char ** argv)
{
  struct list_item *root = malloc(sizeof(*root));
  root->value = -1; /* This value is always ignored */
  root->next = NULL;
  append(root, 1);
  print(root);
  append(root, 69);
  //clear(root);
  prepend(root, 2);
  print(root);
  input_sorted(root, 180);
  print(root);
  clear(root);
};
