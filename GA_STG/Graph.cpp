#include"System.h"

//エラー排除用
int DrawRotaGraphF(double xd, double yd, double ExRate,
	double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE) {
	return DrawRotaGraphF((float)xd, (float)yd, ExRate, Angle, GrHandle, TransFlag, TurnFlag);
}

//画像ハンドル用変数
int board_img;
int chara_img[3];
int bullet_img[5];

//画像読み込み
void LoadGraph() {
	board_img = LoadGraph("../image/board.png");
	LoadDivGraph("../image/Chara.png", 3, 1, 1, 15, 15, chara_img);
	LoadDivGraph("../image/Bullet.png", 5, 5, 1, 40, 40, bullet_img);
}

//弾描画
void DrawBullet() {
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	for (int i = 0; i < MAX_SHOT; i++) {
		if (shotdata[i].flg) {
			for (int j = 0; j < MAX_BULLET; j++) {
				if (shotdata[i].bullet[j].flg) {
					DrawRotaGraphF(shotdata[i].bullet[j].x, shotdata[i].bullet[j].y,
						0.4, shotdata[i].bullet[j].angle + PI / 2, bullet_img[shotdata[i].bullet[j].img], true);
				}
			}
		}
	}
	SetDrawMode(DX_DRAWMODE_NEAREST);
}

void DrawGraph() {
	DrawGraph(0, 0, board_img, true);
	DrawRotaGraphF(chara.x, chara.y, 1.0, 0, chara_img[0], true);
	DrawBullet();
	DrawFormatString(0,0,GetColor(255,255,255),"%d",stagecount);
}