// "C PROGRAMMING LANGUAGE" by Brian W. Kernighan and Dennis M. Ritchie

// Exercise 1-13. Write a program to print a histogram of the lengths of words
// in its input. It is easy to draw the histogram with the bars horizontal;
// a vertical orientation is more challenging.

#include <stdio.h>

#define IN 1           // we are in a word
#define OUT 0          // we are out of a word
#define MAX_LENGTH 20  // The maximum length of a word

int main(void) {
  int i, c, state, count;
  int length[MAX_LENGTH];

  for (i = 0; i < MAX_LENGTH; ++i) {
    length[i] = 0;
  }

  // divide input into separate words by eliminating spaces, blank lines, tabs
  state = OUT;
  count = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == '\t' || c == ' ') {
      // if length of a word > length of array then put this word at the end;
      if (state) {
        if (count > MAX_LENGTH) {
          ++length[MAX_LENGTH - 1];
        } else {
          ++length[count];
        }
        count = 0;
        state = OUT;
      }
    } else {
      ++count;
      state = IN;
    }
  }

  // count last word if input ends with EOF without new line
  if (state) {
    if (count > MAX_LENGTH) {
      ++length[MAX_LENGTH - 1];
    } else {
      ++length[count];
    }
  }

  // represening array of ints as vertical histogram
  int temp = 0;
  for (i = 0; i < MAX_LENGTH; ++i) {
    if (length[i] > temp) {
      c = temp = length[i];
    }
  }
  printf("   ======Histogram of word lengths======\n");
  printf("\n");
  printf(" |-the number of words in the text\n");
  printf(" V\n");
  while (c > 0) {
    for (i = 1; i < MAX_LENGTH; ++i) {
      if (i == 1) printf("%2d ", c);
      if (length[i] >= c)
        printf("== ");
      else
        printf(".. ");
    }
    --c;
    putchar('\n');
  }
  printf("->");
  for (i = 1; i < MAX_LENGTH; ++i) {
    printf("%3d", i);
  }
  putchar('\n');
  printf("|-the number of letters in word\n");
  printf(
      "The last column represents all words which contain more letters than"
      " the array length!\n");
  putchar('\n');
}