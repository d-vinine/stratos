#ifndef UTILS_H
#define UTILS_H

#include <signal.h>
#include <stdio.h>

int signals_install(int signo, void (*handler)(int));

#endif // !UTILS_H
