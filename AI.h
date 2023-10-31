#pragma once
#include "Chess.h"

class AI
{
public:
	void Init(Chess* chess);
	void Go();
private:
	Chess* chess;
	vector<vector<int>> scoreMap;
	void calculateScore();
	ChessPos think();
};

