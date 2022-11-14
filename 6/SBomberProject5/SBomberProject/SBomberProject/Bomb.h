#pragma once

#include "Visitour.h"
#include "DynamicObject.h"

class Visitor;

class Bomb : public DynamicObject
{
public:

	static const uint16_t BombCost = 10; // стоимость бомбы в очках

	void Draw() const override;
	//void accept(Visitor& v) { v.visit(this); };
private:

};

