#include "ChessGame.h"

void ChessGame::Play()
{
	chess->Init();
	while (1)
	{
		man->Go();
		if (chess->CheckOver()) {
			chess->Init();
			continue;
		}
		ai->Go();
		if (chess->CheckOver()) {
			chess->Init();
			continue;
		}
	}
}

ChessGame::ChessGame(AI* ai, Chess* chess, Man* man)
{
	this->ai = ai;
	this->chess = chess;
	this->man = man;

	//ai->Init(chess);
	man->Init(chess);
}