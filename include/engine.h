#ifndef ENGINE_H
#define ENGINE_H

typedef struct
{
	int x;
	int y;
} Position;

typedef struct
{
	Position start;
	Position size;
} Rectangle;

/* MATH FUNCTIONS */
int e_clamp(int n, int min, int max);
int e_max(int a, int b);
int e_min (int a, int b);
int e_round(float f);
int e_floor(float f);
int e_ceil(float f);

Position getCenter(Rectangle game_box);
Position getRectangleEnd(Rectangle box);
Rectangle createRectangle(Position start, Position end);
Rectangle getCenterBox(Rectangle box, Rectangle game_box);

extern Rectangle game_size;

#endif
