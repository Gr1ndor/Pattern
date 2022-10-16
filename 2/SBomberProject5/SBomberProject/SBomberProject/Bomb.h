#pragma once

#include "DynamicObject.h"

class Bomb : public DynamicObject
{
public:

	static const uint16_t BombCost = 10; // стоимость бомбы в очках

	void Draw() const override;

private:

};

class BombDecorator : public DynamicObject
{
	int m;
	void Move() { b->Move(m); };
	Bomb* b;
public:
	BombDecorator(int _m) : m(_m) { Move(); }
	void Draw() { b->Draw(); };
};

