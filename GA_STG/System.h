#pragma once
#include<math.h>
#include"DxLib.h"
#include"Define.h"
#include"Struct.h"
#include"Global.h"
#include"BulletPattern.h"

int ProcessLoop();
void StartInit();

void LoadGraph();
void DrawGraph();
void ShotMain();
void CharaMove();
int BulletCheckIn(int);
void BulletAppend(int);
bool CheckMain();
void LoadKey();