#pragma once
#include "GameObject.h"
#include <iostream>
class Game
{
public:
	Game(int width, int height);
	int getIndex(int x, int y);
	void printWorld();
	void addGameObject(GameObject *g);
	void moveGameObject(GameObject* g,int x,int y);
	GameObject *getGameObject(int x,int y);
private:
	GameObject** map;
	int width;
	int height;
	int field_count;
};

