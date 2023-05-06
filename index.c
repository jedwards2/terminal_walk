#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

void clearScreen() { printf("\033[2J\033[1;1H"); }

int main(int argc, char **argv) {
  clearScreen();
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

  printf("lines %d\n", w.ws_row);
  printf("columns %d\n", w.ws_col);

  int eighty_row = w.ws_row * 0.8;
  int eighty_col = w.ws_col * 0.8;
  int mid_row = eighty_row / 2;
  int mid_col = eighty_col / 2;
  printf("lines %d\n", eighty_row);
  printf("columns %d\n", eighty_col);
  for (int q = 0; q < eighty_row; q++) {
    for (int i = 0; i < eighty_col; i++) {
      if (i == mid_col && q == mid_row) {
        printf("0");
      } else {
        printf("X");
      }
    }
    printf("\n");
  }
  return 0;
}
