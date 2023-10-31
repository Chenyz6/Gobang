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
	int row; // �ڼ���
	int col; // �ڼ���
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
	bool ClickBoard(int x, int y, ChessPos *pos); // ��갴ѹ��λ��
	void ChessDown(ChessPos* pos,chess_kind_t kind);  // ����
	void putimagePNG(int x, int y, IMAGE* picture); //xΪ����ͼƬ��X���꣬yΪY���� ���ӱ����к�ɫ������������Ϊeasyxͼ�ο�Ĭ�ϲ�֧�ֱ���͸����png��ʽͼƬ����͸������ֱ����ȾΪ��ɫ�ˡ����������ʹ���Զ����ͼ����Ⱦ�ӿ�
	int GetGradeSize();
	int getChessData(ChessPos* pos);
	int getChessData(int row, int col);
	bool CheckOver();	
	bool CheckWin(); // ����Ƿ�ʤ��
private:
	void updateGameMap(ChessPos* pos); // ������㵽chessMap������
private:
	int gradeSize; // ����һ�л�һ�ж��ٸ���
	float margin_x; // �����б�Ե��������ľ���
	int margin_y; // �����б�Ե��������ľ���
	float chessSize; //���Ӵ�С�����̷����С��������
	IMAGE chessBlackImg;
	IMAGE chessWhiteImg;
	vector<vector<int>> chessMap;
	ChessPos lastPos;
	bool playerFlag; // ���巽, true:���巽  false : AI ���巽��AI����
};

