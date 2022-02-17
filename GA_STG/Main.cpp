#define MAIN
#include"System.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	SetOutApplicationLogValidFlag(true);
	ChangeWindowMode(true); //�E�B���h�E���[�h
	SetMainWindowText("GA_STG"); //�^�C�g��
	if (DxLib_Init() == -1 || SetDrawScreen(DX_SCREEN_BACK) != 0) return -1;//�������Ɨ���ʉ�

	//���C�����[�v
	while (ProcessLoop() == 0 && mainstate!=101) {

		//�����̕���
		switch (mainstate) {

		//�N����
		case 0:
			LoadGraph();
			mainstate = 99;
			break;

		//�J�n�O
		case 99:
			LoadKey();
			StartInit();
			BulletAppend(4);
			mainstate = 100;
			break;

			//���s��
		case 100:
			DrawGraph();
			CharaMove();
			ShotMain();
			if (CheckMain() || stagecount >= FRAME * TIMEOUT) mainstate = 99;
			stagecount++;
			break;

			//�l�����������ꍇ
		default:
			break;
		}

		//����ʔ��f
		ScreenFlip();
	}

	FILE *fp;
	fopen_s(&fp,"../livetime.txt","w");
	fprintf(fp,"%d",stagecount);
	fclose(fp);

	DxLib_End();//�c�w���C�u�����I������
	return 0;
}