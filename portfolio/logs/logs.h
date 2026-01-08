#ifndef LOGS_H
#define LOGS_H
#include <stdio.h>
#include <stdarg.h>


void printl(const char* fmt, ...);

void debug_init();

void debug_close();


#endif
