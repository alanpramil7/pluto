#ifndef APP_H
#define APP_H

#include <ncurses.h>

typedef struct {
  WINDOW *win;
  char *title;
  bool is_running;
} App;

// Main window functions
bool init_app(App *app);
bool init_colors();
void run(App *app);
void handle_input(App *app);
void app_cleanup(App *app);

#endif
