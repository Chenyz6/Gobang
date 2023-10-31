#pragma once
#include "AI.h"
#include "Chess.h"
#include "Man.h"

class ChessGame
{
public:
	void Play();
	ChessGame(AI* ai, Chess* chess, Man* man);
private:
	AI* ai;
	Chess* chess;
	Man* man;
};

