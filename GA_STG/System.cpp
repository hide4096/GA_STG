#include"System.h"

//���t���[�����s������
int ProcessLoop() {
	if (ProcessMessage() != 0)return -1;//�v���Z�X�������G���[�Ȃ�-1��Ԃ�
	if (ClearDrawScreen() != 0)return -1;//��ʃN���A�������G���[�Ȃ�-1��Ԃ�
	return 0;
}

//������
void StartInit() {
	stagecount = 1;
	memset(&chara,0,sizeof(chara_state));
	chara.x = 320;
	chara.y = 400;
	memset(&shotdata, 0, sizeof(enemy_shot)*MAX_SHOT);
}
