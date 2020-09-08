#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include "player.h"
#include "window.h"

#define DELAY 500

int tick = 0;

void init_window() {
  initscr();
  noecho();
  curs_set(FALSE);
}

int get_rows() {
  int rows, cols;
  getmaxyx(stdscr, rows, cols);
  return rows;
}

int get_cols() {
  int rows, cols;
  getmaxyx(stdscr, rows, cols);
  return cols;
}

void draw(Player *player) {
  clear();
  //mvprintw(0, 0, "Tick %d", tick++);
  move(player->y, player->x);
  addch('@');
  refresh();
}

int wait_for_input() {
  int c;
  clock_t start, recieved;

  flushinp(); // Flush out old getch
  start = clock();
  timeout(DELAY);
  c = getch();
  if (c != ERR) {
    recieved = clock() - start;
    if (recieved < DELAY) {
      usleep((DELAY - recieved) * 1000);
    }
    return c;
  } else {
    return -1;
  }
}

void end_window() {
  endwin();
}
