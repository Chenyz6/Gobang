#pragma once
#include "Chess.h"

class Man
{
public:
	void Init(Chess *chess);
	void Go();
private:
	Chess* chess;
};

