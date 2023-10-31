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
	int row; // 第几行
	int col; // 第几列
	ChessPos() {
		row = 0;
		col = 0;
	}
	ChessPos(int r, int c) {
		row = r;
		col = c;
	}
};

class Chess
{
public:
	Chess(int gradeSize, int margin_x, int margin_y, float chessSize);
	void Init();
	bool ClickBoard(int x, int y, ChessPos *pos); // 鼠标按压点位置
	void ChessDown(ChessPos* pos,chess_kind_t kind);  // 落子
	void putimagePNG(int x, int y, IMAGE* picture); //x为载入图片的X坐标，y为Y坐标 棋子背后有黑色背景。这是因为easyx图形库默认不支持背景透明的png格式图片，把透明部分直接渲染为黑色了。解决方案，使用自定义的图形渲染接口
	int GetGradeSize();
	int getChessData(ChessPos* pos);
	int getChessData(int row, int col);
	bool CheckOver();	
	bool CheckWin(); // 检查是否胜利
private:
	void updateGameMap(ChessPos* pos); // 更新落点到chessMap容器中
private:
	int gradeSize; // 棋盘一行或一列多少个点
	float margin_x; // 棋盘中边缘方格到外面的距离
	int margin_y; // 棋盘中边缘方格到外面的距离
	float chessSize; //棋子大小（棋盘方格大小）正方形
	IMAGE chessBlackImg;
	IMAGE chessWhiteImg;
	vector<vector<int>> chessMap;
	ChessPos lastPos;
	bool playerFlag; // 下棋方, true:黑棋方  false : AI 白棋方（AI方）
};

