#include <ncurses.h>

#include "ui/app.h"

int main() {
  // Create main window
  App app;
  if (!init_app(&app)) {
    return 1;
  }

  run(&app);
  app_cleanup(&app);

  return 0;
}
