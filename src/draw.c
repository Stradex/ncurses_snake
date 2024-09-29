#include <draw.h>

void init_colors()
{
	if (has_colors())
	{
		start_color();
		init_pair(WALL_COLOR, COLOR_WHITE, COLOR_BLACK);
		init_pair(FRUIT_COLOR, COLOR_RED, COLOR_BLACK);
		init_pair(SNAKE_COLOR, COLOR_BLUE, COLOR_BLACK);
	}
}

void draw_point(Point p)
{
	if (!p.visible) {
		return;
	}
	mvaddch(p.pos.y, p.pos.x, p.ch | COLOR_PAIR(p.color));
}

void draw_box(Box b)
{
	if (!b.visible) {
		return;
	}
	Position box_start_pos = b.rect.start;
	Position box_end_pos = getRectangleEnd(b.rect);
	for (int i=box_start_pos.x; i <= box_end_pos.x; i++) {
		for (int j=box_start_pos.y; j <= box_end_pos.y; j++) {
			if (!b.filled && i != box_start_pos.x && i != box_end_pos.x && j != box_start_pos.y && j != box_end_pos.y) {
				continue;
			}
			mvaddch(j, i, b.ch | COLOR_PAIR(b.color));
		
		}
	}
}

Point create_point(int x, int y, int ch)
{
	Position pos = {x, y};
	Point p;
	p.pos = pos;
	p.ch = ch;
	p.visible = true;
	p.color = WALL_COLOR;
	return p;
}

Box create_box(int x, int y, int width, int height, int ch)
{
	Rectangle rect = {{x, y}, {width, height}};
	Box b;
	b.rect = rect;
	b.ch = ch;
	b.visible = true;
	b.color = WALL_COLOR;
	b.filled = false;
	return b;

}
