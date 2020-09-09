#include "player.h"

void move_player(Player *player, int input) {
    if (input == 'w') {
      player->y -= 1;
    } else if (input == 'a') {
      player->x -= 1;
    } else if (input == 's') {
      player->y += 1;
    } else if (input == 'd') {
      player->x += 1;
    }
}
