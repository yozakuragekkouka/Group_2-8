#include <math.h>

#include "DxLib.h"
#include "../../Common.h"
#include "../Input/Input.h"
#include "../Score/ScoreManager/ScoreManager.h"
#include "ScenePlay.h"

//�v���C�V�[��������
void ScenePlay::Init()
{
	Back.RectInit(LoadGraph(PLAY_BG_PATH), VGet(0.0f, 0.0f, 0.0f), 1280, 720);

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_LOOP_PLAY;
}

//�v���C�V�[���ʏ폈��
void ScenePlay::Step()
{
	switch (ScoreManager::GetMulti_Flag())
	{
	case true:
		break;
	case false:
		break;
	}

	if (Input::PressAnyKey())
	{
		SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_FIN_PLAY;
	}
}

//�v���C�V�[���`�揈��
void ScenePlay::Draw()
{
	Back.DrawRect();

	//�f�o�b�O
	DrawFormatString(100, 100, GetColor(255, 255, 255), "�v���C�V�[���ł�", true);

	switch (ScoreManager::GetMulti_Flag())
	{
	case true:
		break;
	case false:
		break;
	}
}

//�v���C�V�[���㏈��
//���g���C���ǂ�����Ԃ�
void ScenePlay::Fin()
{
	Back.RectFin();

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_INIT_RESULT;
}
