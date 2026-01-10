#include "../include/resume.h"

	//touchwin(resume.win);


Resume* initResume(int maxy, int maxx){
	Resume* resume = malloc(sizeof(Resume));
	if(resume == NULL) return NULL;
	resume->win = newwin(0,0,0,0);
	if(resume->win == NULL) goto fail;
	resume->pan = new_panel(resume->win);
	if(resume->pan == NULL) goto fail;
	resume->subwinl = derwin(resume->win,maxy/2,(maxx/2)-1,2,1);
	if(resume->subwinl == NULL) goto fail;
	resume->subwinr = derwin(resume->win,maxy/2,(maxx/2)-1,2,maxx/2);
	if(resume->subwinl == NULL) goto fail;
	
	box(resume->win,0,0);
	box(resume->subwinl,0,0);
	box(resume->subwinr,0,0);
	windowOptions(resume->win);
	return resume;

	fail:
		freeResume(resume);
		return NULL;
}

void freeResume(Resume* resume){
	if(resume){
		if(resume->subwinl) delwin(resume->subwinl);
		if(resume->subwinr) delwin(resume->subwinr);
		if(resume->pan) del_panel(resume->pan);
		if(resume->win) delwin(resume->win);
	}
	free(resume);
}

void redrawResume(Resume* resume, int maxy, int maxx)
{
	top_panel(resume->pan);

	const char* name = "Daniel Mihovch";
	mvwprintw(resume->win,0,center_text(maxx/2,strlen(name) ),"%s",name);
	//I think I should stop using center_text
	const char* contact = "732-239-5689 | dmihovch@udel.edu | linkedin.com/in/danielmihovch | github.com/dmihovch";
	mvwprintw(resume->win,1,center_text(maxx/2, strlen(contact)),"%s",contact);
	int y,x;
	getmaxyx(resume->subwinl,y,x);
	drawEducation(resume->subwinl,2, 0, y, x);

	getmaxyx(resume->subwinr,y,x);
	drawExperience(resume->subwinr, 2, 0, maxy, maxx);

	return;
}


void drawEducation(WINDOW* win, int y, int x, int maxy, int maxx){
	int scaled_x;

	const char* edu_title = "Education";
	mvwprintw(win,y,center_text(maxx/2, strlen(edu_title)),"%s",edu_title);
	const char* edu_school = "University of Delaware";
	mvwprintw(win,y+1, 1,"%s",edu_school);
	const char* edu_city = "Newark, DE";
	mvwprintw(win, y+1, maxx - (strlen(edu_city)+1),"%s",edu_city);



	const char* edu_major = "Bachelor of Science in Computer Science";
	scaled_x = maxx * .75;
	// mvwprintw(win,y+2,center_text(scaled_x, strlen(edu_major)),"%s",edu_major);
	
	mvwprintw(win,y+2,maxx-(strlen(edu_major)+1),"%s",edu_major);

	return;

}


void drawExperience(WINDOW* win, int y, int x, int maxy, int maxx){
	mvwprintw(win,maxy/2,maxx/2,"Experience");
	return;
}
