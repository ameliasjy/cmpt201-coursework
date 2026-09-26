#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();

  // Who am I?
  if (pid == 0) {
    printf("CHILD:  PID=%d, parent PID=%d\n", getpid(), getppid());
    // execlp("ls", "ls", "-a", NULL)

    // char *const args[] = {"ls", "-a", 0};
    // execvp("LS", args);

    char *args[] = {"echo", "hello", "world", NULL};
    execvp("echo", args);

  } else {
    printf("PARENT: PID=%d, child PID=%d\n", getpid(), pid);
    execlp("ls", "ls", "-a", "-l", "-h", NULL);
  }
}
