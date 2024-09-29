#include <snake.h>
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

Entity* fruit;

void init_rand() {
	srand(time(NULL)); 
}
void init_game() {
	init_rand();
	fruit = NULL;
}

bool didPlayerAte(Position new_pos) {
	
	if (!fruit) {
		return false;
	}
	if (fruit->pos.x == new_pos.x && fruit->pos.y == new_pos.y) {
		fruit = NULL;
		return true;
	}
	return false;
	//return fruit->pos.x == new_pos.x && fruit->pos.y == new_pos.y;
}


bool isBodyOfSnake(Position pos)
{
	for (int i=0; i < player->size; i++)
	{
		if (player->body[i].x == pos.x && player->body[i].y == pos.y)
		{
			return true;
		}
	}
	return false;
}

bool isGameOver(Position new_pos) {
	if (new_pos.x <= game_size.start.x || new_pos.y <= game_size.start.y) {
		return true;
	}
	if (new_pos.x >= (game_size.start.x + game_size.size.x) || new_pos.y >= (game_size.start.y + game_size.size.y)) {
		return true;
	}
	return isBodyOfSnake(new_pos);
}

bool isPlayerGoingBackwards(Position new_pos) {
	if (player->size < 2) 
	{
		return false;
	}
	if (player->body[1].x == new_pos.x && player->body[1].y == new_pos.y) 
	{
		return true;
	}

	return false;
}



bool playerMove(Position delta_pos)
{
	if (delta_pos.x == 0 && delta_pos.y == 0) {
		return true;
	}
	Position new_pos = player->body[0];
	new_pos.x += delta_pos.x;
	new_pos.y += delta_pos.y;
	bool player_ate = didPlayerAte(new_pos);
	if (isPlayerGoingBackwards(new_pos)) {
		return true;
	}
	if (isGameOver(new_pos)) {
		return false;
	}
	

	if (player_ate) {
		Position* tmp = player->body;
		int new_size = player->size+1;
		player->body = realloc(player->body, new_size * sizeof(Position));
	   	if (!player->body) {
			player->body = tmp;
		} else {
			player->size = new_size;
			
		}
	}
	Position prev_pos = player->body[0];
	player->body[0] = new_pos;
	for (int i=1; i < player->size; i++)
	{
		Position tmp_pos = player->body[i];
		player->body[i] = prev_pos;
		prev_pos = tmp_pos;
	}

	return true;
}

Entity* createFruit(Position start_pos)
{
	Entity* newFruit = calloc(1, sizeof(Entity));
	newFruit->pos.y = start_pos.y;
	newFruit->pos.x = start_pos.x;
	newFruit->ch = '*';

	return newFruit;
}

Snake* createPlayer(Position start_pos)
{
	Snake* newPlayer = calloc(1, sizeof(Snake));
	newPlayer->size = 1;
	newPlayer->body = (Position*)calloc(newPlayer->size, sizeof(Position)); 
	newPlayer->body[0].y = start_pos.y;
	newPlayer->body[0].x = start_pos.x;
	newPlayer->ch = 'O';

	return newPlayer;
}

void tryToSpawnFruit() {
	if (fruit) { //it already exists!
		return;
	}
	Position spawn_pos = {0, 0};
	Position game_start_pos = game_size.start;
	Position game_end_pos = getRectangleEnd(game_size);
	do 
	{
		spawn_pos.x = 1+game_start_pos.x+rand() % game_end_pos.x;
		spawn_pos.y = 1+game_start_pos.y+rand() % game_end_pos.y;
		if (spawn_pos.y >= game_end_pos.y) {
			spawn_pos.y = game_end_pos.y-1;
		}
		if (spawn_pos.x >= game_end_pos.x) {
			spawn_pos.x = game_end_pos.x-1; 
		}
		if (spawn_pos.x <= game_start_pos.x) {
			spawn_pos.x = 1;
		}
		if (spawn_pos.y <= game_start_pos.y) {
			spawn_pos.y = 1;
		}
	} while(isBodyOfSnake(spawn_pos));
	fruit = createFruit(spawn_pos);

}

bool handleInput(int input)
{
	Position delta_pos = {0, 0};
	switch(input)
	{
		//move up
		case 'w':
			delta_pos.y--;
		break;
		//down
		case 's':
			delta_pos.y++;
		break;
		//left
		case 'a':
			delta_pos.x--;
		break;
		//right
		case 'd':
			delta_pos.x++;
		break;
		default:
		break;
	}
	return playerMove(delta_pos);
}
