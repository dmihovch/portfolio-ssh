#ifndef RESUME_H
#define RESUME_H

#include "../logs/logs.h"
#include "utils.h"
#include <string.h>
#include <ncurses.h>
#include <panel.h>
#include <stdlib.h>

//probably should not use this
#define center_text(x, text_len) x - (text_len/2)

typedef struct {
	WINDOW* win;
	PANEL* pan;
	WINDOW* subwinl;
	WINDOW* subwinr;
}Resume;

void redrawResume(Resume* resume,int maxy, int maxx);
void drawEducation(WINDOW* win, int y, int x, int maxy, int maxx);
void drawExperience(WINDOW* win, int y, int x, int maxy, int maxx);
Resume* initResume(int maxy, int maxx);
void freeResume(Resume* resume);

#endif
