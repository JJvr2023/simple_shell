#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This function prints the contents of the specified linked list. */
void print_list(struct node *head) {
  /* Declare a variable to traverse the linked list. */
  struct node *current = head;

  /* If the linked list is empty, print a message. */
  if (current == NULL) {
    printf("The list is empty.\n");
    return;
  }

  /* Print the contents of the linked list. */
  while (current != NULL) {
    printf("%s\n", current->data);
    current = current->next;
  }
}

/* This function creates a new node with the specified data. */
struct node *new_node(char *data) {
  /* Declare a new node. */
  struct node *new = malloc(sizeof(struct node));

  /* Initialize the node. */
  new->data = data;
  new->next = NULL;

  return new;
}

/* This function inserts a new node with the specified data at the
 * beginning of the linked list. */
void insert_at_beginning(struct node **head, char *data) {
  /* Create a new node with the specified data. */
  struct node *new = new_node(data);

  /* Set the new node's next pointer to the current head of the list. */
  new->next = *head;

  /* Set the new node as the new head of the list. */
  *head = new;
}

int main() {
  /* Declare a variable to store the head of the linked list. */
  struct node *head = NULL;

  /* Insert some nodes into the linked list. */
  insert_at_beginning(&head, "Hello");
  insert_at_beginning(&head, "World");
  insert_at_beginning(&head, "!");

  /* Print the contents of the linked list. */
  print_list(head);

  /* Delete the linked list. */
  while (head != NULL) {
    struct node *temp = head;
    head = head->next;
    free(temp);
  }

  return 0;
}
