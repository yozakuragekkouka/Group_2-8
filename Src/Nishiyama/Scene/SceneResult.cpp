#include <math.h>
#include "DxLib.h"
#include "../../Common.h"
#include "../Input/Input.h"
#include "../Shapes/Shapes.h"
#include "Scene.h"
#include "SceneResult.h"
#include "../NumberFont/NumberFont.h"
#include "../Score/ScoreManager/ScoreManager.h"

//�N���A������
void SceneResult::Init()
{
	Result_BG_Hndl = LoadGraph(RESULT_BG_PATH);
	TextHndl = LoadGraph(TEXT_PATH);

	ClownHndl = LoadGraph("Data/Image/SceneResult/����.png");
	PlayerHndl[0] = LoadGraph("Data/Image/ScenePlay/�v���C���[1.png");
	PlayerHndl[1] = LoadGraph("Data/Image/ScenePlay/�v���C���[2.png");
	PlayerHndl[2] = LoadGraph("Data/Image/ScenePlay/�v���C���[3.png");
	PlayerHndl[3] = LoadGraph("Data/Image/ScenePlay/�v���C���[4.png");
	PlayerHndl[4] = LoadGraph("Data/Image/ScenePlay/CPU_400.png");


	BGM_Hndl = LoadSoundMem(RESULT_BMG_PATH);			//BGM�ǂݍ���
	TAPSound_Hndl = LoadSoundMem(RESULT_TAP_PATH);		//���艹�ǂݍ���

	TextPosX = 400;
	TextPosY = 470;
	MousePosX = MousePosY = 0;

	PlaySoundMem(BGM_Hndl, DX_PLAYTYPE_LOOP);

	//�e�X�g�p
	//ScoreManager::SetWinner(1);

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_LOOP_RESULT;
}

//�N���A�ʏ폈��
void SceneResult::Step()
{
	//�}�E�X�̍��W���擾����
	GetMousePoint(&MousePosX, &MousePosY);

	//�}�E�X���������Ƃ��Ƀ}�E�X���W���摜�͈͓̔��ɂ���΃V�[�����I���
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		if (MousePosX > TextPosX && MousePosX < TextPosX + TEXT_WIDHT
			&& MousePosY > TextPosY && MousePosY < TextPosY + TEXT_HEIGHT)
		{
			PlaySoundMem(TAPSound_Hndl, DX_PLAYTYPE_NORMAL);
			SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_FIN_RESULT;
		}
	}

	
}

//�N���A�`�揈��
void SceneResult::Draw()
{

	DrawGraph(0, 0, Result_BG_Hndl, true);				//�w�i�摜�`��
	DrawGraph(TextPosX, TextPosY, TextHndl, true);		//�e�L�X�g�摜�`��

	DrawRotaGraph(640, 320, 0.7f, 0.0f, PlayerHndl[ScoreManager::GetWinner()], true, false, false);	//���҃v���C���[�̕`��
	DrawRotaGraph(640, 120, 0.7f, 0.0f, ClownHndl, true, false, false);		//�����摜�\��

	/*DrawFormatString(0, 0, GetColor(255, 255, 255), "�}�E�X��X���W�F%d", MousePosX);
	DrawFormatString(0, 15, GetColor(255, 255, 255), "�}�E�X��Y���W�F%d", MousePosY);*/

}

//�N���A�㏈��
void SceneResult::Fin()
{
	DeleteGraph(Result_BG_Hndl);
	DeleteGraph(TextHndl);
	DeleteGraph(ClownHndl);

	for (int i = 0; i < 5; i++)
	{
		DeleteGraph(PlayerHndl[i]);
	}


	DeleteSoundMem(BGM_Hndl);
	DeleteSoundMem(TAPSound_Hndl);

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_INIT_TITLE;
}