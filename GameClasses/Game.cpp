#include "Game.h"

Game::Game(int width, int height)
{
	this->width = width;
	this->height = height;
	this->field_count = height * width;
	map = new GameObject * [field_count];
	for (int i = 0; i < field_count; i++)
	{
		map[i] = nullptr;
	}
}

int Game::getIndex(int x, int y)
{
	return (y * width) + x;
}

void Game::printWorld()
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int id = getIndex(x, y);
			if (map[id] == nullptr) {
				std::cout << "*";
			}
			else {
				std::cout << "+";
			}
			std::cout << " ";
		}
		std::cout<<std::endl;
	}
}

void Game::addGameObject(GameObject *g)
{
	int id = getIndex(g->get—oord().x, g->get—oord().y);
	if (g->get—oord().x >= width || g->get—oord().y >= height) {
		std::cout << "Can't add object with this coordinates X:"<< g->get—oord().x <<" Y:" << g->get—oord().y<<std::endl;
		return;
	}
	map[id] = g;
}

void Game::moveGameObject(GameObject* g,int x, int y)
{
	if (x >= width || y >= height || x < 0 || y < 0) {
		std::cout << "Can't move object with this coordinates X:" << x << " Y:" << y << std::endl;
		return;
	}
	int g_x = g->get—oord().x;
	int g_y = g->get—oord().y;
	int g_index = getIndex(g_x, g_y);
	int n_index = getIndex(x, y);
	if (map[g_index] == nullptr) {
		std::cout << "The fild X:" << g_x << " Y:" << g_y << " is empty.Cannot move objects" << std::endl;
		return;
	}
	map[g_index] = nullptr;
	g->setX(x);
	g->setY(y);
	map[n_index] = g;

}

GameObject* Game::getGameObject(int x, int y)
{
	if (x >= width || y >= height || x < 0 || y < 0) {
		std::cout << "Can't move object with this coordinates X:" << x << " Y:" << y << std::endl;
		return nullptr;
	}
	int id = getIndex(x, y);
	return map[id];
}
