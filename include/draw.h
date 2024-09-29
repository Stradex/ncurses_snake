#ifndef DRAW_H
#define DRAW_H

#include <engine.h>
#include <ncurses.h>
#include <stdlib.h>

#define FRUIT_COLOR	1
#define SNAKE_COLOR	2
#define WALL_COLOR	3

typedef struct 
{
	Position pos;
	int color;
	bool visible;
	int ch;
} Point;

typedef struct
{
	Rectangle rect;
	int color;
	bool visible;
	bool filled;
	int ch;

} Box;

//TO DO:
//1. Use percentage to create boxes/rectangles
//2. Align text: left, right, center, justified

/*Shorthand functions*/
Point create_point(int x, int y, int ch);
Box create_box(int x, int y, int width, int height, int ch);


void init_colors();
void draw_point(Point p);
void draw_box(Box b);

#endif
