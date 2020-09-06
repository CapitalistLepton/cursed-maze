#include <ncurses.h>
#include <unistd.h>
#include "player.h"
#include "window.h"

void init_window() {
  int rows, cols;
  initscr();
  getmaxyx(stdscr, rows, cols);
  noecho();
  curs_set(FALSE);
  addstr("Hello");
  move(1, 0);
  printw("%d rows %d cols", rows, cols);
  refresh();
}

void draw(Player *player) {
  move(player->y, player->x);
  addch('@');
  refresh();
  getch();
}

void end_window() {
  endwin();
}
