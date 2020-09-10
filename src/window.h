#ifndef CURSED_MAZE_WINDOW
#define CURSED_MAZE_WINDOW

void init_window();
void draw(World *);
int wait_for_input();
int get_rows();
int get_cols();
void end_window();

#endif
