#include <stdlib.h>
#include <stdio.h>
#include <curses.h>

void ctos(char* reference, char input);

int main(){
	char test;
	test = 'c';

	initscr();
	cbreak();

	clear();

	printw("lmao");
	printw("haha");

	/*
	char* ref;
	ctos(ref, 'c');
	printw(ref);*/

	refresh();
	//getch();
	
	/*
	while (1) {
		char c = getch();

		if (c == 'c')
			break;
		else
			printw(c);
	}*/

	endwin();


	return 0;
}

void ctos(char* reference,char input){
	char output[2];
	output[0] = input;
	output[1] = '\0';
	reference = output;
}
