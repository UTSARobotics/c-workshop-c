#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORDLIST "english.txt"
// 1/100
#define ODDS 0x10F2C

void printBoard(char *word, int *mask, int wlen, int fails) {
  char board0[] = {
      "\n+-------+\n" // +-------+
      "|       |\n"   // |       |
      "|        \n"   // |       O
      "|        \n"   /* |      /|\ */
      "|        \n"   /* |      /\ */
      "|        \n"   // |
  };

  char board1[] = {
      "\n+-------+\n" // +-------+
      "|       |\n"   // |       |
      "|       O\n"   // |       O
      "|        \n"   /* |      /|\ */
      "|        \n"   /* |      /\ */
      "|        \n"   // |
  };
  char board2[] = {
      "\n+-------+\n" // +-------+
      "|       |\n"   // |       |
      "|       O\n"   // |       O
      "|       |\n"   /* |      /|\ */
      "|        \n"   /* |      /\ */
      "|        \n"   // |
  };
  char board3[] = {
      "\n+-------+\n" // +-------+
      "|       |\n"   // |       |
      "|       O\n"   // |       O
      "|      /|\n"   /* |      /|\ */
      "|        \n"   /* |      /\ */
      "|        \n"   // |
  };
  char board4[] = {
      "\n+-------+\n" // +-------+
      "|       |\n"   // |       |
      "|       O\n"   // |       O
      "|      /|\\\n" /* |      /|\ */
      "|        \n"   /* |      /\ */
      "|        \n"   // |
  };
  // char board5[] = {
  //     "\n+-------+\n" // +-------+
  //     "|       |\n"   // |       |
  //     "|       O\n"   // |       O
  //     "|      /|\\\n" /* |      /|\ */
  //     "|        \n"   /* |      /\ */
  //     "|        \n"   // |
  // };
  char board5[] = {
      "\n+-------+\n" // +-------+
      "|       |\n"   // |       |
      "|       O\n"   // |       O
      "|      /|\\\n" /* |      /|\ */
      "|      / \n"   /* |      /\ */
      "|        \n"   // |
  };
  char board6[] = {
      "\n+-------+\n" // +-------+
      "|       |\n"   // |       |
      "|       O\n"   // |       O
      "|      /|\\\n" /* |      /|\ */
      "|      / \\\n" /* |      /\ */
      "|        \n"   // |
  };

  switch (fails) {
  case 0:
    printf("%s", board0);
    break;
  case 1:
    printf("%s", board1);
    break;
  case 2:
    printf("%s", board2);
    break;
  case 3:
    printf("%s", board3);
    break;
  case 4:
    printf("%s", board4);
    break;
  case 5:
    printf("%s", board5);
    break;
  case 6:
    printf("%s", board6);
    printf("\nYou Lose\nThe correct word was %s\n", word);
    exit(0);

    break;
  // case 7:
  //   printf("%s", board7);
  //   printf("\nYou Lose\nThe correct word was %s\n", word);
  //   exit(0);
  //   break;
  default:
    printf("This is probably an error\n");
    exit(1);
  }

  printf("Word Length: %d\n", wlen);

  for (int i = 0; i < wlen; i++) {
    if (mask[i] == 0) {
      printf("_");
    } else {
      printf("%c", word[i]);
    }
  }

  printf("\n");
}

void playGame(char *word, int wlen) {
  int mask[wlen];
  char guess[wlen];
  int fails = 0;
  // fill mask with 0s
  for (int i = 0; i < wlen; i++)
    mask[i] = 0;

  while (1) {
    printBoard(word, mask, wlen, fails);

    printf("\nType your guess: ");

    fgets(guess, wlen, stdin);

    // win is true be default
    int win = 1;

    // fill mask and test for win
    for (int i = 0; i < wlen; i++) {
      mask[i] = mask[i] == 1 ? 1 : word[i] == guess[i];
      if (mask[i] == 0) {
        win = 0;
      }
    }

    if (!win)
      fails += 1;

    // if win is still true then we win
    if (win == 1) {
      // print final board
      printBoard(word, mask, wlen, fails);

      printf("You Win\n");
      // end game
      return;
    }
  }
}

int main(int argc, char *argv[]) {
  // open our word list file
  FILE *wl = fopen(WORDLIST, "r");
  char word[256];

  srand(time(NULL));

  if (wl == NULL) {
    fprintf(stderr, "File failed to open");
    exit(1);
  }

  while (fgets(word, sizeof(word), wl)) {
    if (rand() % (ODDS + 1) == 311) {
      break;
    }
  }

  // close word list file
  fclose(wl);

  int wlen;

  // get real length of string
  for (int i = 0; word[i] != '\0'; i++)
    wlen = i;

  // remove new line character from end of string
  word[wlen] = '\0';

  playGame(word, wlen);

  return 0;
}
