#include <stdlib.h>
#include "entity.h"
#include "window.h"

int main() {
  int running = 1;
  int c, rows, cols;
  World *world;
  Entity *player;

  init_window();
  cols = get_cols();
  rows = get_rows();
  world = new_world(cols, rows);
  player = new_player(world, 10, 10);
  while (running) {
    draw(world);

    c = wait_for_input();
    if (c == 'q') {
      running = 0;
    } else {
      if (c == 'w') {
        player->y -= 1;
      } else if (c == 'a') {
        player->x -= 1;
      } else if (c == 's') {
        player->y += 1;
      } else if (c == 'd') {
        player->x += 1;
      }
    }
  }
  end_window();

  // Free all memory
  free(world->entities);
  free(world);

  return 0;
}
