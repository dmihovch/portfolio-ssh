#include "../include/animations.h"
#include <stdlib.h>
Lightning createLightning(int startx, int starty){
	return (Lightning){ .x = startx, .y = starty, .startx = startx, .starty = starty};
}


void updateLightning(WINDOW* win, Lightning* bolt, int maxy, int maxx)
{
	char chs[CHARS] = {'&', '$', '@', '|', '%'};
	char ch = chs[rand()%CHARS];
	if(rand()%2){
		bolt->x++;
	} else {
		bolt->x--;
	}
	bolt->y++;
	bolt->x = clamp(bolt->x, maxx);
	bolt->y = clamp(bolt->y, maxy);
	mvwaddch(win, bolt->y, bolt->x, ch);
}

void updateAllLightning(WINDOW* win, Lightning* bolts, int num_bolts, int maxy, int maxx){
	for(int i  = 0; i<num_bolts; i++){
		if(bolts[i].y < maxy){
		updateLightning(win,&bolts[i], maxy, maxx);
		}
	}
}

void resetLightning(WINDOW* win, Lightning* bolts, int num_bolts){
	wclear(win);
	for(int i = 0; i<num_bolts; i++){
		bolts[i].x = bolts[i].startx;
		bolts[i].y = bolts[i].starty;
	}
}


int randInRange(int low, int high){
    return ((rand() % (high - low + 1)) + low);
}
CycleLetter* createCycleString(const char* str, int len,  int x, int y, int cycles){
	CycleLetter* cstr = malloc(len*sizeof(CycleLetter));
	if(cstr == NULL) return NULL;
	int charcycles;
	for(int i = 0; i<len; i++){
		charcycles = cycles;	
		if(str[i] == ' ') charcycles = 0;
		cstr[i] = (CycleLetter){x+i,y,charcycles,str[i]};
	}
	return cstr;
}


void updateCycleString(CycleLetter* str, int len){
	char ch;
	for(int i = 0; i<len; i++){
		if(str[i].cycles <= 0){
			ch = str[i].ch;
		} 
		else{
			ch = (char) randInRange(LOWASCII,HIGHASCII);
			str[i].cycles--;
		} 
		mvaddch(str[i].y, str[i].x, ch);
	}
}

