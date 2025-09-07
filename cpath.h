#ifndef CPATH
#define CPATH

void init_cpath();
void end_cpath();
void clear_screen();
void draw_text(int x, int y, char* entry);
void move_pencil(int x, int y);
void draw_rect(int x, int y, int w, int h, int color);
void change_color(int color);
void change_bgcolor(int color);

#endif
