#include "../include/resume.h"
#include <ncurses.h>


#define center_text(x, text_len)	\
	x - (text_len/2)			\

void drawEducation(WINDOW* win, int y, int x, int maxy, int maxx){

	int scaled_x;

	const char* edu_title = "Education:";
	mvwprintw(win,y,center_text(maxx/2, strlen(edu_title)),"%s",edu_title);

	const char* edu_school = "University of Delaware";
	mvwprintw(win,y+1, 1,"%s",edu_school);
	WINDOW* subwin = derwin(win,10,10,10,10);
	// touchwin(win);
	box(subwin,0,0);
	const char* edu_city = "Newark, DE";
	mvwprintw(win, y+1, maxx - (strlen(edu_city)+1),"%s",edu_city);



	const char* edu_major = "Bachelor of Science in Computer Science";
	scaled_x = maxx * .75;
	mvwprintw(win,y+2,center_text(scaled_x, strlen(edu_major)),"%s",edu_major);



}


void redrawResume(Page* resume){
	WINDOW* resume_win = resume->win;
	int maxy,maxx;
	getmaxyx(resume_win, maxy, maxx);


	const char* name = "Daniel Mihovch";
	mvwprintw(resume_win,0,center_text(maxx/2,strlen(name) ),"%s",name);

	const char* contact = "732-239-5689 | dmihovch@udel.edu | linkedin.com/in/danielmihovch | github.com/dmihovch";
	mvwprintw(resume_win,1,center_text(maxx/2, strlen(contact)),"%s",contact);
	
	drawEducation(resume_win, 2, 0, maxy, maxx);
}

