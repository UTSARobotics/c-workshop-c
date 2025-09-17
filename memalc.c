#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("%u\n", sizeof(int));
  printf("%u\n", sizeof(char));
  printf("%u\n", sizeof(double));

  int numbers[6] = {0, 1, 2, 3, 4, 5};

  int *numbers1;

  numbers1 = (int *)malloc(sizeof(int) * 6);

  for (int i = 0; i < 6; i++) {
    numbers1[i] = i;
  }

  for (int j = 0; j < 6; j++) {
    printf("%d\n", numbers1[j]);
  }

  char *str = "my string";

  char *mystr;

  mystr = (char *)malloc(sizeof(char) * 5);

  memcpy(mystr, "grape", 5);

  printf("%s\n", mystr);
}
