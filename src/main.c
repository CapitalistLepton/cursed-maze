#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include "player.h"

int main() {
  int rows, cols;

  Player *player = malloc(sizeof(Player));
  if (player == NULL) {
    printf("Malloc failed\n");
    return -1;
  }
  player->x = 10;
  player->y = 10;

  initscr();
  getmaxyx(stdscr, rows, cols);
  noecho();
  curs_set(FALSE);
  addstr("Hello");
  move(1, 0);
  printw("%d rows %d cols", rows, cols);

  move(player->y, player->x);
  addch('@');
  refresh();

  getch();

  // End ncurses
  endwin();

  // Free all memory
  free(player);

  return 0;
}
