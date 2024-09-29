#include <engine.h>

int e_clamp(int n, int min, int max)
{
	return (n < min) ? min : ((n > max) ? max : n );
}

int e_max(int a, int b)
{
	return (a > b) ? a : b;
}

int e_min(int a, int b) 
{
	return (a < b) ? a : b;
}

int e_round (float f)
{
	return (int)((f > 0) ? f - 0.5 : f + 0.5 );
}

int e_floor (float f)
{
	return (int)f;
}

int e_ceil(float f) 
{
	return (int)(f + 1.0);
}

Position getCenter(Rectangle game_box) {
	Position box_start = game_box.start;
	Position box_end = getRectangleEnd(game_box);
	Position center = {
		e_round((float)(box_start.x + box_end.x)/2.0f),

		e_round((float)(box_start.y + box_end.y)/2.0f)
	};
	return center;
}

Rectangle getCenterBox(Rectangle box, Rectangle game_box)
{
	Position center_game_pos = getCenter(game_box);
	Position center_box_pos = getCenter(box);
	Rectangle center_box = {{box.start.x + center_game_pos.x - center_box_pos.x, box.start.y + center_game_pos.y - center_box_pos.y}, {box.size.x, box.size.y}};
	return center_box;
}

Position getRectangleEnd(Rectangle box)
{
	Position end = { box.start.x + box.size.x, box.start.y + box.size.y };
	return end;
}

Rectangle createRectangle(Position start, Position end)
{
	Rectangle box = {{start.x, start.y}, {end.x-start.x, end.y-start.y}};
	return box;
}
