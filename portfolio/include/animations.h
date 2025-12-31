
#ifndef ANIMATION_H
#define ANIMATION_H


#include "utils.h"
#include <stdlib.h>
#include <unistd.h>


#define HIGHASCII 126
#define LOWASCII 33


typedef struct {
	int x,y,cycles;
	char ch;
}CycleLetter;

CycleLetter* createCycleString(const char* str, int len,  int x, int y, int cycles);
void updateCycleString(CycleLetter* str, int len);


#define CHARS 5
typedef struct{
	int x,y, startx, starty;
}Lightning;


Lightning createLightning(int startx, int starty);
void updateLightning(WINDOW* win, Lightning*, int, int);
void updateAllLightning(WINDOW* win, Lightning* bolts, int num_bolts, int maxy, int maxx);
void resetLightning(WINDOW* win, Lightning* bolts, int num_bolts);




#endif 
