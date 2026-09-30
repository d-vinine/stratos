#include "state_table.h"
#include "utils.h"

#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

static volatile sig_atomic_t g_running = 1;

/// SIGTERM/SIGINT handler
/// Sets g_running flag to 0
static void parent_signal_handler(int signo) {
  (void)signo;
  g_running = 0;
}

int main(void) {
  if (signals_install(SIGINT, parent_signal_handler) < 0 ||
      signals_install(SIGTERM, parent_signal_handler) < 0) {
    perror("sigaction");
    return 1;
  }

  uint8_t inputs[WORDS] = {0};

  // spawn state actors
  pid_t pids[NO_OF_STATES];
  for (int i = 0; i < NO_OF_STATES; i++) {
    pid_t pid = fork();

    if (pid < 0) {
      perror("fork");
      // TODO: kill the procs gracefully and exit func
      return 1;
    }

    // inside child
    if (pid == 0) {
      // TODO: child proc init and run
    }

    // parent proc
    else {
      pids[i] = pid;
    }
  }

  // mocking reader
  int fd = open("/tmp/stratos", O_RDWR);
  if (fd < 0) {
    perror("open");
    return 1;
  }

  (void)pids;
  (void)inputs;
  char c;
  while (g_running) {
    int n = read(fd, &c, 1);
    if (n < 0) {
      if (errno == EINTR) {
       //TODO 
      }
      perror("read");
      return 1;
    } else if (n == 0) {
      continue;
    } else {
      int a = c - '0';

      if (a > 5) {
        printf("HI\n");
      }
    }
  }
}
