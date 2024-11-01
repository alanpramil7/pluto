#include "app.h"
#include <ncurses.h>

// Inituialize main window
bool init_app(App *app) {
  app->win = initscr();
  app->title = " Pluto ";
  box(app->win, 0, 0); // Border box
  mvwprintw(app->win, 0, 2, " Pluto ");
  raw();
  noecho();
  curs_set(0); // No cursor

  if (!init_colors()) {
    return false;
  }

  // Refresh the window to display contents
  wrefresh(app->win);

  // Get app windwo widht and height
  int tracklist_height = getmaxy(app->win) - 2;
  int tracklist_width = getmaxx(app->win) / 5;
  // Initialize tracklist  window
  init_tracklist(&app->track_list, "/home/alan/Music/songs/", tracklist_height,
                 tracklist_width);

  app->is_running = true;
  return true;
}

// Initialize colors
bool init_colors() {
  if (!has_colors()) {
    fprintf(stderr, "No terminal color supported\n");
    false;
  }
  use_default_colors();
  init_pair(1, COLOR_BLACK, COLOR_BLUE);
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
  delwin(app->track_list.win);
  delwin(app->win);
  endwin();
}
