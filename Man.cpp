#include "Man.h"

void Man::Init(Chess* chess)
{
	this->chess = chess;
}

void Man::Go()
{
	MOUSEMSG msg;
	ChessPos pos;
	while (1)
	{
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN && chess->ClickBoard(msg.x, msg.y, &pos)) {
			break;
		}
	}

	chess->ChessDown(&pos, CHESS_BLACK);
	if (chess->CheckWin()) {
		MessageBox(NULL, TEXT("Man Win!"), TEXT("Hint"), 0);
	}
}
