#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  while (1) {
    printf("Enter programs to run.\n> ");

    read = getline(&line, &len, stdin);

    if (read == -1) {
      break;
    }

    line[strcspn(line, "\n")] = 0;

    pid_t pid = fork();

    if (pid == -1) {
      perror("fork failed");
    } else if (pid == 0) {
      if (execlp(line, line, (char *)NULL) == -1) {
        perror("Exec failure");
        exit(EXIT_FAILURE);
      }
    } else {
      if (waitpid(pid, NULL, 0) == -1) {
        perror("waitpid failed");
      }
    }
  }

  free(line);
  return 0;
}
