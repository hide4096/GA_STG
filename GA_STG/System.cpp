#include"System.h"

//毎フレーム実行するやつ
int ProcessLoop() {
	if (ProcessMessage() != 0)return -1;//プロセス処理がエラーなら-1を返す
	if (ClearDrawScreen() != 0)return -1;//画面クリア処理がエラーなら-1を返す
	return 0;
}

//初期化
void StartInit() {
	stagecount = 1;
	memset(&chara,0,sizeof(chara_state));
	chara.x = 320;
	chara.y = 400;
	memset(&shotdata, 0, sizeof(enemy_shot)*MAX_SHOT);
}
