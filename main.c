#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/XKBlib.h>

int main(void) {
  Display *display = XOpenDisplay(NULL);
  char *group = NULL;
  XkbStateRec state;

  if (NULL == display) {
    printf("%s\n", "Cannot open X server");
    return EXIT_FAILURE;
  }

  XkbGetState(display, XkbUseCoreKbd, &state);
  XkbDescPtr desc = XkbGetKeyboard(display, XkbAllComponentsMask, XkbUseCoreKbd);
  group = XGetAtomName(display, desc->names->groups[state.group]);

  printf("%s\n", (group != NULL ? group : "unknown"));

  XFree(group);
  XCloseDisplay(display);

  return EXIT_SUCCESS;
}
