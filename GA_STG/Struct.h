#pragma once

//自機キャラ情報
typedef struct {
	double x, y;
}chara_state;

//弾の情報
typedef struct {
	bool flg;
	int count, img, save;
	double x, y, speed, angle, range;
}bullet_state;

//弾幕情報
typedef struct {
	bool flg;
	int pattern, count;
	bullet_state bullet[MAX_BULLET];
}enemy_shot;