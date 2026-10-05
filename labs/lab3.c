#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void store_lines(char *history[], int *count, char *new_input) {
  if (*count == 5) {
    free(history[0]);
    for (int i = 1; i < 5; i++) {
      history[i - 1] = history[i];
    }

    (*count)--;
  }

  history[*count] = new_input;
  (*count)++;
}

void print_lines(char *history[], int count) {
  for (int i = 0; i < count; i++) {
    printf("%s", history[i]);
  }
}

int main() {
  char *history[5] = {NULL};
  int count = 0;

  char *line = NULL;
  size_t len = 0;

  printf("Enter input: ");

  while (getline(&line, &len, stdin) != -1) {
    store_lines(history, &count, line);

    if (strcmp(line, "print\n") == 0) {
      print_lines(history, count);
    }

    line = NULL;
    len = 0;

    printf("Enter input: ");
  }

  for (int i = 0; i < count; i++) {
    free(history[i]);
  }

  free(line);
  return 0;
}
