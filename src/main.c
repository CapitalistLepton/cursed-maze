#include <stdlib.h>
#include "player.h"
#include "window.h"

int main() {
  int running = 1;
  int c;

  Player *player = malloc(sizeof(Player));
  if (player == NULL) {
    printf("Malloc failed\n");
    return -1;
  }
  player->x = 10;
  player->y = 10;

  init_window();
  while (running) {
    draw(player);

    c = wait_for_input();
    if (c == 'q') {
      running = 0;
    } else if (c == 'd') {
      player->x += 1;
    }
  }
  end_window();

  // Free all memory
  free(player);

  return 0;
}
