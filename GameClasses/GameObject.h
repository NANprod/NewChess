#pragma once
#include "Coord.h"
class GameObject {
public:
	GameObject() = default;
	GameObject(int id,int x,int y) {
		coord = Coord(x,y);
		this->id = id;
	}
	Coord get—oord() {
		return coord;
	}
	void setX(int x) {
		coord.x = x;
	}
	void setY(int y) {
		coord.y = y;
	}
	void setCoord(Coord coordinates) {
		coord = coordinates;
	}
protected:
		int id;
		Coord coord;
};