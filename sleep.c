#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
  fork();

  char *message = "Hello world!\n";

  for (int i = 0; i < strlen(message); i++) {
    printf("Sleeping\n");
    sleep(2);
  }

  printf("DONE\n");
}
