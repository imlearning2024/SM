#include <stdio.h>

int puzzle[9][9] = {{3, 0, 0, 0, 2, 0, 0, 7, 0}, 
                    {9, 0, 0, 5, 0, 0, 0, 1, 4},
                    {0, 1, 6, 3, 7, 0, 0, 0, 8},
                    {2, 0, 0, 8, 0, 0, 0, 0, 1},
                    {5, 0, 0, 0, 4, 1, 8, 0, 0},
                    {0, 8, 9, 0, 0, 0, 0, 5, 0},
                    {0, 0, 5, 0, 1, 0, 2, 8, 0},
                    {0, 4, 0, 0, 0, 6, 0, 9, 3},
                    {7, 3, 1, 0, 8, 2, 0, 0, 0}};

void print_puzzle(int p[9][9]);

int main() {
  print_puzzle(puzzle);
  return 0;
}

void print_puzzle(int p[9][9]) {

  printf("\n\n+-------+--------+--------+-------+");

  for (int row = 0; row < 9; row++) {

    for (int col = 0; col < 9; col++) {

      if (col % 3 == 0) {
        printf("|");
      }
      printf(" %d", p[row][col]);
    }
    printf("|");
    printf("\n");
  }
  printf("\n\n+-------+--------+--------+-------+");
}
