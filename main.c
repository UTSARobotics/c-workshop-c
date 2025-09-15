#include <stdio.h>
#include <stdlib.h>

#define WORDLIST "english.txt"

int main(int argc, char *argv[]) {
  // open our word list file
  FILE *wl = fopen(WORDLIST, "r");

  // close word list file
  fclose(wl);

  return 0;
}
