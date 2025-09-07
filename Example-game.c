#include <stdio.h>
#include <unistd.h>
#include "cpath.h"

int blocks_x[100];
int blocks_y[100];
int blocks_c[100];
int size = 0;

void push(int x, int y, int c) {
	int mov = 0;
	if(size < 100) {
		for(int count = 0; count < size; count++) {
			if(blocks_x[count] == x && blocks_y[count] == y) {
				mov = 1;
				blocks_c[count] = c;
			}
		}
		if(mov == 0) {
			blocks_x[size] = x;
			blocks_y[size] = y;
			blocks_c[size] = c;
			size++;
		}
		printf("\a");
	}
}

int main() {
	printf("\b");
	init_cpath();
	int y = 1;
	int x = 1;
	char c;
	int bcolor = 1;

	while(1) {
		clear_screen();
		draw_rect(0,1,81,31,2);
		for(int count = 0; count < size; count++) {
			draw_rect(blocks_x[count],blocks_y[count],1,1,blocks_c[count]);
		}
		draw_rect(x, y, 1, 1, 1);
		if(read(STDIN_FILENO, &c, 1) == 1) {
		
			if(c == 'q') break;

			if(c == '1') bcolor = 1;
			if(c == '2') bcolor = 2;
			if(c == '3') bcolor = 3;
			if(c == '4') bcolor = 4;
			if(c == '5') bcolor = 5;
			if(c == '6') bcolor = 6;

			if(c == 'a') {
				x--;
				printf("\a");
			}
			if(c == 'd') {
				x++;
				printf("\a");
			}
			if(c == 'w') {
				y--;
				printf("\a");
			}
			if(c == 's') {
				y++;
				printf("\a");
			}
			if(c == ' ') {
				push(x, y, bcolor);
			}
		}
	}

	end_cpath();
}
