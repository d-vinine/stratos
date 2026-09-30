#include "utils.h"

/// Function that assigns a handler to a signal with empty mask and no flags
/*
 * Returns 0 on success, -1 on failure
 */
int signals_install(int signo, void (*handler)(int)) {
  struct sigaction sa = {0};

  sa.sa_handler = handler;
  sa.sa_flags = 0;

  if (sigemptyset(&sa.sa_mask) < 0) {
    return -1;
  };

  if (sigaction(signo, &sa, NULL) < 0) {
    return -1;
  }
  return 0;
}
