#pragma once
#include <vector>
#include <graphics.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

typedef enum {
	CHESS_WHITE = -1,
	CHESS_BLACK = 1
}chess_kind_t;

struct ChessPos
{
	int row;
	int col;
};

class Chess
{
public:
	Chess(int gradeSize, int margin_x, int margin_y, float chessSize);
	void Init();
	bool ClickBoard(int x, int y, ChessPos *pos);
	void ChessDown(ChessPos* pos,chess_kind_t kind);
	void GetGradeSize();
	int getChessData(ChessPos* pos);
	int getChessData(int row, int col);
	bool CheckOver();
private:
	int gradeSize; // 棋盘尺寸
	float margin_x; // 49;
	int margin_y; // 49;
	float chessSize; //棋子大小（棋盘方格大小）
	IMAGE chessBlackImg;
	IMAGE chessWhiteImg;
	vector<vector<int>> chessMap;
	bool playerFlag; // 下棋方, true:黑棋方  false : AI 白棋方（AI方）
};

