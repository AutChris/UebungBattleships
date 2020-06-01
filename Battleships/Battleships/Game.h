#pragma once

#include "Field.h"
#include "Ship.h"
#include <iostream>
#include <stdio.h>

using namespace std;
class Game
{
public:
	Field board[10][10];
	Game();
	void printboard();
};

