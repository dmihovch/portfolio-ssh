#include "logs.h"

static FILE* logfile = NULL;


void debug_logf(const char *fmt, ...){
	va_list args;
	va_start(args, fmt);
	vfprintf(logfile,fmt,args);
	va_end(args);
}

void debug_init(){
	logfile = fopen("logs/debug.log","w");
	setvbuf(logfile,NULL,_IOLBF, 0);
}

void debug_close(){
	fclose(logfile);
}

