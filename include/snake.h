#ifndef SNAKE_H
#define SNAKE_H
#include <engine.h>
#include <ncurses.h>
#include <stdlib.h>


typedef struct
{
	Position pos;
	char ch;
} Entity;

typedef struct
{
	int size;
	Position* body;
	char ch;
} Snake;

void init_game();
void tryToSpawnFruit();
Entity* createFruit(Position start_pos);
bool playerMove(Position new_pos);
Snake* createPlayer(Position start_pos);
bool handleInput(int input);

extern Entity* fruit;
extern Snake* player;
#endif
