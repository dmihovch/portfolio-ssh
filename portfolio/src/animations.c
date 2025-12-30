#include "../include/animations.h"
#include <stdlib.h>

Lightning createLightning(int x){
	return (Lightning){ .x = x, .y = 0};
}


void updateLightning(Lightning* bolt, int maxy, int maxx)
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
	mvaddch(bolt->y, bolt->x, ch);
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

