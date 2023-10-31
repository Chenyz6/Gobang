#include "Main.h"


int main()
{
	Chess chess(13,44,43,67.4);
	AI ai;
	Man man;
	ChessGame game(&ai, &chess, &man);
	game.Play();
	return 0;
}