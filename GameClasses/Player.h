#pragma once
#include "GameObject.h"
#define MAX_HEALTH 100
#define MAX_STAMINA 100

class Player : public GameObject
{
public:
	Player() = default;
	Player(int id, int x, int y)
		: GameObject(id,x,y)
	{
		health = MAX_HEALTH;
		stamina = MAX_STAMINA;
		orientation = Orientation::UP;
	}
	enum class Orientation
	{
		UP,
		DOWN,
		LEFT,
		RIGHT
	};
	void changeHealth(int points) {
		health += points;
	}
	int getHealth() {
		return health;
	}
	int getStamina() {
		return stamina;
	}
	void changeStamina(int points) {
		stamina += stamina;
	}
	Orientation getOrientation() {
		return orientation;
	}
	void setHealth(int health) {
		this->health = health;
	}
	void setStamina(int stamina) {
		this->stamina = stamina;
	}
	void getOrientation(Orientation orientation) {
		this->orientation = orientation;
	}
protected:
	int health;
	int stamina;
	Player::Orientation orientation;
};

