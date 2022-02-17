#define MAIN
#include"System.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	SetOutApplicationLogValidFlag(true);
	ChangeWindowMode(true); //ウィンドウモード
	SetMainWindowText("GA_STG"); //タイトル
	if (DxLib_Init() == -1 || SetDrawScreen(DX_SCREEN_BACK) != 0) return -1;//初期化と裏画面化

	//メインループ
	while (ProcessLoop() == 0 && mainstate!=101) {

		//処理の分岐
		switch (mainstate) {

		//起動時
		case 0:
			LoadGraph();
			mainstate = 99;
			break;

		//開始前
		case 99:
			LoadKey();
			StartInit();
			BulletAppend(4);
			mainstate = 100;
			break;

			//実行中
		case 100:
			DrawGraph();
			CharaMove();
			ShotMain();
			if (CheckMain() || stagecount >= FRAME * TIMEOUT) mainstate = 99;
			stagecount++;
			break;

			//値がおかしい場合
		default:
			break;
		}

		//裏画面反映
		ScreenFlip();
	}

	FILE *fp;
	fopen_s(&fp,"../livetime.txt","w");
	fprintf(fp,"%d",stagecount);
	fclose(fp);

	DxLib_End();//ＤＸライブラリ終了処理
	return 0;
}