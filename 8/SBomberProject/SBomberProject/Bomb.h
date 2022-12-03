#pragma once

#include "DynamicObject.h"

class Bomb : public DynamicObject
{
public:

	static const uint16_t BombCost = 10; // стоимость бомбы в очках

	void Draw() const override;

	Bomb() {}

	Bomb(const Bomb& r)
	{
		x = r.x;
		y = r.y;
		width = r.width;
		speed = r.speed;
		xDirction = r.xDirction;
		yDirection = r.yDirection;
	}

	Bomb* clone() const
	{
		return new Bomb(*this);
	}

private:

};

