#include <stdio.h>

/* This function reads a line from the specified stream into the
 * specified buffer. The buffer must be large enough to hold
 * the entire line, including the terminating newline character.
 *
 * Returns the length of the line, or -1 on error. */
int getline(char *buffer, size_t size, FILE *stream) {
  /* Initialize the variables. */
  int c = 0;
  size_t i = 0;

  /* Loop until we reach the end of the line or the buffer is full. */
  while (i < size && c != '\n') {
    /* Read the next character from the stream. */
    c = getc(stream);

    /* If we reached the end of the file, return -1. */
    if (c == EOF) {
      return -1;
    }

    /* Otherwise, add the character to the buffer. */
    buffer[i++] = c;
  }

  /* If we reached the end of the buffer before the end of the line,
   * truncate the line and add a terminating newline character. */
  if (i == size) {
    buffer[i - 1] = '\n';
  }

  /* Return the length of the line. */
  return i;
}

/* int main() */ {
  char buffer[1024];
  int length;

  /* Read a line from the standard input. */
  length = getline(buffer, sizeof(buffer), stdin);

  /* If the line was successfully read, print it. */
  if (length > 0) {
    printf("The line is: \"%s\"\n", buffer);
  }

  return 0;
}
