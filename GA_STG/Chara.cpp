#include"System.h"

void CharaDistance() {
	double x, y, distance;
	const double cnt_x = RNG_U + (RNG_D - RNG_U) / 2, cnt_y = RNG_L + (RNG_R - RNG_L) / 2;

	x = chara.x - cnt_x;
	y = chara.y - cnt_y;
	distance = sqrt(x * x + y * y);

	DrawFormatString(30, 0, GetColor(255, 255, 255), "%d", 250 - (int)distance);
	int mx, my;
	GetMousePoint(&mx, &my);
	chara.x = (double)mx, chara.y = (double)my;
}

void LoadKey() {
	int fp;
	fp = FileRead_open("../elite.txt");
	if (fp == NULL) return;
	for (int i = 0; i <= FRAME*TIMEOUT; i++) {
		key[i] = FileRead_getc(fp);
	}
	FileRead_close(fp);
}

void CharaMove() {
	double calc_x=0.0, calc_y=0.0;
	double speed=1.5;

	switch (key[stagecount]) {
		case'W':
			calc_y = 1.0;
			break;
		case'S':
			calc_y = -1.0;
			break;
		case'A':
			calc_x = -1.0;
			break;
		case'D':
			calc_x = 1.0;
			break;
		case'N':
			break;
	}

	bool xout = chara.x + calc_x < RNG_L || chara.x + calc_x > RNG_R;
	bool yout = chara.y + calc_y < RNG_U || chara.y + calc_y > RNG_D;
	if (!(xout || yout)) {
		chara.x += calc_x * speed;
		chara.y += calc_y * speed;
	}

	//CharaDistance();
}