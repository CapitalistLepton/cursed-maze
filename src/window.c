#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include "entity.h"
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

void draw(World *world) {
  int i, length;
  Entity *entity;

  clear();
  //mvprintw(0, 0, "Tick %d", tick++);
  length = world->width * world->height * sizeof(Entity);
  for (i = 0; i < length; i += sizeof(Entity)) {
    entity = world->entities + i;
    if (entity->y != -1 && entity->x != -1) {
      move(entity->y, entity->x);
      switch (entity->type) {
        case PLAYER: addch('@'); break;
        case WALL: addch('H'); break;
        case UNINITIALIZED: break;
	default: fprintf(stderr, "Ent %p has bad type %d\n", entity, entity->type); break;
      }
    }
  }
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
