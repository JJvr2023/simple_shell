#include <stdio.h>
#include <stdlib.h>

/* This function resizes the specified memory block to the specified size. */
void *realloc(void *ptr, size_t size) {
  /* Declare a variable to store the new memory block. */
  void *new_ptr = malloc(size);

  /* If the new memory block is NULL, there was an error. */
  if (new_ptr == NULL) {
    return NULL;
  }

  /* If the ptr is not NULL, copy the data from the old memory block to the new memory block. */
  if (ptr != NULL) {
    memcpy(new_ptr, ptr, size);
    free(ptr);
  }

  /* Return the new memory block. */
  return new_ptr;
}

int main() {
  /* Declare a variable to store the old memory block. */
  void *ptr = malloc(100);

  /* Write some data to the old memory block. */
  strcpy(ptr, "Hello, world!");

  /* Resize the memory block to 200 bytes. */
  ptr = realloc(ptr, 200);

  /* Check if the memory block was successfully resized. */
  if (ptr == NULL) {
    printf("Failed to resize the memory block.\n");
    return 1;
  }

  /* Print the new data in the memory block. */
  printf("%s\n", ptr);

  /* Free the memory block. */
  free(ptr);

  return 0;
}
