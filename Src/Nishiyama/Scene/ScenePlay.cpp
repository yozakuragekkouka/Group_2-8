#include <math.h>

#include "DxLib.h"
#include "../../Common.h"
#include "../Input/Input.h"
#include "../Score/ScoreManager/ScoreManager.h"
#include "ScenePlay.h"

//�v���C�V�[��������
void ScenePlay::Init()
{
	for (int i = 0; i < 4; i++)
	{
		scorefont[i].Init();
		scorefont[i].SetNumberFont(Number_16_32_orange);

		if (i % 2 == 1)
			scorefont[i].Set_posX(SCREEN_SIZE_X - 100);
		else
			scorefont[i].Set_posX(100);

		if(i >= 2)
			scorefont[i].Set_posY(SCREEN_SIZE_Y - 100);
		else
			scorefont[i].Set_posY(100);
	}
	for (int i = 0; i < 5; i++)
	{
		Player[i].RectInit(LoadGraph(PLAYER_IMAGE_PATH[i]), VGet(0.0f, 0.0f, 0.0f), 400, 400);

		if (i % 2 == 1)
			Player[i].Set_posX(SCREEN_SIZE_X - 50);
		else
			Player[i].Set_posX(50);

		if(i >= 2)
			Player[i].Set_posY(SCREEN_SIZE_Y - 50);
		else
			Player[i].Set_posY(50);

		if (i == 4)
		{
			Player[i].Set_posX(SCREEN_SIZE_X - 50);
			Player[i].Set_posY(50);
		}
	}
	Back.RectInit(LoadGraph(PLAY_BG_PATH), VGet(0.0f, 0.0f, 0.0f), 1280, 720);

	card.Init();

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_LOOP_PLAY;
}

//�v���C�V�[���ʏ폈��
void ScenePlay::Step()
{
	card.Step();

	if (card.AllCard_isDead())
	{
		SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_FIN_PLAY;
	}
}

//�v���C�V�[���`�揈��
void ScenePlay::Draw()
{
	Back.DrawRect();

	card.Draw();

	for (int i = 0; i < ScoreManager::GetAll_playerNum(); i++)
	{
		if (i == card.GetNow_Player())
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
		}
		else
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
		}

		if (ScoreManager::GetMulti_Flag() == false && i == 1)
			Player[4].DrawRect_Rota_Center(PLAYER_EXTEND_RATE);
		else
			Player[i].DrawRect_Rota_Center(PLAYER_EXTEND_RATE);

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	for (int i = 0; i < ScoreManager::GetAll_playerNum(); i++)
	{
		scorefont[i].Draw_int(ScoreManager::GetScore(i));
	}
}

//�v���C�V�[���㏈��
//���g���C���ǂ�����Ԃ�
void ScenePlay::Fin()
{
	Back.RectFin();

	card.Fin();

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_INIT_RESULT;
}