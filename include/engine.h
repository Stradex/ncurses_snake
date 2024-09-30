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


Position getCenter(Rectangle game_box);
Position getRectangleEnd(Rectangle box);
Rectangle createRectangle(Position start, Position end);
Rectangle getCenterBox(Rectangle box, Rectangle game_box);

extern Rectangle game_size;

#endif
