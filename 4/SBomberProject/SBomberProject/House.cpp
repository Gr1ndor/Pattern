
#include <iostream>

#include "House.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

void HouseBuilderA::createHouse() {
	for (size_t i = 0; i < 6; i++)
	{
		for (size_t j = 0; j < 13; j++)
		{
			(*h).look[i][j] = ' ';
		}
	}
	(*h).look[0][6] = '#';
	(*h).look[0][12] = '#';
	(*h).look[1][5] = '#';
	(*h).look[1][7] = '#';
	(*h).look[1][11] = '#';
	(*h).look[2][4] = '#';
	(*h).look[2][8] = '#';
	(*h).look[2][10] = '#';
	(*h).look[3][3] = '#';
	(*h).look[3][9] = '#';
	(*h).look[4][2] = '#';
	(*h).look[4][10] = '#';
	(*h).look[5][1] = '#';
	(*h).look[5][11] = '#';
}

void House::Draw() const {
	MyTools::SetColor(CC_Green);
	for (size_t i = 0; i < 6; i++)
	{
		GotoXY(x, y - 5 + i);
		for (size_t j = 0; j < 13; j++)
		{
			cout << look[i][j];
		}
	}
}


bool House::isInside(double x1, double x2) const
{
	const double XBeg = x + 2;
	const double XEnd = x + width - 1;

	if (x1 < XBeg && x2 > XEnd)
	{
		return true;
	}

	if (x1 > XBeg && x1 < XEnd)
	{
		return true;
	}

	if (x2 > XBeg && x2 < XEnd)
	{
		return true;
	}

	return false;
}

//void House::Draw() const
//{
//	MyTools::SetColor(CC_Yellow);
//	GotoXY(x, y - 5);
//	cout << "  ########  ";
//	GotoXY(x, y - 4);
//	cout << "##        ##";
//	GotoXY(x, y - 3);
//	cout << "############";
//	GotoXY(x, y - 2);
//	cout << "#          #";
//	GotoXY(x, y - 1);
//	cout << "#          #";
//	GotoXY(x, y);
//	cout << "############";
//}