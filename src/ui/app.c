#include <stdio.h>

#include "app.h"

// Inituialize main window
bool init_app(App *app) {
  app->win = initscr();
  app->title = " Pluto ";
  box(app->win, 0, 0); // Border box
  mvprintw(0, 2, "%s", app->title);
  raw();
  noecho();
  curs_set(0); // No cursor

  if (!init_colors()) {
    return false;
  }

  // Refresh the window to display contents
  wrefresh(app->win);
  app->is_running = true;
  return true;
}

// Initialize colors
bool init_colors() {
  if (!has_colors()) {
    fprintf(stderr, "No terminal color supported\n");
    false;
  }
  return true;
}

// Main loop
void run(App *app) {
  while (app->is_running) {
    handle_input(app);
  }
}

void handle_input(App *app) {
  char key = getch();
  switch (key) {
  case 'q':
    app->is_running = false;
    break;
  default:
    return;
  }
}

void app_cleanup(App *app) {
  delwin(app->win);
  endwin();
}
