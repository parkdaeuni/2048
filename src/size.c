#include <curses.h>

int size_choice(){
	int size;
	int b;

	clear();
	mvprintw(LINES/2 - 1, COLS/2 -12, "%s", "Plesase Enter a size (4~8)>>  ");
	move(LINES-1, COLS-1);
	refresh();
	size = getchar();
	size -= 48;
	while(size < 4 || size > 8){
		size = getchar();
		size -= 48;
	}
	mvprintw(LINES/2,     COLS/2 -12, "You choose size %d (y/n)", size);
	move(LINES-1, COLS-1);
	refresh();
	
	b = getchar();
	if(b == 'y')
		return size;
	return 1;
}

