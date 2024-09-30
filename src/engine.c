#include <engine.h>
#include <math_util.h>

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
