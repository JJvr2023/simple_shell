#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This function gets the user's name and age from the standard input. */
void getinfo(char *name, int *age) {
  /* Prompt the user for their name. */
  printf("What is your name? ");

  /* Read the user's name into the buffer. */
  fgets(name, 256, stdin);

  /* Remove the newline character from the end of the name. */
  name[strcspn(name, "\n")] = '\0';

  /* Prompt the user for their age. */
  printf("How old are you? ");

  /* Read the user's age into the integer pointer. */
  scanf("%d", age);
}

int main() {
  /* Declare variables to store the user's name and age. */
  char name[256];
  int age;

  /* Get the user's information. */
  getinfo(name, &age);

  /* Print the user's information. */
  printf("Your name is: %s\n", name);
  printf("You are %d years old.\n", age);

  return 0;
}
