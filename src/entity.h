#ifndef CURSED_MAZE_ENTITY
#define CURSED_MAZE_ENTITY

typedef enum entity_type_e {
  UNINITIALIZED,
  PLAYER,
  WALL
} EntityType;

typedef struct entity_s {
  int x;
  int y;
  EntityType type;
} Entity;

typedef struct world_s {
  int width;
  int height;
  Entity *entities;
} World;

World *new_world(int, int);
Entity *new_player(World *, int, int);
void move_entity(Entity *, World *, int, int);

#endif
