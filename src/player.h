#ifndef TUI_PLAYER
#define TUI_PLAYER

typedef struct player_s {
  int x;
  int y;
} Player;

void move_player(Player *, int);
#endif
