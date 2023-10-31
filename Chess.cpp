#include "Chess.h"

Chess::Chess(int gradeSize, int margin_x, int margin_y, float chessSize)
{
	this->gradeSize = gradeSize;
	this->margin_x = margin_x;
	this->margin_y = margin_y;
	this->chessSize = chessSize;
	playerFlag = CHESS_BLACK;
	for (int i = 0; i < gradeSize; i++) {
		vector<int> row;
		for (int j = 0; j < gradeSize; j++) {
			row.push_back(0);
		}
		chessMap.push_back(row);
	}
}

void Chess::Init()
{
	initgraph(897, 895);
	loadimage(0, _T("res/棋盘2.jpg"));

	mciSendString(_T("res/start.WAV"), 0, 0, 0); //需要修改字符集为多字节字符集

	loadimage(&chessBlackImg, _T("res/black.png"), chessSize, chessSize, true);
	loadimage(&chessWhiteImg, _T("res/white.png"), chessSize, chessSize, true);

	for (int i = 0; i < chessMap.size(); i++) {
		for (int j = 0; j < chessMap[i].size(); j++) {
			chessMap[i][j] = 0;
		}
	}

	playerFlag = true;
}

bool Chess::ClickBoard(int x, int y, ChessPos* pos)
{
	margin_x;
	margin_y;
	x;
	y;
	return true;
}

bool Chess::CheckOver()
{
	return false;
}
