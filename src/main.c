#include <stdlib.h>
#include "player.h"
#include "window.h"

int main() {
  Player *player = malloc(sizeof(Player));
  if (player == NULL) {
    printf("Malloc failed\n");
    return -1;
  }
  player->x = 10;
  player->y = 10;

  init_window();
  draw(player);

  end_window();

  // Free all memory
  free(player);

  return 0;
}
