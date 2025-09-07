#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <termios.h>

struct termios orig_termios;

void clear_screen() {
	printf("\033[2J");
	fflush(stdout);
}

void move_pencil(int x, int y) {
	printf("\033[%d;%dH", y, x);
}

void draw_text(int x, int y, char* entry) {
	move_pencil(x, y);
	printf("%s", entry);
	fflush(stdout);
}

void change_bgcolor(int color) {
	int c = 40 + color;
	printf("\033[%dm", c);
	fflush(stdout);
}

void change_color(int color) {
	int c = 30 + color;
	printf("\033[%dm", c);
	fflush(stdout);
}

void draw_hline(int x, int y, int w, int color) {
	move_pencil(x, y);
	change_color(color);
	for(int px = 0; px < w; px++) {
		printf("\u2588");
	}

	fflush(stdout);
}

void draw_rect(int x, int y, int w, int h, int color) {
	for(int py = 0; py < h; py++) {
		draw_hline(x, y+py, w, color);
	}
	change_color(7);
	change_bgcolor(0);
}

void disable_raw_mode() {
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enable_raw_mode() {
	tcgetattr(STDIN_FILENO, &orig_termios);
	atexit(disable_raw_mode);

	struct termios raw = orig_termios;
	raw.c_lflag &= ~(ECHO | ICANON);
	raw.c_cc[VMIN] = 0;
	raw.c_cc[VTIME] = 1;

	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void init_cpath() {
	clear_screen();
	change_color(7);
	move_pencil(0, 0);
	printf("\033[?25l");

	enable_raw_mode();
	atexit(disable_raw_mode);
	
	fflush(stdout);
}

void end_cpath() {
	disable_raw_mode();
	printf("\033[?25h");
	clear_screen();
}
