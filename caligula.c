#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BACKGROUND  "\x1B[30m"
#define ERROR 		"\x1B[31m"
#define SUCCESS 	"\x1B[32m"
#define RESET 		"\x1B[0m"

#define SUCCESS_PAIR 1
#define ERROR_PAIR 2
#define BACKGROUND_PAIR 3


/*
 * använd röd färg för fel,
 * grön färg för avklarade bokstäver,
 * ingen färg för normal text.
 */

int count_words(char words[1024]) {
	int amount = 1;

	for (int i=0; i < strlen(words); i++){
		if (words[i] == ' ') {
			amount++;
		}
	}

	return amount;
}


int main()
{
	char str[1024] = "ah hello there it is so nice to meet you";
	int words = count_words(str);

	initscr();
	noecho();

	if (has_colors() == FALSE){
		printf(ERROR "[Caligulaphy]\t\t" RESET);
		printf("Color might not be supported.\n");
		exit(1);
	}

	start_color();
	init_pair(SUCCESS_PAIR, COLOR_GREEN, COLOR_BLACK);
	init_pair(ERROR_PAIR, COLOR_RED, COLOR_BLACK);
	init_pair(BACKGROUND_PAIR, COLOR_BLACK, COLOR_BLACK);

	attron(COLOR_PAIR(BACKGROUND_PAIR));
	for(int i = 0; i < LINES; i++){
		mvhline(i,0,' ', COLS);
	}
	attroff(COLOR_PAIR(BACKGROUND_PAIR));



	mvprintw(10,10,str);

	char input;
	char current;
	int start_of_word = 0;
	int length_of_word = 0;
	int errors = 0;
	int total_errors = 0;
	clock_t start, end;


	start = clock();

	for (int i=0; i < strlen(str); i++){
		move(10,10+i);

		current = str[i];
		input = getch();
		
		if (current == ' ' || i == strlen(str)) {
			// ordet är slut
			if (errors > 0){
				errors = 0;
				total_errors++;
			}


			start_of_word = i+1;
			// sätt nytt start för ett nytt ord
			length_of_word = 0;
			// resetta längden av ordet
		}

		if(input == current){
			attron(COLOR_PAIR(SUCCESS_PAIR));
			mvaddch(10,10+i, current);
			attroff(COLOR_PAIR(SUCCESS_PAIR));
		} else {
			attron(COLOR_PAIR(ERROR_PAIR));
			mvaddch(10,10+i, current);
			attroff(COLOR_PAIR(ERROR_PAIR));
			errors++;
		}
		refresh();
	}
	end = clock();

	mvprintw(13,10, "You did well!\tpress any key to exit.\n%d errors %d", total_errors);
	getch();
	getch();
	endwin();

	return 0;
}
