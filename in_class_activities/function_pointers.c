#include <stdio.h>

void happy(int score) { printf("%d is great!\n", score); }

void sad(int score) { printf("%d sucks!\n", score); }

int main() {
  // Declare function pointer varibale
  void (*my_function)(int);

  // Change value, just like a varibale; no ()
  my_function = happy;

  for (int i = 0; i < 10; i++) {
    // Call it
    my_function(i);
  }

  return 0;
}
