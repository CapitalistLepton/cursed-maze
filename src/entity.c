#include <stdlib.h>
#include "entity.h"

World *new_world(int width, int height) {
  int i;
  World *world = malloc(sizeof(World));
  world->width = width;
  world->height = height;
  world->entities = malloc(width * height * sizeof(Entity));
  for (i = 0; i < width * height; i++) {
    Entity *e = (world->entities + i * sizeof(Entity));
    e->type = UNINITIALIZED;
    e->x = -1;
    e->y = -1;
  }
  return world;
}

Entity *new_player(World *world, int x, int y) {
  Entity *player;
  int i;

  for (i = 0; (world->entities + i * sizeof(Entity))->type != UNINITIALIZED; i++);
  player = world->entities + i * sizeof(Entity);
  player->x = x;
  player->y = y;
  player->type = PLAYER;

  return player;
}

void move_entity(Entity *entity, World *world, int dx, int dy) {
  if (entity->x + dx >= 0 && entity->x < world->width) {
    entity->x += dx;
  }
  if (entity->y + dy >= 0 && entity->y < world->height) {
    entity->y += dy;
  }
}
