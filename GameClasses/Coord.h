#pragma once
class Coord {
public:
	int x;
	int y;
	Coord() = default;
	Coord(int x, int y) {
		this->x = x;
		this->y = y;
	}
	friend const Coord operator +(const Coord &left, const Coord& right) {
		return Coord(left.x + right.x, left.y + right.y);
	}
};