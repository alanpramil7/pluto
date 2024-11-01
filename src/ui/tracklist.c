#include "app.h"
#include <ncurses.h>

bool init_tracklist(TrackList *track_list, char *dir, int height, int width) {
  track_list->win = newwin(height, width, 1, 2);
  if (!track_list->win) {
    fprintf(stderr, "Failed to initialize Tracklist window\n");
    return false;
  }

  // Draw border and title
  box(track_list->win, 0, 0);
  mvwprintw(track_list->win, 0, 2, " Tracks ");

  // Refresh to draw the content
  wrefresh(track_list->win);
  return true;
}
