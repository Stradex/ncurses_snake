#include <snake.h>
#include <terminal.h>
#include <draw.h>

Snake* player;
Rectangle game_size = {{0, 0}, {15, 40}};
void displayGameBorders() {
	Position game_start_pos = game_size.start;
	Position game_end_pos = getRectangleEnd(game_size);
	for(int i=game_start_pos.x; i < game_end_pos.x; i++) {
		mvaddch(game_start_pos.y, i, '#' | COLOR_PAIR(WALL_COLOR));
		mvaddch(game_end_pos.y, i, '#' | COLOR_PAIR(WALL_COLOR));
	}
	for(int i=game_start_pos.y; i < game_end_pos.y; i++) {
		mvaddch(i, game_start_pos.x, '#' | COLOR_PAIR(WALL_COLOR));
		mvaddch(i, game_end_pos.x, '#' | COLOR_PAIR(WALL_COLOR));
	}

}
void displayGameOverScreen() {
	
	mvaddch(5, 5, 'G' | COLOR_PAIR(FRUIT_COLOR));
	mvaddch(5, 6, 'A' | COLOR_PAIR(FRUIT_COLOR));
	mvaddch(5, 7, 'M' | COLOR_PAIR(FRUIT_COLOR));
	mvaddch(5, 8, 'E' | COLOR_PAIR(FRUIT_COLOR));
	mvaddch(5, 9, ' ' | COLOR_PAIR(FRUIT_COLOR));
	mvaddch(7, 5, 'O' | COLOR_PAIR(FRUIT_COLOR));
	mvaddch(7, 6, 'V' | COLOR_PAIR(FRUIT_COLOR));
	mvaddch(7, 7, 'E' | COLOR_PAIR(FRUIT_COLOR));
	mvaddch(7, 8, 'R' | COLOR_PAIR(FRUIT_COLOR));
}

void drawPlayer() {
	for (int i=0; i < player->size; i++) {
		mvaddch(player->body[i].y, player->body[i].x, player->ch | COLOR_PAIR(SNAKE_COLOR));
	}
}

void draw_gui() 
{
	Point p = create_point(4, 5, '%');
	Box b = create_box(4, 5, 7, 7, '$');
	draw_box(b);	

}

int main(void)
{
	int ch;
	Terminal currentTerminal = getTerminal();
	Position start_pos = {2, 2};
	Position end_pos = {currentTerminal.columns-2, currentTerminal.lines-2};
	game_size = createRectangle(start_pos, end_pos);
	initscr();
	noecho();
	curs_set(0);
	init_colors();
	init_game();
	player = createPlayer(getCenter(game_size));
	drawPlayer();	
	bool game_over = false;
	while (ch = getch()) 
	{
		if (ch == 'q') {
			break;
		}
		if (!game_over) {	
			game_over = !handleInput(ch);
			tryToSpawnFruit();
		}
		clear();
		if (game_over) {
			displayGameOverScreen();
		} else {
			drawPlayer();
			if (fruit) {
				mvaddch(fruit->pos.y, fruit->pos.x, fruit->ch | COLOR_PAIR(FRUIT_COLOR));
			}
			displayGameBorders();

			draw_gui();
		}
	}

	endwin();



	return 0;
}
