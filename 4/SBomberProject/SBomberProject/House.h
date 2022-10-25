#pragma once

#include <stdint.h>

#include "DestroyableGroundObject.h"

class House;

class HouseBuilder {
protected:
public:
	HouseBuilder() {}
	virtual ~HouseBuilder() {}
	virtual void createHouse() {}
};

class HouseBuilderA : public HouseBuilder
{
	House* h;
public:
	HouseBuilderA(House* _h) : h(_h) {}
	void createHouse();
};
class House : public DestroyableGroundObject
{
public:
	House() { HouseBuilderA builder(this); builder.createHouse(); }

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

	friend HouseBuilderA;
private:

	const uint16_t score = 40;
	char look[6][13];
};

