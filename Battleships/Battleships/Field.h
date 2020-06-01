#pragma once
#include "Ship.h"

class Field
{
public:
	bool occupied;
	Ship *ship;
	bool hit;
	bool sunk;
	int geshooted = 1;
};

